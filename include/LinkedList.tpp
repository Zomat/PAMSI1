#include "LinkedList.h"

template <typename T>
LinkedList<T>::LinkedList() {
    _head = nullptr;
}

template <typename T>
LinkedList<T>::~LinkedList() {
    removeAll();
}

template <typename T>
void LinkedList<T>::prepend(T value) {
    Node* newNode = new Node;
    newNode->value = value;
    newNode->next = _head;
    _head = newNode;
}

template <typename T>
void LinkedList<T>::append(T value) {
    Node* newNode = new Node;
    newNode->next = nullptr;
    newNode->value = value;

    if (_head == nullptr) {
        _head = newNode;
    } else {
        Node* temp = _head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

template <typename T>
void LinkedList<T>::remove(T value) {
    Node* temp = _head;
    Node* prev = nullptr;

    while (temp != nullptr) {
        if (temp->value == value) {
            if (prev == nullptr) {
                _head = temp->next;
            } else {
                prev->next = temp->next;
            }

            delete temp;
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

template <typename T>
void LinkedList<T>::removeAll() {
    while (_head != nullptr) {
        Node* next = _head->next;
        delete _head;
        _head = next;
    }
}

template <typename T>
void LinkedList<T>::printAll(){
    if (_head == nullptr) {
        std::cout << "(List empty, HEAD == nullptr)" << std::endl;
        return;
    }

    uint index = 0;
    Node* temp = _head;

    while (temp != nullptr) {
        std::cout << index << ((index==0) ? " (HEAD)" : "") << ": " << temp->value << std::endl;
        temp = temp->next;
        index++;
    }
}



