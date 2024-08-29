#include "Pingouin.hpp"
#include <iostream>
using namespace std;

Pingouin::Pingouin(double vitesseNage, double vitesseMarche)
    : Aquatique(vitesseNage), Terrestre(vitesseMarche) {}

void Pingouin::sePresenter() const {
    cout << "Je suis un pingouin. Je nage et je marche" << endl;
}

void Pingouin::nage() const {
    cout << "Le pingouin nage a une vitesse de " << vitesse_nage << " m/s." << endl;
}

void Pingouin::marche() const {
    cout << "Le pingouin marche a une vitesse de " << vitesse_marche << " m/s." << endl;
}
