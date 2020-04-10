#include <algorithm> // std::find
#include <iostream> // cin y cout
#include <vector>

#include "../../sources/Graph.hpp"


template <class V, class E>
Vertex<V, E> * busca(const Graph<V, E>& mapa, const int &num_nodes, Vertex<V, E> * &v_curso, std::vector< Vertex<V, E> * >& yaesta, int j)
{
    if (j < num_nodes)
    {
      auto mejor_vertice = v_curso->minEdge(yaesta, num_nodes)->getTarget();
      yaesta.push_back(mejor_vertice);
      return mejor_vertice;
    }
}

int main(int argc, char const *argv[])
{
    std::cout << "\n\n\n\t\t-----INICIO PROGRAMA CICLO HAMILTONIANO-----\n\n" << std::endl;

    Graph<std::string, int> mapa("Ejemplo 1");

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
    mapa.addEdge(V0, V1, 10);
    mapa.addEdge(V0, V2, 20);
    mapa.addEdge(V0, V5, 40);
    mapa.addEdge(V1, V3, 40);
    mapa.addEdge(V1, V5, 30);
    mapa.addEdge(V2, V4, 30);
    mapa.addEdge(V3, V4, 20);
    mapa.addEdge(V3, V5, 50);

    std::vector< Vertex<std::string, int> * > nodes = mapa.getNodes();
    int num_nodes = nodes.size();

    std::cout << "Nodos en grafo: " << num_nodes << std::endl;

    std::vector< Vertex<std::string, int> * > yaesta;

    Vertex<std::string, int> * v_curso = nodes[0];
    yaesta.push_back(v_curso);

    std::cout << "Camino a tomar: " << std::endl;

    for (int j = 0; j <= nodes.size(); ++j)
    {
      std::cout << v_curso->getInfo() << std::endl;
      v_curso = busca(mapa, num_nodes, v_curso, yaesta, j);

    }

    char ans;
    std::cout << "¿Ver grafo? [Y/N]: ";
    std::cin >> ans;

    if (ans == 'Y' || ans == 'y')
    {
      std::cout << mapa << std::endl;
    }

    std::cout << "\n\n\t\t----PROGRAMA CICLO HAMILTONIANO FINALIZADO----\n" << std::endl;

    return 0;
}




   //  PROCEDURE Busca(VAR g:GRAFO_PONDERADO; vertice:CARDINAL; VAR yaesta:PRESENCIA):CARDINAL;
   //      VAR mejor_vertice,i,min:CARDINAL;
   //      BEGIN
   //          mejor_vertice:=1; min:=MAX(CARDINAL); FOR i:=1 TO n DO
   //              IF (i<>vertice)AND(NOT(yaesta[i]))AND(g[vertice,i]<min) THEN min:=g[vertice,i]; mejor_vertice:=i;
   //              END
   //          END;
   //      RETURN mejor_vertice;
   // END Busca;

   //
   //  PROCEDURE Viajante1(VAR g:GRAFO_PONDERADO; VAR sol:GRAFO);
   //  // (* supone que el recorrido comienza en el vertice 1 *)
   //    VAR yaesta:PRESENCIA; i,verticeencurso,v_anterior:CARDINAL;
   //
   //    BEGIN
   //        FOR i:=1 TO n DO
   //            yaesta[i]:=FALSE END;
   //            verticeencurso:=1;
   //        FOR i:=1 TO n DO
   //            v_anterior:=verticeencurso;
   //            yaesta[v_anterior]:=TRUE;
   //            verticeencurso:=Busca(g,verticeencurso,yaesta);
   //            sol[v_anterior,verticeencurso]:=TRUE;
   //        END;
   // END Viajante1;
   //
   //
