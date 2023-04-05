#include <iostream>
#include <string>
#include "include/Palindrom.h"
#include "include/DynamicStringArray.h"

using namespace std;

DynamicStringArray* palList = new DynamicStringArray(1);

void permute(string a, int l, int r, DynamicStringArray *arr) {
    if (l == r) {
        if (jestPal(a)) {
            arr->addItem(a);
        }
    } else {
        for (int i = l; i <= r; i++) {
            swap(a[l], a[i]);
            permute(a, l+1, r, arr);
            swap(a[l], a[i]);
        }
    }
}

void usunDup(DynamicStringArray &arr) {
    DynamicStringArray* newArr = new DynamicStringArray(1);
    bool isDuplicate;

    for (int i = 0; i < arr.getSize(); i++) {
        isDuplicate = false;
        for (int j = 0; j < i; j++) {
            if (arr.getArray()[i] == arr.getArray()[j]) {
                isDuplicate = true;
                break;
            }
        }

        if (!isDuplicate) {
            newArr->addItem(arr.getArray()[i]);
        }
    }

    delete &arr;

    arr = *newArr;
}

int main() {
    string str = "kajak";
    int n = str.size();
    permute(str, 0, n-1, palList);
    palList->printArray();
    usunDup(*palList);
    cout << " === USUWANIE DUPLIKATOW ===" <<  endl;
    palList->printArray();

    return 0;
}
