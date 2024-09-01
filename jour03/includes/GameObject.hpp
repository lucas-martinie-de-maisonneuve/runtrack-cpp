#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include "Vector2d.hpp"

class GameObject : public Vector2d
{
protected:
    int id;

public:
    GameObject(int id, double x = 0, double y = 0) 
        : Vector2d(x, y), id(id) {}

    virtual void draw() const = 0;
    virtual void update() = 0;

    int getId() const {
        return id;
    }
    
    virtual ~GameObject() = default;
};

#endif
