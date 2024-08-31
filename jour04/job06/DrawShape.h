#ifndef DRAWSHAPE_H
#define DRAWSHAPE_H

#include "Shape.h"

template <typename T>
void drawShape(const T& shape) {
    shape.draw();
}

#endif
