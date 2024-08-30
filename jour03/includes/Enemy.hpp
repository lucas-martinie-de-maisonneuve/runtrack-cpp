#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Character.hpp"
#include "Weapon.hpp"

class Enemy : public Character {
private:
    Weapon* weapon;

public:
    Enemy(const std::string& name, int hp, double x, double y, Weapon* weapon)
        : Character(name, hp, x, y), weapon(weapon) {}

    void attack(Character& target) const {
        double dist = distance(target);
        if (dist <= weapon->getRange()) {
            std::cout << getName() << " is attacking " << target.getName() << " with ";
            weapon->attack(target);
        } else {
            std::cout << getName() << " is out of range to attack " << target.getName() << std::endl;
        }
    }

    void update(Character& target) override {  // Implémentation de la méthode update
        double dist = distance(target);
        if (dist > weapon->getRange()) {
            // Se rapprocher de la cible
            if (getX() < target.getX()) {
                setX(getX() + 1);
            } else if (getX() > target.getX()) {
                setX(getX() - 1);
            } else if (getY() < target.getY()) {
                setY(getY() + 1);
            } else if (getY() > target.getY()) {
                setY(getY() - 1);
            }
            std::cout << getName() << " moved to (" << getX() << ", " << getY() << ")" << std::endl;
        }

        // Tenter une attaque après le déplacement
        attack(target);
    }

    void draw() const override {
        std::cout << "Drawing Enemy " << getName() << " at ";
        position.print();
    }
};

#endif
