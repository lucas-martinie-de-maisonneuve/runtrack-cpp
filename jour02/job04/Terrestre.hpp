#ifndef TERRESTRE_HPP
#define TERRESTRE_HPP

class Terrestre {
protected:
    double vitesse_marche;

public:
    Terrestre(double vitesse);
    virtual void marche() const;
    virtual ~Terrestre();
};

#endif
