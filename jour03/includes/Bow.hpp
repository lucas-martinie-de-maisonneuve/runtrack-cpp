#ifndef BOW_HPP
#define BOW_HPP

#include "Weapon.hpp"

class Bow : public Weapon {
public:
    double getRange() const override { return 5.0; }
    void attack(Character &target) const override {
        std::cout << "Shooting an arrow at " << target.getName() <<" (-10) "<< std::endl;
        target.takeDamage(10);
    }
};

#endif
