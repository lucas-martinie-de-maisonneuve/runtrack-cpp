#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <memory>
#include <algorithm>
#include "GameObject.hpp"
#include "Character.hpp"

class Game
{
private:
    std::vector<std::unique_ptr<GameObject>> gameObjects;

public:
    void addObject(std::unique_ptr<GameObject> obj)
    {
        gameObjects.push_back(std::move(obj));
    }

    void removeObject(GameObject *obj)
    {
        auto it = std::remove_if(gameObjects.begin(), gameObjects.end(),
                                 [obj](const std::unique_ptr<GameObject> &p)
                                 { return p.get() == obj; });
        gameObjects.erase(it, gameObjects.end());
    }

    void updateGame()
    {
        for (auto &obj : gameObjects)
        {
            obj->update();
        }

        // Supprimer les ennemis morts
        gameObjects.erase(
            std::remove_if(gameObjects.begin(), gameObjects.end(),
                           [](const std::unique_ptr<GameObject> &p)
                           {
                               if (Character *character = dynamic_cast<Character *>(p.get()))
                               {
                                   return character->getHp() <= 0;
                               }
                               return false;
                           }),
            gameObjects.end());
    }

    void drawObjects() const
    {
        for (const auto &obj : gameObjects)
        {
            obj->draw();
        }
    }

    const std::vector<std::unique_ptr<GameObject>> &getObjects() const
    {
        return gameObjects;
    }
};

#endif
