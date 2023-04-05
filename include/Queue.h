#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

template <typename T>
class Queue{
private:
    struct Node {
        T value;
        Node* next;
    };
    Node* _head;
    Node* _tail;

public:
    Queue();
    ~Queue();

    /**
     * Add element to the back (tail)
     * @param value
     */
    void enqueue(T value);

    /**
     * Remove and return head element
     * @return T
     */
    T dequeue();

    /**
     * Print all elements in queue
     */
    void printAll();

    /**
     * Remove all elements from queue
     */
    void removeAll();
};

#include "Queue.tpp"

#endif //QUEUE_H
