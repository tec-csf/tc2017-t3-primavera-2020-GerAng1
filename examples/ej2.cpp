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

    Graph<std::string, int>  mapa("Ejemplo 1");

    /* Crear vértices */
    Vertex<std::string, int> * V0 = new Vertex<std::string, int>("V0");
    Vertex<std::string, int> * V1 = new Vertex<std::string, int>("V1");
    Vertex<std::string, int> * V2 = new Vertex<std::string, int>("V2");
    Vertex<std::string, int> * V3 = new Vertex<std::string, int>("V3");
    Vertex<std::string, int> * V4 = new Vertex<std::string, int>("V4");
    Vertex<std::string, int> * V5 = new Vertex<std::string, int>("V5");

    /* Adicionar vértices al grafo */
    mapa.addVertex(V0);
    mapa.addVertex(V1);
    mapa.addVertex(V2);
    mapa.addVertex(V3);
    mapa.addVertex(V4);
    mapa.addVertex(V5);

    /* Adicionar aristas */
    mapa.addEdge(V0, V1, 20);
    mapa.addEdge(V0, V2, 10);
    mapa.addEdge(V0, V5, 40);
    mapa.addEdge(V1, V3, 40);
    mapa.addEdge(V1, V5, 30);
    mapa.addEdge(V2, V4, 30);
    mapa.addEdge(V3, V4, 20);
    mapa.addEdge(V3, V5, 50);


    /* Mostrar el grafo */
    std::cout << mapa << std::endl;

    return 0;
}
