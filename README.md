# Tarea *3*. *Técnicas de diseño de algoritmos (Individual)*

---

##### Integrante:
1. *Gerardo Anglada de Landa* - *A01021917* - *CSF*


---
## 1. Aspectos generales

Las orientaciones de la tarea se encuentran disponibles en la plataforma **Canvas**.

Este documento es una guía sobre qué información debe entregar como parte de la tarea, qué requerimientos técnicos debe cumplir y la estructura que debe seguir para organizar su entrega.


### 1.1 Requerimientos técnicos

A continuación se mencionan los requerimientos técnicos mínimos de la tarea, favor de tenerlos presente para que cumpla con todos.

* El código debe desarrollarse en C++, cumpliendo con el último estándar [C++17](https://isocpp.org/std/the-standard).
* Toda la programación debe realizarse utilizando Programación Genérica.
* Deben utilizarse las [C++ Core Guidelines](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md).
* Todo el código debe estar correctamente documentado, siguiendo los lineamientos que aparecen en [Documenting C++ Code](https://developer.lsst.io/cpp/api-docs.html).
* Todo el código de la tarea debe alojarse en este repositorio de GitHub.
* Debe configurar su repositorio para que utilice el sistema de Integración Continua [Travis CI](https://travis-ci.org/).

### 1.2 Estructura del repositorio

El proyecto debe seguir la siguiente estructura de carpetas:
```
- / 			        # Raíz del repositorio
    - README.md			# Archivo con la información general de la actividad (este archivo)
    - sources  			# Códigos fuente con la solución
    - examples			# Archivos de ejemplo que pueden utilizarse para verificar que la solución funciona.
```

## 2. Solución

PROGRAMA 1: FIGURAS CONVEXAS
Se desea implementar un algoritmo que permita resolver el problema de encontrar el cerco convexo de un conjunto de puntos en el plano XY.

Definiciones:

 - Cerco convexo: secuencia de puntos del conjunto que define una figura convexa que los encierra.

 - Figura convexa: es una figura cerrada, donde cada línea intersecta una figura convexa en no más de 2 puntos.

Para este problema se requiere una técnica de *Divide y Vencerás* porque para solucionar este problema hay que ir dividiendo el área de puntos a la mitad para obtener dos nuevas áreas y así sucesivamente hasta poder crear de manera directa una figura convexa. Luego se van fusionando las soluciones parciales para llegar a la solución final.
<!-- Funciona parecido a QuickSort. -->

PROGRAMA 2: CICLO HAMILTONIANO
Dado un grafo g conexo y ponderado y dado uno de sus vértices v0, Se desea implementar un algoritmo que enuentre el ciclo Hamiltoniano de coste mínimo que comienza y termina en v0.

Para este problema se requiere una técnica de *Algoritmos Ávidos* porque sea (C,v) el camino construido hasta el momento que comienza en v0 y termina en v. Inicialmente C es vacío y v = v0. Si C contiene todos los vértices de g, el algoritmo incluye el arco (v,v0) y termina. Si no, incluye el arco (v,w) de longitud mínima entre todos los arcos desde v a los vértices w que no están en el camino C.


### 2.1 Pasos a seguir para utilizar la aplicación

##### Utilizando la línea de comando (Requiere conocimiento básicos de la línea de comando)
Lo primero que se debe realizar para utilizar las clases implementadas es clonar el repositorio de GitHub a un directorio local.
El usuario deberá estar en el directorio donde desea almacenar el repositorio y ahí deberá ejecutar el siguiente comando:

    $ git clone https://github.com/tec-csf/tc2017-t3-primavera-2020-GerAng1.git

Una vez clonado el repositorio, el usuario deberá cambiar a ese directorio ejecutando el siguiente comando:

    $ cd tc2017-t3-primavera-2020-GerAng1

Lo siguiente es compilar el código para generar un archivo ejecutable y finalmente, ejecutar este último:

    $ g++ sources/main_convexo.cpp -std=c++17 -o convexo
    $ g++ sources/main_hamilton.cpp -std=c++17 -o hamilton

    $ ./convexo
    $ ./hamilton

<!-- Al estar ejecutando el programa, este le pedirá al usuario que ingrese el numero de elementos que desea insertar a los arboles, para lo cual debe insertar un número entero, como en el siguiente ejemplo:

    $ Ingrese la cantidad de elementos a ingresar a los arboles: 1000
---
Si es que se desea observar el funcionamiento de cada arbol por separado, se recomienda acceder a los codigos en la carpeta *examples* corriendo cada una de las clases por separado (en este caso ya contienen su propio *main*). Para ver el funcionamiento del Árbol AVL se correrían lo siguientes comandos:

    $ g++ example/avl_example.cpp

    $ ./a.out

Y para ver el funcionamiento del Árbol B se correrían los siguientes comandos:

    $ g++ example/BTree_example.cpp

    $ ./a.out -->

## 3. Referencias

*[Incluya aquí las referencias a sitios de interés y cualquier otra información que haya utilizado para realizar la actividad y que le puedan ser de utilidad a otras personas que quieran usarlo como referencia]*
