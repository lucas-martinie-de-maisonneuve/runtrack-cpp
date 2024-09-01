#include "Pingouin.hpp"
#include <iostream>
#include <algorithm>
#include <iomanip> // Pour formatage du temps de parcours

using namespace std;

vector<shared_ptr<Pingouin>> Pingouin::colonies;

Pingouin::Pingouin(double vitesseNage, double vitesseMarche, double vitesseGlisse, const string &nom)
    : Aquatique(vitesseNage), Terrestre(vitesseMarche), vitesse_glisse(vitesseGlisse), nom(nom)
{
}

Pingouin::Pingouin(const Pingouin &autre)
    : Aquatique(autre.vitesse_nage), Terrestre(autre.vitesse_marche), vitesse_glisse(autre.vitesse_glisse), nom(autre.nom)
{
}

void Pingouin::init()
{
    colonies.push_back(shared_from_this());
    
    // Trie la colonie après chaque ajout, en fonction du temps de parcours
    sort(colonies.begin(), colonies.end(),
         [](const shared_ptr<Pingouin> &a, const shared_ptr<Pingouin> &b) {
             return a->calculerTempsParcours() < b->calculerTempsParcours();
         });
}

void Pingouin::setVitesseNage(double vitesse)
{
    vitesse_nage = vitesse;
    // Réorganiser la colonie après la modification de la vitesse
    sort(colonies.begin(), colonies.end(),
         [](const shared_ptr<Pingouin> &a, const shared_ptr<Pingouin> &b) {
             return a->calculerTempsParcours() < b->calculerTempsParcours();
         });
}

void Pingouin::setVitesseMarche(double vitesse)
{
    vitesse_marche = vitesse;
    // Réorganiser la colonie après la modification de la vitesse
    sort(colonies.begin(), colonies.end(),
         [](const shared_ptr<Pingouin> &a, const shared_ptr<Pingouin> &b) {
             return a->calculerTempsParcours() < b->calculerTempsParcours();
         });
}

void Pingouin::setVitesseGlisse(double vitesse)
{
    vitesse_glisse = vitesse;
    // Réorganiser la colonie après la modification de la vitesse
    sort(colonies.begin(), colonies.end(),
         [](const shared_ptr<Pingouin> &a, const shared_ptr<Pingouin> &b) {
             return a->calculerTempsParcours() < b->calculerTempsParcours();
         });
}

double Pingouin::getVitesseNage() const
{
    return vitesse_nage;
}

double Pingouin::getVitesseMarche() const
{
    return vitesse_marche;
}

double Pingouin::getVitesseGlisse() const
{
    return vitesse_glisse;
}

string Pingouin::getNom() const
{
    return nom;
}

void Pingouin::sePresenter() const
{
    cout << "Je suis un pingouin nommé " << nom << ". Je nage, je marche et je glisse." << endl;
}

void Pingouin::nage() const
{
    cout << "Le pingouin nage a une vitesse de " << vitesse_nage << " m/s." << endl;
}

void Pingouin::marche() const
{
    cout << "Le pingouin marche a une vitesse de " << vitesse_marche << " m/s." << endl;
}

void Pingouin::glisse() const
{
    cout << "Le pingouin glisse a une vitesse de " << vitesse_glisse << " m/s." << endl;
}

double Pingouin::calculerTempsParcours() const
{
    double tempsGlisse = 15.0 / vitesse_glisse;
    double tempsPlat1 = 20.0 / vitesse_marche;
    double tempsNage = 50.0 / vitesse_nage;
    double tempsPlat2 = 15.0 / vitesse_marche;

    return tempsGlisse + tempsPlat1 + tempsNage + tempsPlat2;
}

void Pingouin::afficherTempsParcoursColonies()
{
    for (const auto &pingouin : colonies)
    {
        cout << pingouin->getNom() << " : "
             << pingouin->calculerTempsParcours()
             << " secondes pour parcourir la piste." << endl;
    }
}

void Pingouin::ajouterCompetence(const string &nom, int niveau) {
    competences.ajouterCompetence(nom, niveau);
}

void Pingouin::modifierCompetence(const string &nom, int nouveauNiveau) {
    competences.modifierCompetence(nom, nouveauNiveau);
}

void Pingouin::retirerCompetence(const string &nom) {
    competences.retirerCompetence(nom);
}

void Pingouin::afficherCompetences() const {
    competences.afficherCompetences();
}

Pingouin::~Pingouin()
{
    retirerDeLaColonie();
}

void Pingouin::retirerDeLaColonie()
{
    auto it = find_if(colonies.begin(), colonies.end(),
                      [this](const shared_ptr<Pingouin> &ptr)
                      { return ptr.get() == this; });

    if (it != colonies.end())
    {
        colonies.erase(it);
    }
}

void Pingouin::afficherColonies()
{
    cout << "Nombre de pingouins dans la colonie: " << colonies.size() << endl;
}
