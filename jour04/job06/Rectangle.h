#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"
#include <iostream>
using namespace std;

class Rectangle : public Shape {
public:
    void draw() const override {
        cout << "Rectangle" << endl;
    }
};

#endif
