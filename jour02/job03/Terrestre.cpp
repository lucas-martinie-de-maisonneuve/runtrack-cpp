#include "Terrestre.hpp"
#include <iostream>
using namespace std;

Terrestre::Terrestre(double vitesse) : vitesse_marche(vitesse) {}

void Terrestre::marche() const {
    cout << "Je marche a une vitesse de " << vitesse_marche << " m/s." << endl;
}

Terrestre::~Terrestre() {}
