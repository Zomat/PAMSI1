#include "Queue.h"

template <typename T>
Queue<T>::Queue() {
    _head = nullptr;
    _tail = nullptr;
}

template <typename T>
Queue<T>::~Queue() {
    removeAll();
}

template <typename T>
void Queue<T>::enqueue(T value) {
    Node* newNode = new Node;
    newNode->value = value;

    if (_tail == nullptr) {
        _head = _tail = newNode;
    } else {
        _tail->next = newNode;
        _tail = newNode;
    }
}

template <typename T>
T Queue<T>::dequeue() {
    if (_head == nullptr) {
        throw std::runtime_error("Queue is empty");
    }

    T value = _head->value;
    Node* temp = _head;
    _head = _head->next;
    delete temp;

    if (_head == nullptr) {
        _tail = nullptr;
    }

    return value;
}

template <typename T>
void Queue<T>::printAll() {
    if (_head == nullptr) {
        std::cout << "(Queue empty, HEAD == nullptr)" << std::endl;
        return;
    }

    Node* temp = _head;
    uint index = 0;
    std::string headOrTail = "";

    while (temp != nullptr) {
        if (index == 0 && temp->next == nullptr) {
            headOrTail = " (HEAD/TAIL)";
        } else if (index == 0) {
            headOrTail = " (HEAD)";
        } else if (temp->next == nullptr) {
            headOrTail = " (TAIL)";
        } else {
            headOrTail = "";
        }

        std::cout << index << headOrTail << ": " << temp->value << std::endl;
        temp = temp->next;
        index++;
    }
}

template <typename T>
void Queue<T>::removeAll() {
    while (_head != nullptr) {
        Node* next = _head->next;
        delete _head;
        _head = next;
    }
}
