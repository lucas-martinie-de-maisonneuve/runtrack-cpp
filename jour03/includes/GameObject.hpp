#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include "Vector2d.hpp"

class GameObject : public Vector2d {
public:
    GameObject(double x = 0, double y = 0) : Vector2d(x, y) {}

    virtual void draw() const = 0;
    virtual void update() = 0;

    virtual ~GameObject() = default;
};

#endif
