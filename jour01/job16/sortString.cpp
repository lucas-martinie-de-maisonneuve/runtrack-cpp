#include <cstring>
#include <iostream>
using namespace std;

void swap(char** a, char** b) {
    char* temp = *a;
    *a = *b;
    *b = temp;
}

void MySortString(char* arr[], int n) {
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

int main() {
    const int n = 5;
    char* arr[n] = {
        (char*)"Banane",
        (char*)"Orange",
        (char*)"Ananas",
        (char*)"Citron",
        (char*)"Pomme"
    };

    cout << "Avant le tri: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ", ";
    }

    MySortString(arr, n);

    cout << endl << "Apres le tri: " ;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ", ";
    }

    return 0;
}