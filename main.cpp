#include "DynamicArray.cpp"
//#include "ArraySequence.cpp"
#include <iostream>
#include "LinkedListSequence.h"
#include "ArraySequence.h"
//#include "DynamicArray.hpp"

//#include "AllTests.cpp"

#include "AllTests.h"
using namespace std;

int main() {
    AllTests();
    //проверка DynamicArray
    int arr[] = {1, 2, 3, 4, 5};
    DynamicArray<int> ka(arr, 5);
    DynamicArray<float> a(10);
    cout << a.GetLen() << endl;
    //cout << a.Get(5) << endl;
    cout << ka.Get(2) << endl;

    cout << "Hello, World!" << endl;
    return 0;
}
