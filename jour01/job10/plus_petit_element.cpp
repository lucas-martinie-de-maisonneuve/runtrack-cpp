#include <iostream>
using namespace std;

void plusPetitElement(int **tableau, int taille)
{
    int minimum = **tableau;
    for (int i = 1; i < taille; i++)
    {
        if (*(*(tableau + i)) < minimum)
        {
            minimum = *(*(tableau + i));
        }
    }
    cout << "Le plus petit element est : " << minimum << endl;
}

int main()
{
    int a = 8, b = 3, c = 5, d = 1, e = 9, f = 4;
    int *tableau1[] = {&a, &b, &c, &d, &e, &f};

    int g = 18, h = 35, i = 50, j = 19, k = 99, l = 45, m = 72, n = 88, o = 12;
    int *tableau2[] = {&g, &h, &i, &j, &k, &l, &m, &n, &o};

    int taille1 = sizeof(tableau1) / sizeof(tableau1[0]);
    int taille2 = sizeof(tableau2) / sizeof(tableau2[0]);

    plusPetitElement(tableau1, taille1);
    plusPetitElement(tableau2, taille2);

    return 0;
}
