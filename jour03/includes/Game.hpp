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
    std::vector<std::vector<bool>> collisionGrid;
    static const int GRID_SIZE = 20;
    static const int CELL_SIZE = 1;

public:
    Game() : collisionGrid(GRID_SIZE, std::vector<bool>(GRID_SIZE, false)) {}

    void updateGame()
    {
        for (auto &row : collisionGrid)
        {
            std::fill(row.begin(), row.end(), false);
        }

        for (auto &obj : gameObjects)
        {
            obj->update();
        }

        checkCollisions();

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

    void checkCollisions()
    {
        for (const auto &obj : gameObjects)
        {
            int gridX = static_cast<int>(obj->getX()) / CELL_SIZE;
            int gridY = static_cast<int>(obj->getY()) / CELL_SIZE;

            if (gridX >= 0 && gridX < GRID_SIZE && gridY >= 0 && gridY < GRID_SIZE)
            {
                collisionGrid[gridY][gridX] = true;
            }
        }
    }

    bool isCellOccupied(int x, int y) const
    {
        int gridX = x / CELL_SIZE;
        int gridY = y / CELL_SIZE;

        return gridX >= 0 && gridX < GRID_SIZE && gridY >= 0 && gridY < GRID_SIZE && collisionGrid[gridY][gridX];
    }

    bool isPositionOccupied(double x, double y) const
    {
        int gridX = static_cast<int>(x) / CELL_SIZE;
        int gridY = static_cast<int>(y) / CELL_SIZE;

        if (gridX >= 0 && gridX < GRID_SIZE && gridY >= 0 && gridY < GRID_SIZE)
        {
            for (const auto &obj : gameObjects)
            {
                if (obj->getX() == x && obj->getY() == y)
                {
                    return true;
                }
            }
        }
        return false;
    }

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

    void drawMap() const
    {
        std::cout << std::endl;
        const int mapSize = 11;
        std::vector<std::vector<char>> map(mapSize, std::vector<char>(mapSize, ' '));

        for (const auto &obj : getObjects())
        {
            int x = static_cast<int>(obj->getX());
            int y = static_cast<int>(obj->getY());

            if (x >= 0 && x < mapSize && y >= 0 && y < mapSize)
            {
                if (obj->getId() == 1)
                {
                    map[y][x] = 'H';
                }
                else if (obj->getId() == 2)
                {
                    map[y][x] = 'E';
                }
                else if (obj->getId() == 3) 
                {
                    map[y][x] = 'X';
                }
            }
        }

        std::cout << "+";
        for (int i = 0; i < mapSize; ++i)
        {
            std::cout << "----";
        }
        std::cout << "+" << std::endl;

        for (int y = 0; y < mapSize; ++y)
        {
            std::cout << "|";
            for (int x = 0; x < mapSize; ++x)
            {
                std::cout << " " << map[y][x] << " |";
            }
            std::cout << std::endl;

            std::cout << "+";
            for (int i = 0; i < mapSize; ++i)
            {
                std::cout << "----";
            }
            std::cout << "+" << std::endl;
        }
    }
};

#endif
