#include "Aquatique.hpp"
#include <iostream>
using namespace std;

Aquatique::Aquatique(double vitesse) : vitesse_nage(vitesse) {}

void Aquatique::nage() const {
    cout << "Je nage a une vitesse de " << vitesse_nage << " m/s." << endl;
}

Aquatique::~Aquatique() {}
