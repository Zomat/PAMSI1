#include <iostream>
#include "include/Array2D.h"
#include "include/Array1D.h"

using namespace std;

Array1D* my1DArray = nullptr;
Array2D<int>* my2DArray = nullptr;

void display2DArrayMenu()
{
    cout << endl;
    cout << "--- TABLICA DYNAMICZNA 2D ---" << endl;
    cout << "1. Wypełnij tablicę losowymi wartościami" << endl;
    cout << "2. Wyświetl zawartość tablicy" << endl;
    cout << "3. Znajdź wartość maksymalną tablicy" << endl;
    cout << "0. Powrot do menu" << endl;
    cout << "Podaj opcje:";
}


void menu_array2d() {
    char opt;
    int randomMax;
    int m, n;

    cout << "Ile wierszy ma ma mieć tablica?: ";
    cin >> m;

    cout << "Ile kolumn ma mieć tablica?: ";
    cin >> n;

    my2DArray = new Array2D<int>(m, n);

    do {
        display2DArrayMenu();
        cin >> opt;
        cout << endl;
        switch (opt) {
            case '1': // Wypełnij losowymi wartościami
                cout << "Podaj max. wartość: ";
                cin >> randomMax;

                my2DArray->fillWithRandomValues(randomMax);
                break;

            case '2': // Wyświetlanie zawartości tablicy
                my2DArray->printValues();
                break;

            case '3': // Znajdz wartosc maksymalna tablicy
                cout << "Wartość maksymalna tablicy: " << my2DArray->getMaxValue() << endl;
                break;
        }
    } while (opt != '0');

    delete my2DArray;
}

void display1DArrayMenu()
{
    cout << endl;
    cout << "--- TABLICA 1D ---" << endl;
    cout << "1. Zapisz do pliku tekstowego" << endl;
    cout << "2. Wczytaj z pliku tekstowego" << endl;
    cout << "3. Zapisz do pliku binarnego" << endl;
    cout << "4. Wczytaj z pliku binarnego" << endl;
    cout << "0. Powrot do menu" << endl;
    cout << "Podaj opcje:";
}

void menu_array1d() {
    char opt;
    string filename;
    int size;

    cout << "Jaką wielkość ma mieć tablica?: ";
    cin >> size;

    my1DArray = new Array1D(size);

    do {
        display1DArrayMenu();
        cin >> opt;
        cout << endl;
        switch (opt) {
            case '1':
                cout << "Podaj nazwę pliku do którego chcesz zapisać: ";
                cin >> filename;
                my1DArray->saveToTxt(filename);
                break;

            case '2':
                cout << "Podaj nazwę pliku z którego chcesz wczytać: ";
                cin >> filename;
                my1DArray->loadFromTxt(filename);
                break;

            case '3':
                cout << "Podaj nazwę pliku do którego chcesz zapisać: ";
                cin >> filename;
                my1DArray->saveToBin(filename);
                break;

            case '4':
                cout << "Podaj nazwę pliku z którego chcesz wczytać: ";
                cin >> filename;
                my1DArray->loadFromBin(filename);
                break;
        }
    } while (opt != '0');

    delete my1DArray;
}

int main() {
    char option;
    do{
        cout << endl;
        cout << "==== MENU GLOWNE ===" << endl;
        cout << "1.Tablica jednowymiarowa" << endl;
        cout << "2.Tablica dynamiczna dwuwymiarowa" << endl;
        cout << "0.Wyjscie" << endl;
        cout << "Podaj opcje:";
        cin >> option;
        cout << endl;

        switch (option){
            case '1':
                menu_array1d();
                break;

            case '2':
                menu_array2d();
                break;
        }

    } while (option != '0');

    return 0;
}
