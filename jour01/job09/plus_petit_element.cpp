#include <iostream>
using namespace std;

void plusPetitElement(int* tableau, int taille) {
    int minimum = *tableau;

    for (int i = 1; i < taille; i++) {
        if (*(tableau + i) < minimum) {
            minimum = *(tableau + i);
        }
    }
    cout << "Le plus petit element est : " << minimum << endl;
}

int main() {
    int tableau1[] = {8, 3, 5, 1, 9, 4};
    int tableau2[] = {18, 35, 50, 19, 99, 45, 72, 88, 12};

    int taille1 = sizeof(tableau1) / sizeof(tableau1[0]);
    int taille2 = sizeof(tableau2) / sizeof(tableau2[0]);


    plusPetitElement(tableau1, taille1);
    plusPetitElement(tableau2, taille2);

    return 0;
}
