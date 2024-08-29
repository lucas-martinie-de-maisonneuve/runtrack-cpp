#ifndef BOW_HPP
#define BOW_HPP
using namespace std;

#include "Weapon.hpp"

class Bow : public Weapon {
private:
    int range;
    int power;

public:
    Bow() : range(4), power(1) {}

    void attack(Character& target) const override {
        cout << "Attacking with Bow. Range: " << range << ", Power: " << power << endl;
        target.takeDamage(power);
    }
};

#endif
