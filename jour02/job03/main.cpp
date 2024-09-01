#include <iostream>
#include "Pingouin.hpp"

using namespace std;

int main() {
    auto pinguin1 = make_shared<Pingouin>(2.0, 1.0, 3.0);
    pinguin1->init();

    auto pinguin2 = make_shared<Pingouin>(2.5, 1.2, 3.5);
    pinguin2->init(); 

    pinguin1->sePresenter();
    pinguin1->nage();
    pinguin1->marche();
    pinguin1->glisse();
    Pingouin::afficherColonies();

    pinguin1->retirerDeLaColonie(); 
    Pingouin::afficherColonies();

    return 0;
}
