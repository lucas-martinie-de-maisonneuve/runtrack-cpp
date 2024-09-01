#ifndef PINGOUIN_HPP
#define PINGOUIN_HPP

#include "Aquatique.hpp"
#include "Terrestre.hpp"
#include <vector>
#include <string>
#include <memory>

using namespace std;

class Pingouin : public Aquatique, public Terrestre, public enable_shared_from_this<Pingouin> {
private:
    double vitesse_glisse;
    string nom;

public:
    static vector<shared_ptr<Pingouin>> colonies;
    Pingouin(double vitesseNage, double vitesseMarche, double vitesseGlisse, const string& nom);

    Pingouin(const Pingouin& autre);
    void init();

    void setVitesseNage(double vitesse);
    void setVitesseMarche(double vitesse);
    void setVitesseGlisse(double vitesse);

    double getVitesseNage() const;
    double getVitesseMarche() const;
    double getVitesseGlisse() const;
    string getNom() const;

    void sePresenter() const;
    void nage() const override;
    void marche() const override;
    void glisse() const;

    double calculerTempsParcours() const;  
    static void afficherTempsParcoursColonies();

    ~Pingouin();

    static void afficherColonies();
    void retirerDeLaColonie();
};

#endif
