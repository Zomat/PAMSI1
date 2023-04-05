#include "Deque.h"

template <typename T>
Deque<T>::Deque() {
    _front = _rear = nullptr;
}

template <typename T>
Deque<T>::~Deque() {
    while (!isEmpty()) {
        popFront();
    }
}

template <typename T>
int Deque<T>::size() const {
    unsigned int size = 0;
    Node* temp = _front;

    while(temp != nullptr) {
        size++;
        temp = temp->next;
    }

    return size;
}

template <typename T>
bool Deque<T>::isEmpty() const {
    return _front == nullptr && _rear == nullptr;
}

template <typename T>
T Deque<T>::getFront() {
    if (isEmpty()) {
        throw DequeEmptyException();
    }

    return _front->value;
}

template <typename T>
T Deque<T>::getRear() {
    if (isEmpty()) {
        throw DequeEmptyException();
    }

    return _rear->value;
}

template <typename T>
T Deque<T>::pushFront(const T &obj) {
    Node* newNode = new Node;
    newNode->value = obj;
    newNode->prev = nullptr;
    newNode->next = nullptr;

    if (isEmpty()) {
        _front = _rear = newNode;
    } else {
        _front->prev = newNode;
        newNode->next = _front;
        newNode->prev = nullptr;
        _front = newNode;
    }

    return obj;
}

template <typename T>
T Deque<T>::pushRear(const T &obj) {
    Node* newNode = new Node;
    newNode->value = obj;
    newNode->prev = nullptr;
    newNode->next = nullptr;

    if (isEmpty()) {
        _front = _rear = newNode;
    } else {
        _rear->next = newNode;
        newNode->next = nullptr;
        newNode->prev = _rear;
        _rear = newNode;
    }

    return obj;
}

template <typename T>
T Deque<T>::popFront() {
    if (isEmpty()) {
        throw DequeEmptyException();
    }

    Node* temp = _front;
    T value = temp->value;

    _front = _front->next;

    if (_front == nullptr) {
        _rear = nullptr;
    } else {
        _front->prev = nullptr;
    }

    delete temp;

    return value;
}

template <typename T>
T Deque<T>::popRear() {
    if (isEmpty()) {
        throw DequeEmptyException();
    }

    Node* temp = _rear;
    T value = temp->value;

    _rear = _rear->prev;

    if (_rear == nullptr) {
        _front = nullptr;
    } else {
        _rear->next = nullptr;
    }

    delete temp;

    return value;
}