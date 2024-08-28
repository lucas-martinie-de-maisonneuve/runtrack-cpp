#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
 int n, inverse = 0, reste;

  cout << "Entrez un nombre : ";
  cin >> n;

  while(n != 0) {
    reste = n % 10;
    inverse = inverse * 10 + reste;
    n /= 10;
  }

  cout << "Nombre inverse = " << inverse;

  return 0;
}