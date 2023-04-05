#include <iostream>
#include "include/LinkedList.h"

#define BREAK_LINE "---------------"

using namespace std;

int main() {
    LinkedList<int> list;

    cout << "===== Lista jednokierunkowa =====" << endl;
    cout << "Operacja \"prepend(value)\" dodaje element na początku(headzie) listy: " << endl;
    list.prepend(1);
    list.printAll();
    cout << BREAK_LINE << endl;
    cout << "Operacja \"append(value)\" dodaje element na końcu listy: " << endl;
    list.append(2);
    list.printAll();
    cout << BREAK_LINE << endl;
    cout << "Dodwanie kliku nowych elementów do listy" << endl;
    list.append(5);
    list.append(30);
    list.prepend(45);
    list.prepend(70);
    list.append(99);
    list.printAll();
    cout << BREAK_LINE << endl;
    cout << "Usunięcie jednego elementu z listy za pomocą operacji \"remove(value)\", gdzie \"value\" to 2: " << endl;
    list.remove(2);
    list.printAll();
    cout << BREAK_LINE << endl;
    cout << "Usunięcie wszystkich elementów z listy" << endl;
    list.removeAll();
    list.printAll();

    return 0;
}

