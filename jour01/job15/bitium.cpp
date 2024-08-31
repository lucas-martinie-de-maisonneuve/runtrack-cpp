#include <iostream>
using namespace std;

bool nbBitEstPair(unsigned int n) {
    unsigned int pair = 0;
    do {
        pair ^= (n & 1);
        n >>= 1;
    } while (n);

    return !pair;
}

int main() {

    // exemple avec 42 (101010), 3bits à 1 donc impair
    if (nbBitEstPair(42)) {
        cout << "Bits pair." << endl;
    } else {
        cout << "Bits impair." << endl;
    }

    // exemple avec 12 (1100), 2bits à 1 donc pair
    if (nbBitEstPair(12)) {
        cout << "Bits pair." << endl;
    } else {
        cout << "Bits impair." << endl;
    }

    return 0;
}
