#include <iostream>
#include "EnemyFactory.hpp"
using namespace std;

int main()
{
    EnemyFactory factory;

    unique_ptr<Enemy> goblin = factory.createEnemy("goblin");
    goblin->attack();

    unique_ptr<Enemy> ogre = factory.createEnemy("ogre");
    ogre->attack();

    unique_ptr<Enemy> dragon = factory.createEnemy("dragon");
    dragon->attack();

    unique_ptr<Enemy> invalid = factory.createEnemy("troll");

    return 0;
}
