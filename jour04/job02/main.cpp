#include <iostream>
#include "box.h"
using namespace std;

int main() {
    Box<int> intBox(5);
    cout << "Avant: " << intBox.getElement() << endl;
    intBox.setElement(8);
    cout << "Apres: " << intBox.getElement() << endl;

    // Utilisation avec des double
    Box<double> doubleBox(1.1);
    cout << "Avant: " << doubleBox.getElement() << endl;
    doubleBox.setElement(2.1);
    cout << "Apres: " << doubleBox.getElement() << endl;

    // Utilisation avec des string
    Box<string> stringBox("Pomme");
    cout << "Avant: " << stringBox.getElement() << endl;
    stringBox.setElement("Banane");
    cout << "Apres: " << stringBox.getElement() << endl;

    return 0;
}
