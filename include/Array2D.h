#ifndef ARRAY2D_H
#define ARRAY2D_H

#include <iostream>
#include <cstdint>
#include <random>
#include <string>

template <typename T>

class Array2D {
private:
    T **_array;
    uint _rows;
    uint _cols;
public:
    Array2D(uint m, uint n);
    ~Array2D();

    void fillWithRandomValues(uint maxValue);
    void printValues();
    int getMaxValue();
};

#include "Array2D.tpp"

#endif //PROJECT1_ARRAY2D_H
