#ifndef DEQUE_EMPTY_EXCEPTION_H
#define DEQUE_EMPTY_EXCEPTION_H

#include <exception>

class DequeEmptyException : public std::exception {
public:
    virtual const char* what() {
        return "Deque pusta";
    }
};

#endif //DEQUE_EMPTY_EXCEPTION_H
