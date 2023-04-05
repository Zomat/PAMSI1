#include <iostream>
#include "include/Queue.h"

#define BREAK_LINE "--------------------------"

using namespace std;

int main() {
    Queue<int> q;
    cout << "===== Kolejka =====" << endl;
    cout << "Dodawanie elementu na koniec kolejki za pomocą operacji \"enqueue\"" << endl;
    q.enqueue(5);
    q.printAll();
    cout << BREAK_LINE << endl;
    cout << "Dodawanie kilku kolejnych elementów na koniec kolejki za pomocą operacji \"enqueue\"" << endl;
    q.enqueue(25);
    q.enqueue(33);
    q.enqueue(80);
    q.printAll();
    cout << BREAK_LINE << endl;
    cout << "Pobranie elementu z początku kolejki" << endl;
    cout << "Wartość pobranego elementu: " <<  q.dequeue() << endl;
    q.printAll();
    cout << BREAK_LINE << endl;
    cout << "Usunięcie wszystkich elementów z kolejki" << endl;
    q.removeAll();
    q.printAll();
    return 0;
}

