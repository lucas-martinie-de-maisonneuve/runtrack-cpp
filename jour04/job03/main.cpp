#include <iostream>
#include "Box.h"
using namespace std;

int main() {
    Box<int> intBox(5);
    cout << "Avant: " << intBox.getElement() << endl;
    intBox.setElement(8);
    cout << "Apres: " << intBox.getElement() << endl;

    Box<double*> doubleBox(new double(1.1));
    cout << "Avant: " << *doubleBox.getElement() << endl;
    *doubleBox.getElement() = 2.1;
    cout << "Apres: " << *doubleBox.getElement() << endl; 

    Box<string*> stringBox(new string("Pomme"));
    cout << "Avant: " << *stringBox.getElement() << endl;
    *stringBox.getElement() = "Banane";
    cout << "Apres: " << *stringBox.getElement() << endl;

    return 0;
}
