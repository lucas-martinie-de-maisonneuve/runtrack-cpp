#include "Lieu.hpp"
#include <iostream>

using namespace std;

list<Lieu> Lieu::lieux;

Lieu::Lieu(const string &nom) : nom(nom) {}

string Lieu::getNom() const {
    return nom;
}

void Lieu::ajouterLieu(const Lieu &lieu) {
    lieux.push_back(lieu);
}

void Lieu::retirerLieu(const string &nomLieu) {
    lieux.remove_if([&](const Lieu &l) { return l.getNom() == nomLieu; });
}

void Lieu::afficherLieux() {
    cout << "Lieux de rencontre disponibles:" << endl;
    for (const auto &lieu : lieux) {
        cout << "- " << lieu.getNom() << endl;
    }
}
