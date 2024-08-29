#ifndef SPEAR_HPP
#define SPEAR_HPP

#include "Weapon.hpp"
using namespace std;

class Spear : public Weapon {
private:
    int range;
    int power;

public:
    Spear() : range(2), power(2) {}

    void attack(Character& target) const override {
        cout << "Attacking with Spear. Range: " << range << ", Power: " << power << endl;
        target.takeDamage(power);
    }
};

#endif // SPEAR_HPP
