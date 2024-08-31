#include <iostream>
using namespace std;

void addElement(int*& table, int& taille, int elem) {
    int* tempTable = new int[taille + 1];
    
    for (int i = 0; i < taille; ++i) {
        tempTable[i] = table[i];
    }
    
    tempTable[taille] = elem;
    
    delete[] table;
    
    table = tempTable;
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

    addElement(tableau, taille, 59);
    showTable(tableau, taille);

    addElement(tableau, taille, 295);
    showTable(tableau, taille);

    addElement(tableau, taille, 45);
    showTable(tableau, taille);

    addElement(tableau, taille, 2);
    showTable(tableau, taille);

    addElement(tableau, taille, 72);
    showTable(tableau, taille);

    addElement(tableau, taille, 98);
    showTable(tableau, taille);

    delete[] tableau;
    return 0;
}
