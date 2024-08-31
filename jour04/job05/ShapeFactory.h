#ifndef SHAPEFACTORY_H
#define SHAPEFACTORY_H

#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include <string>
using namespace std;

class ShapeFactory {
public:
    static Shape* createShape(const string& shapeType) {
        if (shapeType == "circle") {
            return new Circle();
        } else if (shapeType == "rectangle") {
            return new Rectangle();
        } else {
            cout << "Error! Shape not defined.";
            return nullptr;
        }
    }
};

#endif
