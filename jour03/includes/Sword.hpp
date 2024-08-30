#ifndef SWORD_HPP
#define SWORD_HPP
using namespace std;

#include "Weapon.hpp"

class Sword : public Weapon {
private:
    int range;
    int power;

public:
    Sword() : range(1), power(4) {}

    void attack(Character& target) const override {  // Ajout du mot-clé 'const'
        cout << "Attacking with Sword. Range: " << range << ", Power: " << power << endl;
        target.takeDamage(power);
    }

    int getRange() const override {
        return range;
    }
};

#endif
