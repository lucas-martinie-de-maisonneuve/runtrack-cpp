#include <iostream>
using namespace std;

int main(void)
{
    // Declarations des variables
    int a;
    int b;

    cout << "Entrez le premier nombre a multiplier : ";

    /* boucle qui prend une input et qui verifie si l'entrée est une input.
     Dans le cas ou ce n'est pas un entier la question est reposé et l'input est vidé pour éviter les erreurs */
    while (!(cin >> a))
    {
        cout << "Woops, ce n'est pas un entier" << endl
             << "Entrez le premier nombre a multiplier : ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    cout << "Entrez le second nombre a multiplier : ";
    while (!(cin >> b))
    {
        cout << "Woops, ce n'est pas un entier" << endl
             << "Entrez le premier nombre a multiplier : ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    cout << "Le resultat de " << a << " x " << b << " est " << a * b;
}
