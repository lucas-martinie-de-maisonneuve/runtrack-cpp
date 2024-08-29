#include <iostream>
using namespace std;

constexpr int fibonacci(int n)
{
    return (n <= 1) ? n : (fibonacci(n - 1) + fibonacci(n - 2));
}

bool bitsPair(unsigned int nb)
{
    int c = 0;
    while (nb)
    {
        c += (nb & 1);
        nb >>= 1;
    }
    return (c % 2 == 0);
}

int main()
{
    unsigned int nb;

    cout << "Dix premiers :" << endl;
    for (int i = 0; i < 10; ++i)
    {
        cout << fibonacci(i) << " ";
    }

    cout << "\nEntrez un nb non-signe de 32 bits : ";
    cin >> nb;

    if (bitsPair(nb))
    {
        cout << "Le nb de bits a 1 dans " << nb << " est pair." << endl;
    }
    else
    {
        cout << "Le nb de bits à 1 dans " << nb << " est impair." << endl;
    }
    return 0;
}