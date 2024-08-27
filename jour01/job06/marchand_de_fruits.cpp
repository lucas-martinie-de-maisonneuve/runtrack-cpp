#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    // Declaration des variables
    float prix_carotte;
    float quantite_carotte;
    float taxe;
    float prix_ttc; 

    // input prix / quantite / tva
    cout <<"Veuillez entrer le prix hors taxe pour 1 kilo de carottes : ";
    cin >> prix_carotte;

    cout <<"Veuillez entrer la quantite de carottes (en KG): ";
    cin >>quantite_carotte;

    cout <<"Veuillez entrer le montant de la taxe (en pourcentage): ";
    cin >>taxe;

    //calcul prix + tva
    prix_ttc = (prix_carotte * quantite_carotte) + (prix_carotte * quantite_carotte * (taxe / 100));
    cout << "Le prix TTC de " << quantite_carotte << " kG de carotte est de : " << prix_ttc << " euros.";
    return 0;
}
