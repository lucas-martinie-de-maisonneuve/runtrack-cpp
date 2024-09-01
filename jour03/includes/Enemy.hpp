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
            std::cout << getName() << " attacks " << target.getName() << " (-10) " << std::endl;
            target.takeDamage(10);
        }
    }

    void update() override
    {
        Character *player = nullptr;
        double minDistance = std::numeric_limits<double>::max();

        for (const auto &obj : game.getObjects())
        {
            if (obj->getId() == 1) // ID 1 pour le joueur
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

            if (std::abs(distX) <= 1.0 && std::abs(distY) <= 1.0) // Ajustez la portée d'attaque ici
            {
                attack(*player);
            }
            else
            {
                // Déplacement en X ou Y
                if (std::abs(distX) > std::abs(distY)) // Déplacement principalement en X
                {
                    if (distX > 0)
                    {
                        if (!game.isCellOccupied(static_cast<int>(getX() + moveSpeed), static_cast<int>(getY())))
                        {
                            setX(getX() + moveSpeed);
                        }
                    }
                    else
                    {
                        if (!game.isCellOccupied(static_cast<int>(getX() - moveSpeed), static_cast<int>(getY())))
                        {
                            setX(getX() - moveSpeed);
                        }
                    }
                }
                else
                {
                    if (distY > 0)
                    {
                        if (!game.isCellOccupied(static_cast<int>(getX()), static_cast<int>(getY() + moveSpeed)))
                        {
                            setY(getY() + moveSpeed);
                        }
                    }
                    else
                    {
                        if (!game.isCellOccupied(static_cast<int>(getX()), static_cast<int>(getY() - moveSpeed)))
                        {
                            setY(getY() - moveSpeed);
                        }
                    }
                }
            }
        }
    }

    void draw() const override
    {
        std::cout << "[" << getName() << "] " << getHp() << " HP (" << getX() << ", " << getY() << ") " << std::endl;
    }
};

#endif
