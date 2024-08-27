#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int m; // Declaration de variable
    int n;

    cout << "Veuillez entrer un nombre : ";
    cin >> m; // input m

    cout << "Veuillez entrer un second nombre : ";
    cin >> n; // input n 

    cout << "[Avant echange] m = " << m << " et n = " << n;
    int temp = m; // utilisation d'une variable pour garder en memoire m
    m = n; 
    n = temp; // echange des variables
    cout << "[Apres echange] m = " << m << " et n = " << n;
    return 0;
}
