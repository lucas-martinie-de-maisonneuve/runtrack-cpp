#include "Competence.hpp"
#include <iostream>

using namespace std;

void Competence::ajouterCompetence(const string &nom, int niveau) {
    competences[nom] = niveau;
}

void Competence::modifierCompetence(const string &nom, int nouveauNiveau) {
    if (competences.find(nom) != competences.end()) {
        competences[nom] = nouveauNiveau;
    }
}

void Competence::retirerCompetence(const string &nom) {
    competences.erase(nom);
}

void Competence::afficherCompetences() const {
    cout << "Competences :" << endl;
    for (const auto &competence : competences) {
        cout << "- " << competence.first << " : " << competence.second << endl;
    }
}
