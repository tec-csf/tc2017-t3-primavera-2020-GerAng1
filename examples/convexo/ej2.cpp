#include <iostream> // cin y cout
#include <vector>
#include <cmath>    // abs()

#include "../../sources/Point.hpp"


int main(int argc, char const *argv[])
{
    std::cout << "\n\n\n\t\t-----INICIO PROGRAMA FIGURAS CONVEXAS-----\n\n" << std::endl;

    srand((double)time(0));
    int num_puntos = 10;
    std::vector<gal::Point> points;

    for (int i = 0; i < num_puntos; ++i)
    {
    		gal::Point p((rand() % 11) - 5, (rand() % 11) - 5); // (0 - 10) - 5 = (-5 al 5)
        points.push_back(p);
  	}

    std::cout << "En este plano hay " << num_puntos << " puntos." << std::endl;

    for (gal::Point point : points)
    {
        std::cout << point << std::endl;
    }

    // print_hull(points);


    std::cout << "\n\n\t\t----PROGRAMA FIGURAS CONVEXAS FINALIZADO----\n" << std::endl;
    return 0;
}
