//
//  Graph.hpp
//  Graph
//
//  Created by Vicente Cubells Nonell on 27/04/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#ifndef Graph_Graph_hpp
#define Graph_Graph_hpp

#include <algorithm>
#include <string>
#include <map>

#include "Vertex.hpp"

template <class V, class E>
class Graph {

    std::string name;
    std::vector< Vertex<V, E> * > nodes;

public:
    Graph() { }
    Graph(std::string _name) : name(_name) { }
    ~Graph();

    // AGREGADO: Regresa nodos que tiene ese Vertex
    std::vector< Vertex<V, E> * > getNodes();

    void addVertex(Vertex<V, E> * vertex);
    // MODIFICADO: Genera una arista en ambos sentidos
    void addEdge(Vertex<V, E> * source, Vertex<V, E> * target, const E & info);

    // MODIFICADO: Quita las dos aristas generadas
    void removeEdge(Vertex<V, E> * source, Vertex<V, E> * target, const E & info);
    bool isComplete();

    // MODIFICADO: CAMBIÉ LA SALIDA A LA TERMINAL
    template <class Vn, class En>
    friend std::ostream & operator<<(std::ostream & os, const Graph<Vn, En> & graph);
};


template <class V, class E>
Graph<V, E>::~Graph()
{
    for (auto v : nodes) {
        delete v;
    }

    nodes.clear();
}


template <class V, class E>
std::vector< Vertex<V, E> *> Graph<V, E>::getNodes()
{
  return nodes;
}


template <class V, class E>
void Graph<V, E>::addVertex(Vertex<V, E> * vertex)
{
    nodes.push_back(vertex);
}


template <class V, class E>
void Graph<V, E>::addEdge(Vertex<V, E> * source, Vertex<V, E> * target, const E & info)
{
    auto node_s = find(nodes.begin(), nodes.end(), source);
    auto node_t = find(nodes.begin(), nodes.end(), target);

    /* Crear una arista en cada dirección y adicionarla al vertex */
    Edge<V, E> * edge_t = new Edge<V, E>(info, target);
    Edge<V, E> * edge_s = new Edge<V, E>(info, source);

    (*node_s)->addEdge(edge_t);
    (*node_t)->addEdge(edge_s);
}


template <class V, class E>
void Graph<V, E>::removeEdge(Vertex<V, E> * source, Vertex<V, E> * target, const E & info)
{
    /* Buscar vertex origen */
    auto node_s = find(nodes.begin(), nodes.end(), source);

    Vertex<V, E> * vertex_s = (*node_s);

    std::vector< Edge<V, E> * > * edges_s = vertex_s->getEdges();

    Edge<V, E> * edge_s = nullptr;

    // Quitando edge de source
    for (auto e : *edges_s) {
        if (e->getInfo() == info && e->getTarget() == target) {
            edge_s = e;
            break;
        }
    }

    if (edge_s) {
        vertex_s->removeEdge(edge_s);
    }


    // Quitando edge de target
    auto node_t = find(nodes.begin(), nodes.end(), target);

    Vertex<V, E> * vertex_t = (*node_t);

    std::vector< Edge<V, E> * > * edges_t = vertex_t->getEdges();

    Edge<V, E> * edge_t = nullptr;

    for (auto f : *edges_t) {
        if (f->getInfo() == info && f->getTarget() == source) {
            edge_t = f;
            break;
        }
    }

    if (edge_t) {
        vertex_t->removeEdge(edge_t);
    }

}


template <class V, class E>
bool Graph<V, E>::isComplete()
{
    bool complete = true;

    std::map<V, int> outputIncidents;

    for (auto vertex : nodes) {
        if (vertex->getEdges()->size() < (nodes.size() - 1) ) {
            return false;
        }

        std::vector< Edge<V, E> * > * edges = vertex->getEdges();

        for (auto e : *edges)
        {
            outputIncidents[e->getTarget()->getInfo()]++;
        }

        if (outputIncidents.size() < (nodes.size() - 1) ) {
            return false;
        }

        outputIncidents.clear();

    }

    return complete;
}


template <class V, class E>
std::ostream & operator<<(std::ostream & os, const Graph<V, E> & graph)
{
    os << "--- Grafo: " << graph.name << " ---" << std::endl;

    for (auto v : graph.nodes) {
        os << *v;
    }

    return os;
}

#endif
