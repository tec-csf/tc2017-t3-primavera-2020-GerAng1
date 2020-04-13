#include <set>
#include <cmath>    // abs()
#include <vector>
#include <iostream> // cin y cout

#include "../../sources/Point.hpp"


// Auxiliar para ordenar vector de puntos ascendentemente por valor en eje x.
bool asc_x(gal::Point &i, gal::Point &j)
{
    return (i.get_x() < j.get_x());
}


// Auxiliar en encontrar el punto mas lejano dado un segmento.
double distance_p(const gal::Point &a, const gal::Point &b, const gal::Point &p)
{
    return std::abs(((p.get_y() - a.get_y()) * (b.get_x() - a.get_x())) -
                    ((b.get_y() - a.get_y()) * (p.get_x() - a.get_x())));
}


// Auxiliar en encontrar de qué lado se encuentra punto dado un segmento.
int find_side(const gal::Point &a, const gal::Point &b, const gal::Point &p)
{
    int val = (((p.get_y() - a.get_y()) * (b.get_x() - a.get_x())) -
               ((b.get_y() - a.get_y()) * (p.get_x() - a.get_x())));

    if (val > 0)      { return 1; }
    else if (val < 0) { return -1; }
    else              { return 0; }
}


// Encuentra puntos en cerco convexo de los puntos
// a la derecha del segmento AB orientado de A a B.
void find_hull(const std::vector<gal::Point> &points, const gal::Point &a,
               const gal::Point &b, std::set<gal::Point, classcomp> &convex_points, const int &side)
{
    int ind = -1;
    int max_dist = 0;

    // Se busca el punto más lejano del segmento AB, así como su lado.
    for (int i = 0; i < points.size(); ++i)
    {
        int temp = distance_p(a, b, points[i]);
        if (find_side(a, b, points[i]) == side && temp > max_dist)
        {
            ind = i;
            max_dist = temp;
        }
    }

    // Una vez que ya no haya puntos de ese lado,
    // se agregan los extremos al cerco.
    if (ind == -1)
    {
        convex_points.insert(a);
        convex_points.insert(b);
        return;
    }

    find_hull(points, points[ind], a, convex_points, -(find_side(points[ind], a, b)));
    find_hull(points, points[ind], b, convex_points, -(find_side(points[ind], b, a)));
}


void print_hull(std::vector<gal::Point> &points)
{
    if (points.size() < 3)
    {
        std::cout << "No se puede hacer un cervo convexo con menos de 3 puntos en el plano." << std::endl;
        return;
    }

    std::set<gal::Point, classcomp> convex_points;

    std::sort(points.begin(), points.end(), asc_x);

    // Los extremos del vector representan
    // los puntos del plano a los extremos en el eje x.
    find_hull(points, points.front(), points.back(), convex_points, 1);
    find_hull(points, points.front(), points.back(), convex_points, -1);

    std::cout << "Los puntos que conforman el cerco convexo son:" << std::endl;

    while (!convex_points.empty())
    {
        std::cout << convex_points[0] << std::endl;
        convex_points.erase(convex_points.begin());
    }
}


// Este se supone ser el cerco
// p(-2, 4);
// p(-1, -3);
// p(6, 6);
// p(8, -3);
// p(9, 5);
int main(int argc, char const *argv[])
{
    std::cout << "\n\n\n\t\t-----INICIO PROGRAMA FIGURAS CONVEXAS-----\n\n" << std::endl;


    std::vector<gal::Point> points;
    gal::Point p;

    // Generando 10 puntos en plano xy
		p.set_xy(-2, 4);  points.push_back(p);
    p.set_xy(-1, -3); points.push_back(p);
    p.set_xy(2, 1);   points.push_back(p);
    p.set_xy(2, 4);   points.push_back(p);
    p.set_xy(4, -2);  points.push_back(p);
    p.set_xy(5, 2);   points.push_back(p);
    p.set_xy(6, 6);   points.push_back(p);
    p.set_xy(8, 2);   points.push_back(p);
    p.set_xy(8, -3);  points.push_back(p);
    p.set_xy(9, 5);   points.push_back(p);

    std::cout << "En este plano hay " << points.size() << " puntos." << std::endl;

    for (auto &point : points)
    {
        std::cout << point << std::endl;
    }

    print_hull(points);


    std::cout << "\n\n\t\t----PROGRAMA FIGURAS CONVEXAS FINALIZADO----\n" << std::endl;
    return 0;
}

// https://www.geeksforgeeks.org/quickhull-algorithm-convex-hull/
