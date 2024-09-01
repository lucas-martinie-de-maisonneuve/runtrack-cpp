#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Character.hpp"
#include "Weapon.hpp"
#include "Bow.hpp"
#include "Spear.hpp"
#include "Sword.hpp"
#include "Game.hpp"
#include <iostream>
#include <vector>
#include <memory>

class Player : public Character
{
private:
    std::vector<std::unique_ptr<Weapon>> weapons;
    int currentWeaponIndex;
    Game &game;

public:
    Player(const std::string &name, int hp, Game &game, double x = 0, double y = 0)
        : Character(1, name, hp, x, y), currentWeaponIndex(0), game(game)
    {
        weapons.push_back(std::make_unique<Bow>());
        weapons.push_back(std::make_unique<Spear>());
        weapons.push_back(std::make_unique<Sword>());
    }

    void attack(Character &target) const override
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

    void update() override
    {
        Character *closestEnemy = nullptr;
        double minDistance = std::numeric_limits<double>::max();

        for (const auto &obj : game.getObjects())
        {
            if (obj->getId() == 2)
            {
                Character *enemy = dynamic_cast<Character *>(obj.get());
                if (enemy && distance(*enemy) < minDistance)
                {
                    minDistance = distance(*enemy);
                    closestEnemy = enemy;
                }
            }
        }

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

                    double newX = getX();
                    double newY = getY();

                    switch (move)
                    {
                    case 'z':
                        newY -= 1;
                        break;
                    case 'q':
                        newX -= 1;
                        break;
                    case 's':
                        newY += 1;
                        break;
                    case 'd':
                        newX += 1;
                        break;
                    default:
                        std::cout << "!!! Invalid move direction !!!" << std::endl;
                        continue;
                    }

                    if (!game.isPositionOccupied(newX, newY))
                    {
                        setX(newX);
                        setY(newY);
                        std::cout << getName() << " moved to (" << getX() << ", " << getY() << ")" << std::endl;
                        hasMoved = true;
                    }
                    else
                    {
                        std::cout << "!!! Position is occupied !!!" << std::endl;
                    }
                }
                break;

            case '3':
                if (hasAttacked)
                {
                    std::cout << "!!! You can only attack once per turn !!!" << std::endl;
                }
                else
                {
                    if (closestEnemy)
                    {
                        attack(*closestEnemy);
                        hasAttacked = true;
                        if (closestEnemy->getHp() <= 0)
                        {
                            std::cout << closestEnemy->getName() << " died from his wound." << std::endl;
                        }
                    }
                    else
                    {
                        std::cout << "No enemies in range to attack!" << std::endl;
                    }
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
        std::cout << "[" << getName() << "] " << getHp() << " HP (" << getX() << ", " << getY() << ") " << std::endl;
    }
};

#endif
