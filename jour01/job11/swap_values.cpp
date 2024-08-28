#include <iostream>
using namespace std;

void swapValues(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int x = 5;
    int y = 10;
    int z = 15;

    cout << "Avant l'échange: x = " << x << ", y = " << y << endl;

    swapValues(x, y);

    cout << "Après l'échange: x = " << x << ", y = " << y << endl;

    cout << "Avant l'échange: x = " << x << ", z = " << z << endl;

    swapValues(x, z);

    cout << "Après l'échange: x = " << x << ", z = " << z << endl;

    return 0;
}
