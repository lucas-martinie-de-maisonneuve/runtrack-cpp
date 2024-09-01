#ifndef AQUATIQUE_HPP
#define AQUATIQUE_HPP

class Aquatique {
protected:
    double vitesse_nage;

public:
    Aquatique(double vitesse);
    virtual void nage() const;
    virtual ~Aquatique();
};

#endif
