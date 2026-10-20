/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:41:07 by armosnie          #+#    #+#             */
/*   Updated: 2025/12/12 14:36:57 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Point::Point() : _x(0), _y(0) {}

Point::~Point() {}

Point::Point(float const x, float const y) : _x(x), _y(y) {}

Point::Point(Point const &pointCopy) : _x(pointCopy._x), _y(pointCopy._y) {}

Point &Point::operator=(Point const &pointCopy) {
    (void)&pointCopy;
    return *this;
}

Fixed Point::getX() const {
    
    return _x;
}

Fixed Point::getY() const {
    
    return _y;
}

float calculate_area(Point const a, Point const b, Point const c) {

    Fixed result = a.getX() * (b.getY() - c.getY()) + b.getX() * (a.getY() - c.getY()) + c.getX() * (a.getY() - b.getY());
    if (result < 0)
        result = result * -1;
    return (result / 2).toFloat();
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    
    float triangle = calculate_area(a, b, c);
    float p1_triangle = calculate_area(b, c, point);
    float p2_triangle = calculate_area(c, point, a);
    float p3_triangle = calculate_area(point, a, b);

    float epsilone = 0.0001f;

    if (p1_triangle < epsilone || p2_triangle < epsilone || p3_triangle < epsilone)
        return false;
    float sum = p1_triangle + p2_triangle + p3_triangle;
    if (sum >= triangle - epsilone && sum <= triangle + epsilone)
        return true;
    return false;
}