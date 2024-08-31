#ifndef OGRE_HPP
#define OGRE_HPP

#include "Enemy.hpp"

class Ogre : public Enemy {
public:
    void attack() const override {
        std::cout << "Ogre attack" << std::endl;
    }
};

#endif
