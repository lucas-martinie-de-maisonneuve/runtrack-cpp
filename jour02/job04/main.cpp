#include <iostream>
#include "Pingouin.hpp"

using namespace std;

int main() {
    auto pinguin1 = make_shared<Pingouin>(2.0, 1.0, 3.0, "Pingu");
    pinguin1->init();
    auto pinguin2 = make_shared<Pingouin>(2.5, 1.2, 3.5, "Pinga");
    pinguin2->init();

    Pingouin::afficherTempsParcoursColonies();

    return 0;
}
