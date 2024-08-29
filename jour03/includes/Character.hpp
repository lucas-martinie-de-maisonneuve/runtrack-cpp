#ifndef CHARACTER_HPP
#define CHARACTER_HPP
using namespace std;

#include "GameObject.hpp"
#include <string>

class Character : public GameObject {
private:
    string name;
    int healthPoints;

public:
    Character(const string& name, int hp, double x = 0, double y = 0)
        : GameObject(x, y), name(name), healthPoints(hp) {}

    bool isAlive() const {
        return healthPoints > 0;
    }

    void takeDamage(int damage) {
        healthPoints -= damage;
        if (healthPoints < 0) {
            healthPoints = 0;
        }
    }

    void draw() const override {
        cout << "Drawing Character " << name << " at (" << getX() << ", " << getY() << ")" << endl;
    }

    void update() override {
        // Character specific update logic (e.g., move, check status)
    }

    const string& getName() const {
        return name;
    }
};

#endif
