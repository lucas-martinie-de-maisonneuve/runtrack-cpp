#include "Aquatique.hpp"
#include <iostream>

Aquatique::Aquatique(double vitesse) : vitesse_nage(vitesse) {}

void Aquatique::nage() const {
    std::cout << "Je nage a une vitesse de " << vitesse_nage << " m/s." << std::endl;
}

Aquatique::~Aquatique() {}
