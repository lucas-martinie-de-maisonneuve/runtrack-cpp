#ifndef COMPETENCE_HPP
#define COMPETENCE_HPP

#include <string>
#include <map>

class Competence {
private:
    std::map<std::string, int> competences;

public:
    void ajouterCompetence(const std::string &nom, int niveau);
    void modifierCompetence(const std::string &nom, int nouveauNiveau);
    void retirerCompetence(const std::string &nom);
    void afficherCompetences() const;
};

#endif
