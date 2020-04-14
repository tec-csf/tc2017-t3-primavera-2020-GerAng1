#include <algorithm> // std::find
#include <iostream> // cin y cout
#include <vector>

#include "../../sources/Graph.hpp"


/* Itera para regresar un apuntador al Vertex con menor coste.
 * Toma como criterios que el Vertex no esté en vector yaesta;
 * y que camino tiene el valor más bajo.*/
template <class V, class E>
Vertex<V, E> * busca(const int &num_nodes, Vertex<V, E> * &v_curso, std::vector< Vertex<V, E> * >& yaesta, std::vector<int>& costos, int j)
{
    if (j < num_nodes)
    {
        auto mejor_edge = v_curso->minEdge(yaesta, num_nodes);
        costos.push_back(mejor_edge->getInfo());
        auto mejor_vertice = mejor_edge->getTarget();
        yaesta.push_back(mejor_vertice);

        return mejor_vertice;
    }
}

int main(int argc, char const *argv[])
{
    std::cout << "\n\n\t\t-----INICIO PROGRAMA CICLO HAMILTONIANO-----\n\n" << std::endl;

    Graph<std::string, int> mapa("Ejemplo 2");

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

    std::vector< Vertex<std::string, int> * > nodes = mapa.getNodes();
    int num_nodes = nodes.size();

    std::cout << "Nodos en grafo: " << num_nodes << std::endl;

    std::vector< Vertex<std::string, int> * > yaesta;
    std::vector<int> costos;

    Vertex<std::string, int> * v_curso = nodes[0];
    yaesta.push_back(v_curso);

    std::cout << "Camino a tomar: " << std::endl;

    for (int j = 0; j <= nodes.size(); ++j)
    {
        std::cout << v_curso->getInfo() << std::endl;
        v_curso = busca(num_nodes, v_curso, yaesta, costos, j);
        if(v_curso == nodes[0] && yaesta.size() != num_nodes + 1)
        {
            std::cout << v_curso->getInfo() << std::endl;
            std::cout << "No se cumplió un circuito Hamiltoniano." << std::endl;
            break;
        }
    }

    std::cout << "Coste total: ";
    int total = 0;

    for (int i = 0; i < costos.size(); ++i)
    {
        if (i == 0) { std::cout << costos[i]; }
        else { std::cout << " + " << costos[i]; }
        total += costos[i];
    }

    std::cout << " = " << total << '\n' << std::endl;


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
