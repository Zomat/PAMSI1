#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <typename T>
class LinkedList {
private:
    struct Node{
        T value;
        Node* next;
    };
    Node* _head;

public:
    LinkedList();
    ~LinkedList();

    /**
     * Insert new element at head
     * @param value
     */
    void prepend(T value);

    /**
     * Insert new element at end
     * @param value
     */
    void append(T value);

    /**
     * Remove item with given value
     * @param value
     */
    void remove(T value);

    /**
     * Remove all nodes from list
     */
    void removeAll();

    /**
     * Print all nodes in list
     */
    void printAll();
};

#include "LinkedList.tpp"

#endif //LINKEDLIST_H
