#include "Array2D.h"

template <typename T>
Array2D<T>::Array2D(uint m, uint n) {
    _rows = m;
    _cols = n;

    _array = new T*[_rows];

    for (uint i=0; i < _rows; i++) {
        _array[i] = new T[_cols];
    }
}

template <typename T>
Array2D<T>::~Array2D() {
    for (uint i=0; i < _rows; i++) {
        delete[] _array[i];
    }

    delete[] _array;
}

template <typename T>
void Array2D<T>::fillWithRandomValues(uint maxValue) {
    srand(time(0));
    for (uint i=0; i < _rows; i++) {
        for (uint j=0; j < _cols; j++) {
            _array[i][j] = (T)(rand() % (maxValue + 1));
        }
    }
}

template <typename T>
void Array2D<T>::printValues() {
    for (uint i=0; i < _rows; i++) {
        for (uint j=0; j < _cols; j++) {
            std::cout << "[" << i << "][" << j << "] = " << _array[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

template <typename T>
int Array2D<T>::getMaxValue() {
    int maxValue;
    for (uint i=0; i < _rows; i++) {
        for (uint j=0; j < _cols; j++) {
            if (maxValue < _array[i][j]) {
                maxValue = _array[i][j];
            }
        }
    }

    return maxValue;
}