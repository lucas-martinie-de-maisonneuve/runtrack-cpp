#include <iostream>
#include "includes/Game.hpp"
#include "includes/Player.hpp"
#include "includes/Enemy.hpp"
#include "includes/Bow.hpp"
#include "includes/Spear.hpp"
#include "includes/Sword.hpp"
#include "includes/Decor.hpp"

int main()
{
    Game game;

    auto player = std::make_unique<Player>("Hero", 100, game, 0, 0);
    game.addObject(std::move(player));

    auto enemy1 = std::make_unique<Enemy>("Goblin", 50, 5, 5, 2.0, game);
    auto enemy2 = std::make_unique<Enemy>("Orc", 70, 10, 10, 2.0, game);
    game.addObject(std::move(enemy1));
    game.addObject(std::move(enemy2));

    auto decor1 = std::make_unique<Decor>(2, 2);
    auto decor2 = std::make_unique<Decor>(7, 7);
    game.addObject(std::move(decor1));
    game.addObject(std::move(decor2));

    int turn = 0;
    while (turn < 10)
    {
        std::cout << "Turn nb : " << turn << "\n";
        game.drawObjects();
        game.drawMap();

        game.updateGame();

        turn++;
    }
    return 0;
}
