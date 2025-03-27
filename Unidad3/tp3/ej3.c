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

int pipefd[2];
sem_t *sem_impresion;

void usuario(int id) {
    close(pipefd[0]); // Cerrar lectura en el usuario

    char mensaje[20];
    sprintf(mensaje, "Archivo de U%d", id);

    // Escribir en el pipe
    write(pipefd[1], mensaje, sizeof(mensaje));
    printf("Usuario %d agregó archivo a la cola de impresión\n", id);

    // Liberar el semáforo para avisar que hay archivos en la cola
    sem_post(sem_impresion);

    close(pipefd[1]); // Cerrar escritura
    exit(0);
}

void impresora() {
    close(pipefd[1]); // Cerrar escritura en la impresora

    char mensaje[20];
    int archivos = 0;

    while (archivos < MAX_ARCHIVOS) {
        // Esperar hasta que haya archivos en la cola
        sem_wait(sem_impresion);

        if (read(pipefd[0], mensaje, sizeof(mensaje)) > 0) {
            printf("Impresora: Imprimiendo %s\n", mensaje);
            archivos++;
            sleep(1); // Simular tiempo de impresión
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

    // Inicializar semáforo en 0 (esperará a que haya archivos en la cola)
    sem_impresion = sem_open("/cola_impresion", O_CREAT, 0644, 0);

    pid_t pid = fork();
    if (pid == 0) {
        impresora();
    } else {
        for (int i = 0; i < NUM_USUARIOS; i++) {
            pid_t p = fork();
            if (p == 0) {
                usuario(i + 1);
            }
        }
        
        // Cerrar escritura en el padre para evitar bloqueos en la lectura de la impresora
        close(pipefd[1]);
    }

    // Esperar a que todos los procesos terminen
    for (int i = 0; i < NUM_USUARIOS + 1; i++) {
        wait(NULL);
    }

    // Eliminar semáforo
    sem_close(sem_impresion);
    sem_unlink("/cola_impresion");

    return 0;
}
