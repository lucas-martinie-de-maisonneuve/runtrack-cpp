#ifndef ENEMYFACTORY_HPP
#define ENEMYFACTORY_HPP

#include "Goblin.hpp"
#include "Ogre.hpp"
#include "Dragon.hpp"
#include <map>
#include <string>
#include <functional>
#include <memory>
using namespace std;

class EnemyFactory {
public:
    EnemyFactory() {
        enemyMap["goblin"] = []() -> Enemy* { return new Goblin(); };
        enemyMap["ogre"] = []() -> Enemy* { return new Ogre(); };
        enemyMap["dragon"] = []() -> Enemy* { return new Dragon(); };
    }

    unique_ptr<Enemy> createEnemy(const string& type) {
        auto it = enemyMap.find(type);
        if (it != enemyMap.end()) {
            return unique_ptr<Enemy>(it->second());
        } else {
            cout << "Error! Enemy type not defined.";
            return nullptr;
        }
    }

private:
    map<string, function<Enemy*()>> enemyMap;
};

#endif
