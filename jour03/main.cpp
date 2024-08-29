#include "includes/Vector2d.hpp"
#include "includes/Decor.hpp"
#include "includes/Character.hpp"

using namespace std;

int main() {
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

    cout << "Distance entre v1 et v2: " << v1.distance(v2) << endl;

    Decor decor(10, 15);
    decor.draw();
    decor.update();

    Character character("Hero", 100, 5, 5);
    character.draw();
    cout << "Character is alive: " << character.isAlive() << endl;


    return 0;
}
