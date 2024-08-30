#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Character.hpp"
#include "Weapon.hpp"
#include "Spear.hpp"
#include "Bow.hpp"
#include "Sword.hpp"

class Player : public Character
{
private:
    Weapon *weapons[3]; // Tableau pour les armes disponibles
    int currentWeaponIndex;

public:
    Player(const std::string &name, int hp, double x, double y)
        : Character(name, hp, x, y), currentWeaponIndex(0)
    {
        // Initialisation des armes disponibles
        weapons[0] = new Bow();   // Assurez-vous que Bow est correctement défini
        weapons[1] = new Spear(); // Assurez-vous que Spear est correctement défini
        weapons[2] = new Sword(); // Assurez-vous que Sword est correctement défini
    }

    ~Player()
    {
        // Nettoyage des armes
        for (Weapon *weapon : weapons)
        {
            delete weapon;
        }
    }

    void attack(Character &target) const
    {
        double dist = distance(target);
        if (dist <= weapons[currentWeaponIndex]->getRange())
        {
            std::cout << getName() << " is attacking " << target.getName() << " with ";
            weapons[currentWeaponIndex]->attack(target);
        }
        else
        {
            std::cout << getName() << " is out of range to attack " << target.getName() << std::endl;
        }
    }

    void update(Character &target) override
    {
        char move;
        cout << "Chose z,q,s,d to move : ";
        cin >> move;

        switch (move)
        {
        case 'z':
            setY(getY() - 1);
            break;
        case 'q':
            setX(getX() - 1);
            break;
        case 's':
            setY(getY() + 1);
            break;
        case 'd':
            setX(getX() + 1);
            break;
        }

        std::cout << getName() << " moved to (" << getX() << ", " << getY() << ")" << std::endl;

        // Tenter une attaque après le déplacement
        attack(target);

        // Changer d'arme pour le prochain tour
        currentWeaponIndex = (currentWeaponIndex + 1) % 3;
        std::cout << getName() << " switched to ";
        if (currentWeaponIndex == 0)
        {
            std::cout << "Bow";
        }
        else if (currentWeaponIndex == 1)
        {
            std::cout << "Spear";
        }
        else
        {
            std::cout << "Sword";
        }
        std::cout << std::endl;
    }

    void draw() const override
    {
        std::cout << "Drawing Player " << getName() << " at ";
        position.print();
    }
};

#endif
