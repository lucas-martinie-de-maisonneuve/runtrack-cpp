#ifndef SPE_HPP
#define SPE_HPP

#include <string>
using namespace std;

enum class Spe {
    IA,
    Web,
    Logiciel,
    SystemeImmersif,
    Cybersecurite
};

string getSpe(Spe spec) {
    switch (spec) {
        case Spe::IA:
            return "Intelligence Artificielle";
        case Spe::Web:
            return "Developpement Web";
        case Spe::Logiciel:
            return "Developpement Logiciel";
        case Spe::SystemeImmersif:
            return "Systeme Immersif";
        case Spe::Cybersecurite:
            return "Cybersecurite";
        default:
            return "Inconnue";
    }
}

void afficherSpecialite(Spe spec, int nbEtudiants) {
    cout << getSpe(spec) << " : " << nbEtudiants << " etudiants" << endl;
}

#endif
