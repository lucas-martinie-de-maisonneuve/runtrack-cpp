#ifndef SWORD_HPP
#define SWORD_HPP

#include "Weapon.hpp"

class Sword : public Weapon {
public:
    double getRange() const override { return 1.0; }
    void attack(Character &target) const override {
        std::cout << "Swinging a sword at " << target.getName() <<" (-20) "<< std::endl;
        target.takeDamage(20);
    }
};

#endif
