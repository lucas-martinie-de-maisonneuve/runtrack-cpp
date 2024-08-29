#include "Terrestre.hpp"
#include <iostream>

Terrestre::Terrestre(double vitesse) : vitesse_marche(vitesse) {}

void Terrestre::marche() const {
    std::cout << "Je marche a une vitesse de " << vitesse_marche << " m/s." << std::endl;
}

Terrestre::~Terrestre() {}
