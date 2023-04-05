#include <iostream>
#include "include/Deque.h"

using namespace std;

bool isPal(string str) {
    Deque<char> charDeque;

    for (char c : str) {
        charDeque.pushRear(c);
    }

    while (charDeque.size() > 1) {
        if (charDeque.popFront() != charDeque.popRear()) {
            return false;
        }
    }

    return true;
}

int main() {
    string word;
    cout << "Wpisz słowo, do sprawdzenia czy jest palindromem: ";
    cin >> word;
    cout << endl;

    cout << "Słowo \"" << word << "\"" << (isPal(word) ? " jest" : " nie jest") << " palindromem" << endl;

    return 0;
}
