#include "Base/DynamicArray.cpp"
#include "Sequence/ArraySequence.cpp"
#include <iostream>
//#include "LinkedListSequence.h"
//#include "ArraySequence.h"
//#include "DynamicArray.hpp"
//#include "AllTests.cpp"
#include "Base/LinkedList.cpp"
#include "Tests/Tests_DA and LL.h"
#include "Vector.h"
#include "Matrix.h"
#include "MenuAll.h"
#include "Tests/Tests_AS and LLS.h"
using namespace std;

/*
ostream &operator << (ostream &cout, complex<float> num) {
    cout << num.real();
    if (num.imag() == 0) return cout;

    if (num.imag() < 0) {
        cout << num.imag();
    }
    else {
        cout << '+' << num.imag();
    }

    return cout << 'i';
}
*/

int main() {
    Tests_DA_LL();

    constructors_AS();
    decomposition_AS();
    function_AS();
    constructors_LLS();
    decomposition_LLS();
    function_LLS();

    menuAll();

    /*
    ArraySequence<Vector<int>> sequence;

    int arr1[] = {1, 2, 3};
    Vector<int> vector(arr1, 3);

    sequence.Append(vector);
    cout << vector << ' ' << sequence.Get(0) << endl;
    /*
    int arr2[] = {2, 3, 4};
    int arr3[] = {3, 4, 5};
    int *arr[] = {arr1, arr2, arr3};

    Matrix<int> mat1;
    Matrix<int> mat2(arr, 3);
    Matrix<int> mat3(mat2);
    Matrix<int> mat4(mat2.MultOfMatrix(3));

    cout << mat2 << endl;
    mat2.ElemTransformOfLines(0, 1, 2);
    cout << mat2 << endl;
    /*
    cout << mat1.GetSize() << endl;
    cout << mat2.GetSize() << endl;
    cout << mat4.GetSize() << endl;
    cout << mat2.Get(2, 1) << endl;
    cout << mat4.Get(2, 1) << endl;
    */



    /*
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {2, 3, 4, 5, 6};
    complex<float> k1(4, 5);
    complex<float> k2(6, 8);
    cout << k1 + k1 << endl << k1 - k2 << endl << k1 * k2 << endl << k1 / k2 << endl;
    //DynamicArray<int> da1(arr1, 5);
    //DynamicArray<int> da2(arr2, 5);
    //ArraySequence<int> as1(arr1, 5);
    //ArraySequence<int> as2(arr2, 5);
    //cout << as2.GetLength() << endl;
    //as2.Append(5);
    //cout << as2.GetLength() << endl;
    //cout << as2.Get(5) << endl;
    //DynamicArray<int> da3;

    Vector<int> vec1(arr1, 5);
    Vector<int> vec2(arr2, 5);

    //Vector<int> vector3;

    Vector<int> vec3(vec1.SubOfVectors(vec2));
    Vector<int> vec4(vec1.SumOfVectors(vec2));
    Vector<int> vec5(vec1.MulOfVectors(5));


    cout << vec1.GetCoord(2) << endl;
    cout << vec1 << endl;
    cout << vec2 << endl;
    cout << vec3 << endl;
    cout << vec4 << endl;
    cout << vec5 << endl;
    cout << vec1.ScalarMulOfVectors(vec2) << endl;

    /*
    float arr[] = {5.5, 6.6, -7.8, -9.9, 0};
    LinkedList<float> list;
    cout << list.GetLength() << endl;
    LinkedList<float> list1(arr, 5);
    cout << list1.GetLength() << endl;
    cout << list1.Get(2) << endl;
    */
    cout << "Hello, World!" << endl;
    return 0;
}
