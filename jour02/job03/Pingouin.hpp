#ifndef PINGOUIN_HPP
#define PINGOUIN_HPP

#include "Aquatique.hpp"
#include "Terrestre.hpp"
#include <vector>
#include <memory>

using namespace std;

class Pingouin : public Aquatique, public Terrestre, public enable_shared_from_this<Pingouin>
{
private:
    double vitesse_glisse;

public:
    void init();
    static vector<shared_ptr<Pingouin>> colonies;
    Pingouin(double vitesseNage, double vitesseMarche, double vitesseGlisse);

    Pingouin(const Pingouin &autre);
    void setVitesseNage(double vitesse);
    void setVitesseMarche(double vitesse);
    void setVitesseGlisse(double vitesse);

    double getVitesseNage() const;
    double getVitesseMarche() const;
    double getVitesseGlisse() const;

    void sePresenter() const;
    void nage() const override;
    void marche() const override;
    void glisse() const;

    ~Pingouin();

    static void afficherColonies();
    void retirerDeLaColonie();
};

#endif
