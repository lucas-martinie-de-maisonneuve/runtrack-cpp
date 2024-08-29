#include <iostream>
using namespace std;

int doubleArray(int *arr, int size)
{
    int sum = 0;
    for (int i = 0; i < size; ++i)
    {
        arr[i] *= 2;
        sum += arr[i];
    }
    return sum;
}

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    const int SIZE = 5;
    int arr[SIZE] = {1, 2, 3, 4, 5};

    cout << "Tableau avant : ";
    printArray(arr, SIZE);

    int sum = doubleArray(arr, SIZE);

    cout << "Somme : " << sum << endl;

    cout << "Tableau apres : ";
    printArray(arr, SIZE);

    return 0;
}
