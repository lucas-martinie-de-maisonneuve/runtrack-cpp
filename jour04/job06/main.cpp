#include <iostream>
#include "ShapeFactory.h"
#include "Circle.h"
#include "Rectangle.h"

int main()
{
    Shape *shape1 = ShapeFactory<Circle>::createShape();
    shape1->draw();
    delete shape1;

    Shape *shape2 = ShapeFactory<Rectangle>::createShape();
    shape2->draw();
    delete shape2;

    return 0;
}
