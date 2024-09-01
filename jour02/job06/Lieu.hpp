#ifndef LIEU_HPP
#define LIEU_HPP

#include <string>
#include <list>

class Lieu {
private:
    std::string nom;

public:
    static std::list<Lieu> lieux;

    Lieu(const std::string &nom);
    std::string getNom() const;

    static void ajouterLieu(const Lieu &lieu);
    static void retirerLieu(const std::string &nomLieu);
    static void afficherLieux();
};

#endif
