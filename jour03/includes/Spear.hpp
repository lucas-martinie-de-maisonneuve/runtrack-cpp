#ifndef SPEAR_HPP
#define SPEAR_HPP

#include "Weapon.hpp"

class Spear : public Weapon {
public:
    double getRange() const override { return 3.0; }
    void attack(Character &target) const override {
        std::cout << "a spear at " << target.getName() <<" (-15) "<< std::endl;
        target.takeDamage(15);
    }
};

#endif
