//
//  main.cpp
//  Graph
//
//  Created by Vicente Cubells Nonell on 23/04/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#include <iostream>
#include "Graph.hpp"

int main(int argc, const char * argv[]) {

    Graph<std::string, int> mapa("Ejemplo 1");

    /* Crear vértices */
    Vertex<std::string, int> * V0 = new Vertex<std::string, int>("V0");
    Vertex<std::string, int> * V1 = new Vertex<std::string, int>("V1");
    Vertex<std::string, int> * V2 = new Vertex<std::string, int>("V2");
    Vertex<std::string, int> * V3 = new Vertex<std::string, int>("V3");
    Vertex<std::string, int> * V4 = new Vertex<std::string, int>("V4");

    /* Adicionar vértices al grafo */
    mapa.addVertex(V0);
    mapa.addVertex(V1);
    mapa.addVertex(V2);
    mapa.addVertex(V3);
    mapa.addVertex(V4);

    /* Adicionar aristas */
    mapa.addEdge(V0, V1, 30);
    mapa.addEdge(V0, V4, 100);
    mapa.addEdge(V1, V0, 50);
    mapa.addEdge(V1, V3, 75);
    mapa.addEdge(V2, V3, 20);
    mapa.addEdge(V3, V1, 60);
    mapa.addEdge(V4, V2, 15);

    /* Mostrar el grafo */
    std::cout << mapa << std::endl;

    std::cout << "Eliminando arista" << '\n';

    /* Eliminar una arista */;
    mapa.removeEdge(V1, V0, 30);

    /* Mostrar el grafo */
    std::cout << mapa << std::endl;

    return 0;
}
