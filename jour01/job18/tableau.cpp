#include <iostream>
using namespace std;

void addElement(int*& table, int& taille, int nouvelElement) {
    int* nouveauTableau = new int[taille + 1];
    
    for (int i = 0; i < taille; ++i) {
        nouveauTableau[i] = table[i];
    }
    
    nouveauTableau[taille] = nouvelElement;
    
    delete[] table;
    
    table = nouveauTableau;
    ++taille;
}

void showTable(const int* table, int taille) {
    cout << "[Taille du tableau] : " << taille << " \t[Contenu] : ";
    for (int i = 0; i < taille; ++i) {
        cout << table[i] << " ";
    }
    cout << endl;
}

int main() {
    int taille = 5;
    int* tableau = new int[taille];

    showTable(tableau, taille);

    addElement(tableau, taille, 10);
    showTable(tableau, taille);

    addElement(tableau, taille, 20);
    showTable(tableau, taille);

    addElement(tableau, taille, 30);
    showTable(tableau, taille);

    addElement(tableau, taille, 40);
    showTable(tableau, taille);

    addElement(tableau, taille, 50);
    showTable(tableau, taille);

    addElement(tableau, taille, 60);
    showTable(tableau, taille);

    delete[] tableau;
    return 0;
}
