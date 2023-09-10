/*
객지 LAB 1주차 coffee
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    string coffee;
    int many, goal;
    int price = 0;
    
    cout << "Menu: Espresso 4000, Americano 4500, Cafuccino 5000" << endl << endl;

    cout << "Enter goal amount today: ";
    cin >> goal;

    while (price <= goal) {

        cout << endl << "What item?>> ";
        cin >> coffee;

        cout << "How many?>> ";
        cin >> many;

        if (coffee == "Espresso") {
            cout << "pay for " << 4000 * many << endl;
            price += 4000 * many ;
        }
        else if (coffee == "Americano") {
            cout << "pay for " << 4500 * many << endl;
            price += 4500 * many;
        }
        else if (coffee == "Cafuccino") {
            cout << "pay for " << 5000 * many << endl;
            price += 5000 * many;
        }
        else {
            cout << "You have a wrong order" << endl;
        }
    }
    cout << endl << "Great Job! You earned " << price << endl;
}