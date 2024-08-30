#include <iostream>
#include "includes/Player.hpp"
#include "includes/Enemy.hpp"
#include "includes/Sword.hpp"
#include "includes/Bow.hpp"
#include "includes/Spear.hpp"

using namespace std;

int main()
{
    Player player("Hero", 100, 0, 0);
    Enemy enemy("Goblin", 50, 5, 5, new Bow());

    player.draw();
    enemy.draw();

    for (int turn = 1; turn <= 5; ++turn)
    {
        std::cout << "\n--- Turn " << turn << " ---\n";

        player.update(enemy);
        enemy.update(player);

        player.draw();
        enemy.draw();

        cout << player.getName() << " (" << player.getHealth() << " HP) // " << enemy.getName() << " (" << enemy.getHealth() << " HP)" << endl;

        if (!player.isAlive() || !enemy.isAlive())
        {
            std::cout << "\nCombat ended.\n";
            break;
        }
    }

    return 0;
}
