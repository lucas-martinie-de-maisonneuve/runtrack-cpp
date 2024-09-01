#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "GameObject.hpp"
#include <string>

class Character : public GameObject
{
private:
    int id;
    std::string name;
    int hp;

public:
Character(int id, const std::string& name, int hp, double x = 0, double y = 0)
    : GameObject(id, x, y), id(id), name(name), hp(hp) {}


    int getId() const { return id; }
    const std::string& getName() const { return name; }
    int getHp() const { return hp; }

    void takeDamage(int amount) { hp -= amount; }
    
    virtual void attack(Character &target) const = 0;
    virtual void update() = 0;
    virtual void draw() const = 0;
};

#endif
