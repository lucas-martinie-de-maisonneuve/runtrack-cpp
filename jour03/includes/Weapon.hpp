#ifndef WEAPON_HPP
#define WEAPON_HPP

#include "Character.hpp"

class Weapon {
public:
    virtual double getRange() const = 0;
    virtual void attack(Character &target) const = 0;
    virtual ~Weapon() = default;
};

#endif
