#include "Pingouin.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

vector<shared_ptr<Pingouin>> Pingouin::colonies;

Pingouin::Pingouin(double vitesseNage, double vitesseMarche, double vitesseGlisse)
    : Aquatique(vitesseNage), Terrestre(vitesseMarche), vitesse_glisse(vitesseGlisse) {
}

Pingouin::Pingouin(const Pingouin& autre)
    : Aquatique(autre.vitesse_nage), Terrestre(autre.vitesse_marche), vitesse_glisse(autre.vitesse_glisse) {
}

void Pingouin::init() {
    colonies.push_back(shared_from_this());
}

void Pingouin::setVitesseNage(double vitesse) {
    vitesse_nage = vitesse;
}

void Pingouin::setVitesseMarche(double vitesse) {
    vitesse_marche = vitesse;
}

void Pingouin::setVitesseGlisse(double vitesse) {
    vitesse_glisse = vitesse;
}

double Pingouin::getVitesseNage() const {
    return vitesse_nage;
}

double Pingouin::getVitesseMarche() const {
    return vitesse_marche;
}

double Pingouin::getVitesseGlisse() const {
    return vitesse_glisse;
}

void Pingouin::sePresenter() const {
    cout << "Je suis un pingouin. Je nage, je marche et je glisse." << endl;
}

void Pingouin::nage() const {
    cout << "Le pingouin nage a une vitesse de " << vitesse_nage << " m/s." << endl;
}

void Pingouin::marche() const {
    cout << "Le pingouin marche a une vitesse de " << vitesse_marche << " m/s." << endl;
}

void Pingouin::glisse() const {
    cout << "Le pingouin glisse a une vitesse de " << vitesse_glisse << " m/s." << endl;
}

Pingouin::~Pingouin() {
    retirerDeLaColonie();
}

void Pingouin::retirerDeLaColonie() {
    auto it = find_if(colonies.begin(), colonies.end(),
        [this](const shared_ptr<Pingouin>& ptr) { return ptr.get() == this; });

    if (it != colonies.end()) {
        colonies.erase(it);
    }
}

void Pingouin::afficherColonies() {
    cout << "Nombre de pingouins dans la colonie: " << colonies.size() << endl;
}
