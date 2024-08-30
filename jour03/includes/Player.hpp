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
    Weapon *weapons[3];
    int currentWeaponIndex;

public:
    Player(const std::string &name, int hp, double x, double y)
        : Character(name, hp, x, y), currentWeaponIndex(0)
    {
        weapons[0] = new Bow();
        weapons[1] = new Spear();
        weapons[2] = new Sword();
    }

    ~Player()
    {
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
        bool hasMoved = false;
        bool hasAttacked = false;
        bool turnOver = false;

        while (!turnOver)
        {
            char action;
            std::cout << "\n"
                      << "                   Choose an action\n"
                      << "       +-----------------------------------------+\n"
                      << "       |    [1] Switch Weapon                    |\n"
                      << "       |    [2] Move                             |\n"
                      << "       |    [3] Attack                           |\n"
                      << "       |    [4] End Turn                         |\n"
                      << "       +-----------------------------------------+\n\t";

            std::cin >> action;

            switch (action)
            {
            case '1':
                std::cout << "\n"
                          << "                   Choose your weapon\n"
                          << "       +-----------------------------------------+\n"
                          << "       |    [1] Bow                              |\n"
                          << "       |    [2] Spear                            |\n"
                          << "       |    [3] Sword                            |\n"
                          << "       +-----------------------------------------+\n\t";
                int weaponChoice;
                std::cin >> weaponChoice;

                if (weaponChoice < 1 || weaponChoice > 3)
                {
                    std::cout << "!!! Invalid weapon choice !!!" << std::endl;
                }
                else
                {
                    std::cout << getName() << " switched to ";
                    switch (weaponChoice)
                    {
                    case 1:
                        std::cout << "Bow" << std::endl;
                        currentWeaponIndex = 0;
                        break;
                    case 2:
                        std::cout << "Spear" << std::endl;
                        currentWeaponIndex = 1;
                        break;
                    case 3:
                        std::cout << "Sword" << std::endl;
                        currentWeaponIndex = 2;
                        break;
                    }
                }
                break;

            case '2':
                if (hasMoved)
                {
                    std::cout << "!!! You can only move once per turn !!!" << std::endl;
                }
                else
                {
                    char move;
                    std::cout << "\n"
                              << "                 Use Z, Q, S, D to move\n"
                              << "       +-----------------------------------------+\n"
                              << "       |                   Up                    |\n"
                              << "       |                  [Z]                    |\n"
                              << "       |         Left [Q] [S] [D] Right          |\n"
                              << "       |                 Down                    |\n"
                              << "       +-----------------------------------------+\n\t";
                    std::cin >> move;

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
                    default:
                        std::cout << "!!! Invalid move direction !!!" << std::endl;
                        continue;
                    }

                    std::cout << getName() << " moved to (" << getX() << ", " << getY() << ")" << std::endl;
                    hasMoved = true;
                }
                break;

            case '3':
                if (hasAttacked)
                {
                    std::cout << "!!! You can only attack once per turn !!!" << std::endl;
                }
                else
                {
                    attack(target);
                    hasAttacked = true;
                }
                break;

            case '4':
                std::cout << getName() << " ended their turn." << std::endl;
                turnOver = true;
                break;

            default:
                std::cout << "!!! Invalid action! Please choose a valid option !!!" << std::endl;
                break;
            }
        }
    }
    void draw() const override
    {
        std::cout << "Drawing Player " << getName() << " at ";
        position.print();
    }
};

#endif
