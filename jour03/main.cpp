#include <iostream>
#include "includes/Player.hpp"
#include "includes/Enemy.hpp"
#include "includes/Sword.hpp"
#include "includes/Bow.hpp"
#include "includes/Spear.hpp"

using namespace std;

int main()
{
    Player player("Hero", 100, 0, 0); // Notez que le constructeur ne prend pas d'arme
    Enemy enemy("Goblin", 50, 5, 5, new Bow()); // L'ennemi a une arme initiale

    // Affichage des positions initiales
    player.draw();
    enemy.draw();

    // Simulation de plusieurs tours
    for (int turn = 1; turn <= 5; ++turn)
    {
        std::cout << "\n--- Turn " << turn << " ---\n";

        // Mise à jour du joueur et de l'ennemi
        player.update(enemy);
        enemy.update(player);

        // Affichage des positions après chaque tour
        player.draw();
        enemy.draw();

        cout << player.getName() << " (" << player.getHealth() << " HP) // " << enemy.getName() << " (" << enemy.getHealth() << " HP)" << endl;

        // Fin de la simulation si l'un des deux meurt
        if (!player.isAlive() || !enemy.isAlive())
        {
            std::cout << "\nCombat ended.\n";
            break;
        }
    }

    return 0;
}
