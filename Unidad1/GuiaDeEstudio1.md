# Guia de Estudio - Unidad 1: Conceptos Basicos del Computo paralelo

## Ejercicio 1: ¿Qué condiciona la capacidad de computo de las computadoras secuenciales?

Las capacidad de las computadoras en serie, se ven limitadas a la hora de realizar problemas de gran escala y costo computacional, al tener que resolver los mismo, de ser posible, de forma lineal lo que conlleva un mayor tiempo. Es decir, los problemas se resuelven paso a paso, generando asi demoras en la ejecuccion de procesos que podrían ser desglozados y resueltos en simultaneo. Además, del mal provecho de los componentes de la computadora ya que, durante todo el proceso nos encontramos que hay elementos osciosos.

## Ejercicio 2: ¿Qué avances han posibilitado la resolucion de problemas de gran dimension en computadores?

En los años 60s, la inovacion en la creacion de nuevos procesadores con mayor poder de computo y la comercializacion de los mismo, generó un abaratamiento en los costos. Es decir, los precios comenzaron a bajar al mismo tiempo que las prestaciones subieron. Al pasar de los años, esta tendencía continuó dandole el nombre de Ley de Moore. Posibilitando así, la adquisición y uso de computadores para sistemas computacionales paralelos.

## Ejercicio 3: ¿Que son las aplicaciones de calculo intensivo? Explique y de ejemplos.

La aplicacion del calculo intensivo es la resolucion de problemas cientificos de gran envergadura donde convergen tanto la experimentacion, la teoria y la computacion. Las principales grupos de aplicacion del calculo intensivo son;

- Modelado predictivo y simulacion;
- Diseño industrial y robotica;
- Investigación básica, médica y militar;
- Exploración de recursos energéticos;
- Visualización;

## Ejercicio 4: ¿Que entiende por computo de altas prestaciones?

Es un conjunto de modelos, reglas y principios que permiten abordar y resolver problemas de gran costo computacional y de estructuras complejas sobre sistemas distribuidos.

## Ejercicio 5: ¿Que es el cómputo paralelo?

Es la poder de cómputo que posee un sistema al diseñar y utilizar el mismo con el objetivo de resolver problemas mediante la distrubucion y paralelizacion.

## Ejercicio 6: ¿Que condiciona la capacidad de cómputo de las computadoras paralelas?

Los computadoras paralelas se ven limitadas por diferentes razones;

- Periodos ociosos ( tiempo muerto sin aprovechar el uso de los procesadores);
- Calculos Redundantes ( recalculo de constantes);
- Comunicaciones entre procesos;
- Regiones del programa no paralelizables ( la inicializacion y finalizacion de la aplicacion )

## Ejercicio 7: ¿Qué dificultades se encuentran a la hora de utilizar sistemas paralelos?

A la hora de utilizar sistemas paralelos podemos encontrarnos con diversos problemas;

- La cantidad de software disponible es limitada;
- Las comunicaciones entre los procesos puede generar problemas al saturar los canales de comunicacion, perdidas de mensajes, nuevos elementos de hardware, entre otras;
- Puede generar problemas de disponibilidad;
- Puede ser complejo alcanzar una buena sicronizacion y comunicacion entre procesos ( complejo de programar)

## Ejercicio 8: Describa algunos ejemplos donde se aplique el paralelsimo a actividades no pertenecientes a al informatica.

Por ejemplo, dentro de la geología vemos la aplicacion del calculo intensivo para modelar la oceanografía terrestre. En el ambito de las ciencias economicas vemos su uso a la hora de realizar predicciones y analisis de riesgo en el mercado financiero. En la medicina se aplica en la investigacion generica con el modelado de secuencias de ADN y en la simulacion de farmacos. Además, de su uso en las predicciones del comportamiento del clima global como tormentas, ciclones o tornados.

## Ejercicio 9: ¿Qué es la ciencia computacional? ¿En que se diferencia de las Ciencias de la Computación?

La ciencia computacional es la relacion interdiciplinaria entre las ciencias de la computacion, las mamtematicas y la ciencia experimental para resolver problemas complejos en diversas áreas de la ciencia, ingeniría, medicina, economia, entre otras.

Mientras que la ciencias de la computación no presenta dicho origen interdiciplinario, con lleva un enfoque teórico en los fundamentos y teorías de la computacion, y su objetivo principal es el de desarrollar, entender y aplicar los fundamentos de la computación. Mencionar que las áreas de estudio de las Cs.Comp. son los algoritmos, estructuras de datos, sistemas complejos, arquitectura de computadoras, entre otras.

## Ejercicio 10: ¿Qué se plantea en la Ley de Moore?¿Se sigue cumpliendo?

La ley de moore plantea que aproximadamente cada 2 años la cantidad de transistores dentro de un microprocesador debería duplicarse. Sin embargo, en los últimos años se ha visto que tal relación lineal se ha roto siendo cada vez mas cercano a una relacion exponencial, sin incluir las apariciones de los primeros prototipos de computación cuantica que romperían con todo el paradigma y arquitectura de los microprocesadores actuales.
