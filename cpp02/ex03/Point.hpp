#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {   

    private :
        Fixed const _x;
        Fixed const _y;

    public :

        Point();
        ~Point();
        Point(float const x, float const y);
        Point(Point const &pointCopy);
        Point &operator=(Point const &pointCopy);
        Fixed getX() const;
        Fixed getY() const;
    };

    float calculate_area(Point const a, Point const b, Point const c);
    bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif