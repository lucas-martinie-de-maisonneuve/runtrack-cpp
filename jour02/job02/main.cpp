#include <iostream>
#include "Pingouin.hpp"
using namespace std;

int main() {
    Pingouin p(2.5, 1.2, 3.0);

    p.sePresenter();
    p.nage();
    p.marche();
    p.glisse();

    p.setVitesseNage(3.0);
    p.setVitesseMarche(1.5);
    p.setVitesseGlisse(4.0);

    cout << "Vitesse de nage modifiee : " << p.getVitesseNage() << " m/s." << endl;
    cout << "Vitesse de marche modifiee : " << p.getVitesseMarche() << " m/s." << endl;
    cout << "Vitesse de glisse modifiee : " << p.getVitesseGlisse() << " m/s." << endl;

    Pingouin p2 = p;
    p2.sePresenter();
    p2.nage();
    p2.marche();
    p2.glisse();

    return 0;
}
