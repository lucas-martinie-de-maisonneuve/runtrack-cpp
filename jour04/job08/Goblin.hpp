#ifndef GOBLIN_HPP
#define GOBLIN_HPP

#include "Enemy.hpp"

class Goblin : public Enemy {
public:
    void attack() const override {
        std::cout << "Goblin attack" << std::endl;
    }
};

#endif
