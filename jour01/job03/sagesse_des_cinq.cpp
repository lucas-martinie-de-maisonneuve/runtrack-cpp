#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int a = 0;
    int input;

    for (int i = 1; i <= 5; i++)
    {
        cout << "Veuillez entrer le nombre " << i << " : ";
        cin >> input;
        a += input;
    }

    cout << "La moyenne des nombres est : " << a / 5 << endl;

    return 0;
}
