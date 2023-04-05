#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>
#include "DequeEmptyException.h"

template <typename T>
class Deque {
private:
    struct Node{
        T value;
        Node* prev;
        Node* next;
    };

    Node* _front;
    Node* _rear;
public:
    Deque();
    ~Deque();

/**
* Zwraca ilość obiektów przechowywanych w deque
*/
    int size() const;

/**
* Zwraca true jeśli deque jest pusty
*/
    bool isEmpty() const;

/**
* Zwraca pierwszy obiekt w deque.
* Wyrzuca DequeEmptyException jeśli deque jest pusty
*/
    T getFront();

/**
* Zwraca ostatni obiekt w deque.
* Wyrzuca DequeEmptyException jeśli deque jest pusty
*/
    T getRear();

/**
* Dodaje obiekt do pocza̧tku deque’a.
*/
    T pushFront(const T &obj);
/**
* Usuwa pierwszy obiekt z deque.
* Wyrzuca DequeEmptyException jeśli deque jest pusty
*/
    T popFront();

/**
* Dodaje obiekt na końcu deque’a.
*/
    T pushRear(const T &obj);

/**
* Usuwa ostatni obiekt z deque.
* Wyrzuca DequeEmptyException jeśli deque jest pusty
*/
    T popRear();
};

#include "Deque.tpp"

#endif //DEQUE_H
