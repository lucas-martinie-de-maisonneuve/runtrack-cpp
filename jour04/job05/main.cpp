#include <iostream>
#include "ShapeFactory.h"

int main()
{
    Shape *shape1 = ShapeFactory::createShape("circle");
    shape1->draw();
    delete shape1;

    Shape *shape2 = ShapeFactory::createShape("rectangle");
    shape2->draw();
    delete shape2;

    Shape *shape3 = ShapeFactory::createShape("triangle");
    shape3->draw();
    delete shape3;

    return 0;
}
