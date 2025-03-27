#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <semaphore.h>
#include <fcntl.h>

#define NUM_USUARIOS 10
#define MAX_ARCHIVOS 10
#define COLA_TAMANO 4  // Tamaño de la cola limitada

int pipefd[2];
sem_t *cola_disponible;  // Espacios disponibles en la cola
sem_t *cola_llena;       // Archivos listos para imprimir

void usuario(int id) {
    close(pipefd[0]); // Cerrar lectura en el usuario

    char mensaje[20];
    sprintf(mensaje, "Archivo de U%d", id);

    // Esperar si la cola está llena (evita sobrecarga)
    sem_wait(cola_disponible);

    // Escribir en el pipe
    write(pipefd[1], mensaje, sizeof(mensaje));
    printf("Usuario %d agregó archivo a la cola de impresión\n", id);

    // Avisar que hay un archivo disponible en la cola
    sem_post(cola_llena);

    close(pipefd[1]); // Cerrar escritura
    exit(0);
}

void impresora(int id) {
    close(pipefd[1]); // Cerrar escritura en la impresora

    char mensaje[20];
    int archivos = 0;

    while (archivos < MAX_ARCHIVOS / 2) { // Cada impresora imprime la mitad
        sem_wait(cola_llena);  // Esperar a que haya archivos en la cola

        if (read(pipefd[0], mensaje, sizeof(mensaje)) > 0) {
            printf("Impresora %d: Imprimiendo %s\n", id, mensaje);
            archivos++;
            sleep(1); // Simular tiempo de impresión

            // Liberar un espacio en la cola después de imprimir
            sem_post(cola_disponible);
        }
    }

    close(pipefd[0]); // Cerrar lectura cuando termine
    exit(0);
}

int main() {
    if (pipe(pipefd) == -1) {
        perror("Error al crear el pipe");
        return 1;
    }

    // Inicializar semáforos
    cola_disponible = sem_open("/cola_disponible", O_CREAT, 0644, COLA_TAMANO); // Máximo 4 archivos en la cola
    cola_llena = sem_open("/cola_llena", O_CREAT, 0644, 0); // Inicialmente vacía

    // Crear las dos impresoras
    pid_t impresora1 = fork();
    if (impresora1 == 0) {
        impresora(1);
    }

    pid_t impresora2 = fork();
    if (impresora2 == 0) {
        impresora(2);
    }

    // Crear los 10 usuarios
    for (int i = 0; i < NUM_USUARIOS; i++) {
        pid_t p = fork();
        if (p == 0) {
            usuario(i + 1);
        }
    }

    // Cerrar escritura en el padre para evitar bloqueos
    close(pipefd[1]);

    // Esperar a que todos los procesos terminen
    for (int i = 0; i < NUM_USUARIOS + 2; i++) {
        wait(NULL);
    }

    // Eliminar semáforos
    sem_close(cola_disponible);
    sem_unlink("/cola_disponible");

    sem_close(cola_llena);
    sem_unlink("/cola_llena");

    return 0;
}
