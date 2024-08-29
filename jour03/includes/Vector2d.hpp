#ifndef VECTOR2D_HPP
#define VECTOR2D_HPP

#include <iostream>

class Vector2d {
private:
    double x, y;

public:
    Vector2d(double x = 0, double y = 0);

    double getX() const;
    double getY() const;

    void setX(double newX);
    void setY(double newY);

    Vector2d operator+(const Vector2d& other) const;

    Vector2d operator-(const Vector2d& other) const;

    double distance(const Vector2d& other) const;

    void print() const;
};

#endif
