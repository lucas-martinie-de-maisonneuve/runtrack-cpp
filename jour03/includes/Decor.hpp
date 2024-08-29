#ifndef DECOR_HPP
#define DECOR_HPP
using namespace std;

#include "GameObject.hpp"

class Decor : public GameObject {
public:
    Decor(double x = 0, double y = 0) : GameObject(x, y) {}

    void draw() const override {
        cout << "Drawing Decor at (" << getX() << ", " << getY() << ")" << endl;
    }

    void update() override {
    }
};

#endif
