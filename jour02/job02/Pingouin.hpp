#ifndef PINGOUIN_HPP
#define PINGOUIN_HPP

#include "Aquatique.hpp"
#include "Terrestre.hpp"

class Pingouin : public Aquatique, public Terrestre {
private:
    double vitesse_glisse;

public:
    Pingouin(double vitesseNage, double vitesseMarche, double vitesseGlisse);

    Pingouin(const Pingouin& autre); // copyconstructor

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
};

#endif
