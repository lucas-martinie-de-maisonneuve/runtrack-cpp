#ifndef VECTOR2D_HPP
#define VECTOR2D_HPP

#include <cmath>
#include <iostream>

class Vector2d
{
private:
    double x, y;

public:
    Vector2d(double x = 0, double y = 0) : x(x), y(y) {}

    double getX() const { return x; }
    double getY() const { return y; }
    void setX(double newX) { x = newX; }
    void setY(double newY) { y = newY; }

    double distance(const Vector2d &other) const
    {
        return std::sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
    }

    void print() const
    {
        std::cout << "(" << x << ", " << y << ")";
    }
};

#endif
