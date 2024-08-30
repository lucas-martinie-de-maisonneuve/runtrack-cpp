#include <iostream>
#include "max.h"
using namespace std;

int main()
{
    int a = 5, b = 10;
    cout << "Max of " << a << " and " << b << " is : " << myMax(a, b) << endl;

    double x = 3.14, y = 2.71;
    cout << "Max of " << x << " and " << y << " is : " << myMax(x, y) << endl;

    string s1 = "apple", s2 = "banana";
    cout << "Max of " << s1 << " and " << s2 << " is : " << myMax(s1, s2) << endl;

    return 0;
}
