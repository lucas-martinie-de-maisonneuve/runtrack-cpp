#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int annee;
    cout << "Entrez une annee: ";
    cin >> annee;
    if (annee % 4 == 0)
    {
        if (annee % 100 == 0)
        {
            if (annee % 400 == 0)
                cout << annee << " est une annee bissextile";
            else
                cout << annee << " n'est pas une annee bissextile";
        }
        else
            cout << annee << " est une annee bissextile";
    }
    else
        cout << annee << " n'est pas une annee bissextile";
    return 0;
}
