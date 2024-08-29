#include "includes/Vector2d.hpp"
#include "includes/Decor.hpp"
#include "includes/Character.hpp"
#include "includes/Bow.hpp"
#include "includes/Spear.hpp"
#include "includes/Sword.hpp"

using namespace std;

int main()
{
    Vector2d v1(3.0, 4.0);
    Vector2d v2(6.0, 8.0);

    Vector2d v3 = v1 + v2;
    Vector2d v4 = v1 - v2;

    cout << "v1: ";
    v1.print();

    cout << "v2: ";
    v2.print();

    cout << "v3 (v1 + v2): ";
    v3.print();

    cout << "v4 (v1 - v2): ";
    v4.print();

    cout << "Dist between v1 et v2: " << v1.distance(v2) << endl;

    Decor decor(10, 15);
    decor.draw();
    decor.update();

    Character character("Hero", 100, 5, 5);
    character.draw();
    character.update();
    cout << "Character is alive: " << character.isAlive() << " (" <<character.getHealth() <<" HP)"<< endl;

    Bow bow;
    Spear spear;
    Sword sword;

    bow.attack(character);
    spear.attack(character);
    sword.attack(character);

    cout << "Character is alive: " << character.isAlive() << " (" <<character.getHealth() <<" HP)"<< endl;

    return 0;
}
