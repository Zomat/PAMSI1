#ifndef DYNAMICSTRINGARRAY_H
#define DYNAMICSTRINGARRAY_H

#include <iostream>
#include <string>

using namespace std;

class DynamicStringArray {
private:
    string* _array;
    uint _size;
    int _lastElementIndex;
public:
    DynamicStringArray(int size);

    ~DynamicStringArray();

    uint getSize() const;

    string* getArray() const;

    int getLastElementIndex() const;

    void addItem(string item);

    void resizeArray();

    void printArray();
};

#endif //DYNAMICSTRINGARRAY_H
