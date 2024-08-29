#include "../includes/Vector2d.hpp"
#include <cmath>
using namespace std;

Vector2d::Vector2d(double x, double y) : x(x), y(y) {}

double Vector2d::getX() const {
    return x;
}

double Vector2d::getY() const {
    return y;
}

void Vector2d::setX(double newX) {
    x = newX;
}

void Vector2d::setY(double newY) {
    y = newY;
}

Vector2d Vector2d::operator+(const Vector2d& other) const {
    return Vector2d(x + other.x, y + other.y);
}

Vector2d Vector2d::operator-(const Vector2d& other) const {
    return Vector2d(x - other.x, y - other.y);
}

double Vector2d::distance(const Vector2d& other) const {
    double dx = x - other.x;
    double dy = y - other.y;
    return sqrt(dx * dx + dy * dy);
}

void Vector2d::print() const {
    cout << "(" << x << ", " << y << ")" << endl;
}
