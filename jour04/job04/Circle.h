#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#include <iostream>
using namespace std;

class Circle : public Shape {
public:
    void draw() const override {
        cout << "Circle" << endl;
    }
};

#endif
