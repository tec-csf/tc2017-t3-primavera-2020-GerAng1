#include <iostream> // cin y cout
#include <vector>
#include <cmath>    // abs()

#include "../../sources/Point.hpp"


int main(int argc, char const *argv[])
{
    std::cout << "\n\n\n\t\t-----INICIO PROGRAMA FIGURAS CONVEXAS-----\n\n" << std::endl;


    std::vector<gal::Point> points;
    gal::Point p;

    // Generando 10 puntos en plano xy
		p.set_xy(-2, 4);  points.push_back(p);
    p.set_xy(-1, -3); points.push_back(p);

    std::cout << "En este plano hay " << points.size() << " puntos." << std::endl;

    for (auto &point : points)
    {
        std::cout << point << std::endl;
    }

    // print_hull(points);


    std::cout << "\n\n\t\t----PROGRAMA FIGURAS CONVEXAS FINALIZADO----\n" << std::endl;
    return 0;
}
