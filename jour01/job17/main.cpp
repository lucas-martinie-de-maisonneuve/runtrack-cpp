#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Spe.hpp"
using namespace std;

int main() {
    Spe specialites[5] = {
        Spe::IA,
        Spe::Web,
        Spe::Logiciel,
        Spe::SystemeImmersif,
        Spe::Cybersecurite
    };

    srand(time(0));
    int nombreEtudiants[5];

    for (int i = 0; i < 5; ++i) {
        nombreEtudiants[i] = 12 + rand() % 55;
    }

    for (int i = 0; i < 5; ++i) {
        afficherSpecialite(specialites[i], nombreEtudiants[i]);
    }

    return 0;
}
