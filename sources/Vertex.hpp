//
//  Vertex.hpp
//  Graph
//
//  Created by Vicente Cubells Nonell on 23/04/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#ifndef Graph_Vertex_hpp
#define Graph_Vertex_hpp

#include <algorithm>
#include <vector>

#include "Edge.hpp"

template <class V, class E>
class Vertex {
    V info;
    std::vector< Edge<V, E> * > edges;

public:
    Vertex() { }
    Vertex(V _info) : info(_info) { }

    ~Vertex();

    V getInfo() const;
    void setInfo(const V &);

    std::vector< Edge<V, E> * > getEdges();

    // Regresará el arista con menor coste
    Edge<V, E> * minEdge(std::vector< Vertex<std::string, int> * > &yaesta, int num_nodes);

    void addEdge(Edge<V, E> *);

    void removeEdge(Edge<V, E> *);

    bool operator != (Vertex<V, E> &) const;

    template <class Vn, class En>
    friend std::ostream & operator <<(std::ostream & , const Vertex<Vn, En> &);
};



template <class V, class E>
Vertex<V, E>::~Vertex()
{
    for (auto  e : edges)
    {
        delete e;
    }

    edges.clear();
}


template <class V, class E>
V Vertex<V, E>::getInfo() const
{
    return info;
}


template <class V, class E>
void Vertex<V, E>::setInfo(const V & value)
{
    info = value;
}


template <class V, class E>
std::vector< Edge<V, E> * > Vertex<V, E>::getEdges()
{
  return edges;
}


template <class V, class E>
Edge<V, E> * Vertex<V, E>::minEdge(std::vector< Vertex<std::string, int> * > &yaesta, int num_nodes)
{
    Edge<V, E>* min;
    int i;
    for (i = 0; i < edges.size(); ++i)
    {
        // std::cout << "Finding first edge" << std::endl;
        if (!(std::find(yaesta.begin(), yaesta.end(), edges[i]->getTarget()) != yaesta.end()))
        {
          min = edges[i];
          break;
        } else if ((edges[i]->getTarget() == yaesta[0]) && (yaesta.size() == num_nodes))
        {
          min = edges[i];
        }
    }

    // std::cout << "\n\n (PRUEBA: min[i] = " << min->getInfo() << ")\n" << std::endl;

    for ( ; i < edges.size(); ++i)
    {
        // std::cout << "Entering 2nd loop" << std::endl;
        // std::cout << "\n\n (PRUEBA: vertex.edges[i].getInfo() = " << edges[i]->getInfo() << ")\n" << std::endl;
        if ((!(std::find(yaesta.begin(), yaesta.end(), edges[i]->getTarget()) != yaesta.end())) && (edges[i]->getInfo() < min->getInfo()))
        {
            // std::cout << "NEXT" << std::endl;
            min = edges[i];
        } else if ((edges[i]->getTarget() == yaesta[0]) && (yaesta.size() == num_nodes))
        {
          // std::cout << "CERRANDO LOOP" << std::endl;
          min = edges[i];
        }
    }

    return min;
}


template <class V, class E>
void Vertex<V, E>::addEdge(Edge<V, E> * edge)
{
    edges.push_back(edge);
}


template <class V, class E>
void Vertex<V, E>::removeEdge(Edge<V, E> * edge)
{
    auto to_delete = find(edges.begin(), edges.end(), edge);
    edges.erase(to_delete);
}


template <class V, class E>
bool Vertex<V, E>::operator != (Vertex<V, E> & other) const
{
    return info != other.info;
}


template <class V, class E>
std::ostream & operator <<(std::ostream & os , const  Vertex<V, E>  & vertex)
{
    os << "Nodo: " << vertex.info << '\n' << std::endl;

    for (auto e : vertex.edges) {
        os << ' ' << vertex.info << *e << std::endl;
    }

    return os;
}


#endif
