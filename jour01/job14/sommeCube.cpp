#include <iostream>
using namespace std;

int main()
{
    int N = 0;
    long long somme = 0;

    cout << "Entrez un entier N (N >= 5) : ";
    while (!(cin >> N) || N < 5) {
        cout << "Veuillez entrer un entier valide N (N >= 5) : ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    for (int i = 5; i <= N; ++i)
    {
        somme += i * i * i;
    }

    cout << "La somme des cubes de 5^3 à " << N << "^3 est : " << somme << endl;

    return 0;
}
