#include "DynamicStringArray.h"

DynamicStringArray::DynamicStringArray(int size) {
    if (size < 0) {
        _size = 1;
    } else {
        _size = size;
    }

    _array = new string[_size];
    _lastElementIndex = -1;
}

DynamicStringArray::~DynamicStringArray() {
    delete[] _array;
}

uint DynamicStringArray::getSize() const {
    return _size;
}

string* DynamicStringArray::getArray() const {
    return _array;
}

int DynamicStringArray::getLastElementIndex() const {
    return _lastElementIndex;
}

void DynamicStringArray::addItem(string item) {
    if (_lastElementIndex >= _size) {
        resizeArray();
    }

    _array[++_lastElementIndex] = item;
}

void DynamicStringArray::resizeArray() {
    string* newArray = new string[_size*2];

    for (int i = 0; i <= _lastElementIndex; i++) {
        newArray[i] = _array[i];
    }

    delete[] _array;
    _array = newArray;
    _size *= 2;
}

void DynamicStringArray::printArray() {
    cout << "Size: " << _size << endl;
    for (int i = 0; i <= _lastElementIndex; i++) {
        cout << _array[i] << endl;
    }
}