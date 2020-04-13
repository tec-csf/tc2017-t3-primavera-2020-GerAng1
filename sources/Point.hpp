#ifndef Point_hpp
#define Point_hpp

#include <iostream>  // cin y cout
#include <set>

namespace gal
{
    class Point
    {
        double x, y;

        public:

            // CONSTRUCTORES
            Point();
            Point(double new_x, double new_y);


            // Destructor
            virtual ~Point();


            /* Asigna nuevos valores en el eje xy
             * en caso de ser necesario.
             * @const float &: valor en eje x.
             * @const float &: valor en eje y.
             */
            void set_xy(const double &, const double &);


            /* Regresa a posición del punto en el eje x */
            double get_x() const;


            /* Regresa a posición del punto en el eje x */
            double get_y() const;


            /* Sobrecarga el operador para imprimir coordenads xy */
            friend std::ostream &operator <<(std::ostream &, const Point &);


            // friend bool operator< (const Point &left, const Point &right);
    };


    Point::Point()
      : x(0.0), y(0.0) { }


    Point::Point(double new_x, double new_y)
      : x(new_x), y(new_y) { }


    Point::~Point() { }


    void Point::set_xy(const double &new_x, const double &new_y)
    {
        x = new_x;
        y = new_y;
    }


    double Point::get_x() const { return x; }


    double Point::get_y() const { return y; }


    std::ostream &operator <<(std::ostream &output, const Point &p)
    {
        output << " Abscisa  (x): " << p.x << "\n Ordenada (y): " << p.y << std::endl;

        return output;
    }


    // bool operator< (const Point &left, const Point &right)
    // {
    //     return (left.x < right.x) || (left.y != right.y);
    // }


}
#endif /* Point_hpp */
