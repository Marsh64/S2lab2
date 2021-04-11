#include "AllTests.h"
#include <cassert>
#include "iostream"
#include "DynamicArray.h"
#include "DynamicArray.cpp"
#include "LinkedList.h"
//#include "LinkedList.cpp"

void constructor_1_DA(){
    int arr[] = {1, 2, 3, 4, 5};
    DynamicArray<int> d(arr, 5);
    assert(d.GetLen() == 5);
    assert(d.GetSize() == 5);
    assert(d.Get(3) == 4);
    d.Resize(8);
    assert(d.GetSize() == 8);
    assert(d.GetLen() == 5);
    d.Set(3, 10);
    assert(d.Get(3) == 10);
    d.Resize(0);
    assert(d.GetLen() == 0);
    assert(d.GetSize() == 0);
    d.Delete_DynamicArray();
}
void constructor_2_DA(){
    DynamicArray<int> arr(10);
    assert(arr.GetSize() == 10);
    assert(arr.GetLen() == 0);
    arr.Delete_DynamicArray();
}
void constructor_3_DA(){
    int arr[] = {1, 2, 3, 4, 5};
    DynamicArray<int> d(arr, 5);
    DynamicArray<int> b(d);
    assert(b.GetSize() == 5);
    assert(b.Get(2) == 3);
    assert(b.Get(1) == 2);
    d.Delete_DynamicArray();
    b.Delete_DynamicArray();
}
void constructor_4_DA(){
    DynamicArray<int> arr;
    assert(arr.GetSize() == 0);
    assert(arr.GetLen() == 0);
    arr.Delete_DynamicArray();
}
void Get_DA(){
    int arr[] = {1, 2, 3, 4, 5};
    DynamicArray<int> d(arr, 5);
    assert(d.Get(3) == 4);
    assert(d.Get(4) == 5);
    assert(d.Get(0) == 1);
    d.Delete_DynamicArray();
}
void GetSize_DA(){
    int arr[] = {1, 2, 3, 4, 5};
    DynamicArray<int> d(arr, 5);
    assert(d.GetSize() == 5);
    d.Delete_DynamicArray();
}
void GetLen_DA(){
    int arr[] = {1, 2, 3, 4, 5};
    DynamicArray<int> d(arr, 5);
    assert(d.GetLen() == 5);
    d.Delete_DynamicArray();
}
void Set_DA(){
    int arr[] = {1, 2, 3, 4, 5};
    DynamicArray<int> d(arr, 5);
    d.Set(3, 100);
    assert(d.Get(3) == 100);
    assert(d.Get(2) == 3);
    d.Delete_DynamicArray();
}
void Resize_DA(){
    int arr[] = {1, 2, 3, 4, 5};
    DynamicArray<int> d(arr, 5);
    assert(d.GetSize() == 5);
    d.Resize(10);
    assert(d.GetSize() == 10);
    assert(d.GetLen() == 5);
    d.Delete_DynamicArray();
}

/*
void constructor_1_LL(){
    float arr[] = {5.5, 6.6, -7.8, -9.9, 0};
    LinkedList<float> list(arr, 5);
    assert(list.GetLength() == 5);
    assert(list.Get(2) == 6.6);
    cout << "1" << endl;
}
*/



void AllTests(){
    constructor_1_DA();
    constructor_2_DA();
    constructor_3_DA();
    constructor_4_DA();
    Get_DA();
    GetSize_DA();
    GetLen_DA();
    Set_DA();
    Resize_DA();
    cout << "с DynamicArray все хорошо" << endl;

    //constructor_1_LL();


}