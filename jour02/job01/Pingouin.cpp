#include "Pingouin.hpp"
#include <iostream>

Pingouin::Pingouin(double vitesseNage, double vitesseMarche)
    : Aquatique(vitesseNage), Terrestre(vitesseMarche) {}

void Pingouin::sePresenter() const {
    std::cout << "Je suis un pingouin. Je nage et je marche" << std::endl;
}

void Pingouin::nage() const {
    std::cout << "Le pingouin nage a une vitesse de " << vitesse_nage << " m/s." << std::endl;
}

void Pingouin::marche() const {
    std::cout << "Le pingouin marche a une vitesse de " << vitesse_marche << " m/s." << std::endl;
}
