#include "Pingouin.hpp"
#include "Lieu.hpp"
#include <iostream>
#include <memory>

int main() {
    Lieu glacier("Glacier");
    Lieu lac("Lac");

    Lieu::ajouterLieu(glacier);
    Lieu::ajouterLieu(lac);

    Lieu::afficherLieux();

    auto pingouin1 = std::make_shared<Pingouin>(1.5, 0.8, 2.0, "Pingu");
    auto pingouin2 = std::make_shared<Pingouin>(1.2, 1.0, 1.8, "Pinga");

    pingouin1->init();
    pingouin2->init();

    pingouin1->ajouterCompetence("Nage", 3);
    pingouin1->ajouterCompetence("Marche", 2);
    pingouin1->ajouterCompetence("Glisse", 4);

    pingouin2->ajouterCompetence("Nage", 4);
    pingouin2->ajouterCompetence("Marche", 3);
    pingouin2->ajouterCompetence("Glisse", 3);

    std::cout << "\nCompetences de " << pingouin1->getNom() << " :\n";
    pingouin1->afficherCompetences();

    std::cout << "\nCompetences de " << pingouin2->getNom() << " :\n";
    pingouin2->afficherCompetences();

    std::cout << "\nTemps de parcours des pingouins :\n";
    Pingouin::afficherTempsParcoursColonies();

    pingouin1->modifierCompetence("Nage", 5);
    std::cout << "\nApres modification de la competence de nage de Pingu :\n";
    pingouin1->afficherCompetences();

    pingouin2->retirerCompetence("Marche");
    std::cout << "\nApres suppression de la competence de marche de Pinga :\n";
    pingouin2->afficherCompetences();

    Pingouin::afficherColonies();

    return 0;
}
