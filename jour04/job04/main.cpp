#include <iostream>
#include "Circle.h"
#include "Rectangle.h"
#include "DrawShape.h"

int main() {
    Circle circle;
    Rectangle rectangle;

    drawShape(circle);
    drawShape(rectangle);

    return 0;
}
