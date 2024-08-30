#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "GameObject.hpp"
#include "Vector2d.hpp"
#include <string>

class Character : public GameObject {
private:
    std::string name;
    int healthPoints;

public:
    Vector2d position;  // Utilisation de Vector2d pour la position

    Character(const std::string& name, int hp, double x = 0, double y = 0)
        : GameObject(x, y), name(name), healthPoints(hp), position(x, y) {}

    bool isAlive() const {
        return healthPoints > 0;
    }

    int getHealth() const {
        return healthPoints;
    }

    void takeDamage(int damage) {
        healthPoints -= damage;
        if (healthPoints < 0) {
            healthPoints = 0;
        }
    }

    void draw() const override {
        std::cout << "Drawing Character " << name << " at ";
        position.print();
    }

    virtual void update(Character& target) = 0;  // Méthode virtuelle pure

    const std::string& getName() const {
        return name;
    }

    double getX() const {
        return position.getX();
    }

    double getY() const {
        return position.getY();
    }

    void setX(double newX) {
        position.setX(newX);
    }

    void setY(double newY) {
        position.setY(newY);
    }

    double distance(const Character& other) const {
        Vector2d otherPos(other.getX(), other.getY());
        return position.distance(otherPos);
    }

    // Implémentation de la méthode update pour ne pas être abstraite
    void update() override {
        // Implémentation par défaut ou faire en sorte que les dérivés le fassent
    }
};

#endif
