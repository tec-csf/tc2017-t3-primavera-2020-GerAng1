#include <iostream> // cin y cout
#include <vector>
#include <set>
#include <cmath>    // abs()

#include "../../sources/Point.hpp"


int main(int argc, char const *argv[])
{
    std::cout << "\n\n\n\t\t-----INICIO PROGRAMA FIGURAS CONVEXAS-----\n\n" << std::endl;


    std::set<gal::Point> points;
    gal::Point p;

    p.set_xy(0, 3);   points.insert(p);
    p.set_xy(1, 1);   points.insert(p);
    p.set_xy(2, 2);   points.insert(p);
    p.set_xy(4, 4);   points.insert(p);
    p.set_xy(0, 0);   points.insert(p);
    p.set_xy(1, 2);   points.insert(p);
    p.set_xy(3, 1);   points.insert(p);
    p.set_xy(3, 3);   points.insert(p);

    std::cout << "En este plano hay " << points.size() << " puntos." << std::endl;

    for (auto &point : points)
    {
        std::cout << point << std::endl;
    }

    std::cout << "\n\n\t\t----PROGRAMA FIGURAS CONVEXAS FINALIZADO----\n" << std::endl;
    return 0;
}

// https://www.geeksforgeeks.org/quickhull-algorithm-convex-hull/
