#ifndef SHAPEFACTORY_H
#define SHAPEFACTORY_H

#include "Shape.h"
#include <string>
#include <stdexcept>
using namespace std;

template <typename T>
class ShapeFactory
{
public:
    static T *createShape()
    {
        static_assert(is_base_of<Shape, T>::value, "T must be derived from Shape");
        return new T();
    }
};

#endif
