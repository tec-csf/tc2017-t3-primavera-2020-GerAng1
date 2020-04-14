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

### PROGRAMA 1: FIGURAS CONVEXAS
Se desea implementar un algoritmo que permita resolver el problema de encontrar el cerco convexo de un conjunto de puntos en el plano XY.

Definiciones:

 - Cerco convexo: secuencia de puntos del conjunto que define una figura convexa que los encierra.

 - Figura convexa: es una figura cerrada, donde cada línea intersecta una figura convexa en no más de 2 puntos.

Para este problema se requiere una técnica de *Divide y Vencerás* porque para solucionar este problema hay que ir dividiendo el área de puntos a la mitad para obtener dos nuevas áreas y así sucesivamente hasta poder crear de manera directa una figura convexa. Luego se van fusionando las soluciones parciales para llegar a la solución final.

Se generó un archivo Point.hpp dentro de sources que contiene la clase que permite la creación de un "Punto" con coordenadas en los ejes "x" y "y".

#### Paso Inicial
##### En el archivo de ejemplo *ej1*, se generaron 10 puntos constantes y se insertaron a un vector. (Esto permite verificar el funcionamiento correcto del programa.)
##### En el archivo de ejemplo *ej2*, se generaron 10 puntos aleatoriamente y se insertaron a un vector. (Esto permite tener distintos escenarios de formaciones de figuras convexas.)
##### En el archivo de ejemplo *ej3*, se generaron 2 puntos y se insertaron a un vector. (Esto muestra el funcionamiento del programa cuando no hay puntos suficientes para formar un cerco [n < 3].)
Se ordena el vector con los puntos; se almacenan el primer y ultimo valor del vector en otro vector *convex_points*, éstos son los puntos más lejanos sobre el eje x; se genera un segmento con estos dos puntos (AB) y se divide en 2 el plano: aquellos puntos que se encuentran a la derecha del segmento AB orientado de A a B y aquellos puntos que se encuentran a la derecha del segmento AB orientado de B a A. *\*Se corre una función sobre cada "set" de puntos.*

#### Paso Intermedio (recursivo)
Recursivamente, lo primero que hará la función es buscar el punto más lejano del segmento AB y llamar al punto "C". El cual se inserta al vector *convex_points*. Con este punto se genera un triángulo el cual divide los puntos en 3 segmentos:
##### El primer segmento "S0", son los puntos que se encuentran dentro del triángulo ABC, y podemos concluir que estos puntos no formarán parte del cerco convexo.
##### El segundo segmento "S1", son los puntos que se encuentran a la derecha del segmento AC orientado de A a C.
##### El tercer segmento "S2", son los puntos que se encuentran a la derecha del segmento CB orientado de C a B.

##### Los puntos a la izquierda del segmento AB no se toman en cuenta ya que está considerado en la otra llamada al método mencionado en el paso 1 con un asterisco (\*).

Se llama esta misma función para los segmentos S1 y S2, hasta que ya no haya un punto para generar un triángulo.

Se repetirá este paso para la otra mitad del segmento AB.

#### Paso Final
Una vez terminadas las recursiones en ambas mitades del segmento AB, se imprimen los puntos almacenados en el vector *convex_points*.


### PROGRAMA 2: CICLO HAMILTONIANO
Dado un grafo g conexo y ponderado y dado uno de sus vértices v0, Se desea implementar un algoritmo que encuentre el ciclo Hamiltoniano de coste mínimo que comienza y termina en v0.

Para este problema se requiere una técnica de *Algoritmos Ávidos*.

#### Paso Inicial
##### En el archivo de ejemplo *ej1*, se genera un grafo *ponderado, no-dirigido* de tal manera que permita que el algoritmo encuentre el circuito Hamiltoniano de menor coste.
##### En el archivo de ejemplo *ej2*, se genera un grafo *ponderado, no-dirigido* de tal manera que el mismo algoritmo encuentra un circuito Hamiltoniano, pero no el de menor coste.
##### En el archivo de ejemplo *ej3*, se genera un grafo *ponderado, no-dirigido* de tal manera que el mismo algoritmo no logra encontrar un circuito Hamiltoniano, **aunque sí existe uno.**
Se itera sobre cada vértice del grafo, iniciando por el vértice llamado "V0", se inserta a un vector *yaesta*, y llama una función que busca el arista con menor coste.


#### Paso Intermedio (recursivo)
El *algoritmo ávido* toma como criterios que el siguiente vértice no este en el vector *yaesta*, y que de las posibles opciones, elija el vértice cuya arista tenga el menor valor (coste).
**En el caso del nodo V0, verifica que el tamaño del vector yaesta sea del mismo tamaño que el número de nodos en el grafo, en caso de que sea menor, no considerará V0 como un posible camino, en caso de que sea igual, sí lo considera para que se pueda cerrar el ciclo y terminar la función. (yaesta nunca será mayor al número de nodos en el grafo ya que el algoritmo termina antes de que esta condición se cumpla)**

#### Paso Final
Una vez terminado el *algoritmo ávido*, se imprimen los contenidos del vector *yaesta* utilizando el operador sobrecargado <<.


### 2.1 Pasos a seguir para utilizar la aplicación

##### Utilizando la línea de comando (Requiere conocimiento básicos de la línea de comando)
Lo primero que se debe realizar para utilizar las clases implementadas es clonar el repositorio de GitHub a un directorio local.
El usuario deberá estar en el directorio donde desea almacenar el repositorio y ahí deberá ejecutar el siguiente comando:

    $ git clone https://github.com/tec-csf/tc2017-t3-primavera-2020-GerAng1.git

Una vez clonado el repositorio, el usuario deberá cambiar a ese directorio ejecutando el siguiente comando:

    $ cd tc2017-t3-primavera-2020-GerAng1

Lo siguiente es compilar los códigos para generar un archivo ejecutable y finalmente, ejecutar este último:

    $ g++ examples/hamilton/ej1.cpp -std=c++17 -o h1
    $ g++ examples/hamilton/ej2.cpp -std=c++17 -o h2
    $ g++ examples/hamilton/ej3.cpp -std=c++17 -o h3
    $ g++ examples/convexo/ej1.cpp -std=c++17 -o c1
    $ g++ examples/convexo/ej2.cpp -std=c++17 -o c2
    $ g++ examples/convexo/ej3.cpp -std=c++17 -o c3

    $ ./h1
    $ ./h2
    $ ./h3
    $ ./c1
    $ ./c2
    $ ./c3

En el caso de los ejecutables h1, h2, y h3, éstos le pediran al usuario ingresar una respuesta para imprimir o no en pantalla el grafo con sus aristas, el usuario tiene la opción de insertar "Y" o "y" en caso de que si quiera verlo, o "N" o "n" en caso de que no. Por default, el sistema de Integración Continua [Travis CI] contesta con un "n".


## 3. Referencias

El pseudocódigo para el *algoritmo de divide y vencerás* se encontró en la liga: https://surface.syr.edu/eecs_techreports/65/
EL pseudocódigo para el *algoritmo ávido* se encontró en el libro **Técnicas de diseño de algoritmos**, capítulo 4, página 161. proporcionado en la clase.

La página http://www.cplusplus.com fue utilizada recurrentemente a lo largo de la tarea para encontrar las referencias de cómo utilizar diversos contenedores, así como sus funciones y bibliotecas correspondientes para el funcionamiento del programa.
