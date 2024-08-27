#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int nombre; // Declaration de variable
    cout << "Veuillez entrer un nombre : ";
    while (!(cin >> nombre)) // Verification que l'input soit un nombre
    {
        cout << "Woops, ce n'est pas un nombre !" << endl
             << "Veuillez entrer un nombre : ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    if (nombre % 2 == 0) // Si le reste du nombre divisé par 2 est 0, le nombre est pair
    {
        cout << nombre << " est un nombre pair !";
    }
    else // Sinon il est impair
    {
        cout << nombre << " est un nombre impair !";
    }
    return 0;
}
