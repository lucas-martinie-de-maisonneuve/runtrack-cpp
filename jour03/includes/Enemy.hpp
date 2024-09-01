#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Character.hpp"
#include <cmath>

class Enemy : public Character
{
private:
    double moveSpeed;
    Game &game;

public:
    Enemy(const std::string &name, int hp, double x, double y, double moveSpeed, Game &game)
        : Character(2, name, hp, x, y), moveSpeed(moveSpeed), game(game) {}

    void attack(Character &target) const override
    {
        double dist = distance(target);
        if (dist <= 1.0) 
        {
            std::cout << getName() << " attacks " << target.getName() <<" (-10) "<< std::endl;
            target.takeDamage(10);
        }
    }

    void update() override
    {
        Character *player = nullptr;
        double minDistance = std::numeric_limits<double>::max();

        for (const auto &obj : game.getObjects())
        {
            if (obj->getId() == 1)
            {
                player = dynamic_cast<Character *>(obj.get());
                if (player)
                {
                    double dist = distance(*player);
                    if (dist < minDistance)
                    {
                        minDistance = dist;
                    }
                }
            }
        }

        if (player)
        {
            double distX = player->getX() - getX();
            double distY = player->getY() - getY();

            if (std::abs(distX) <= 1.0 && std::abs(distY) <= 1.0)
            {
                attack(*player);
            }
            else
            {
                if (std::abs(distX) > std::abs(distY))
                {
                    if (distX > 0)
                    {
                        setX(getX() + moveSpeed);
                    }
                    else
                    {
                        setX(getX() - moveSpeed);
                    }
                }
                else
                {
                    if (distY > 0)
                    {
                        setY(getY() + moveSpeed);
                    }
                    else
                    {
                        setY(getY() - moveSpeed);
                    }
                }
            }
        }
    }

    void draw() const override
    {
        std::cout << "[" << getName() << "] "<< getHp() <<" HP (" << getX() << ", " << getY() << ") " << std::endl;
    }
};

#endif
