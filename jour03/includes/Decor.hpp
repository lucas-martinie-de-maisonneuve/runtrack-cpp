#ifndef DECOR_HPP
#define DECOR_HPP

#include "GameObject.hpp"

class Decor : public GameObject
{
public:
    Decor(double x = 0, double y = 0)
        : GameObject(3, x, y) {}

    void draw() const override
    {
        std::cout << "Decor at (" << getX() << ", " << getY() << ") | ";
    }

    void update() override
    {
    }
};

#endif
