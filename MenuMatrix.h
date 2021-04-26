#ifndef LABORATORY_WORK_2_MENUMATRIX_H
#define LABORATORY_WORK_2_MENUMATRIX_H
#include "Matrix.h"
#include <complex>
#include <iostream>

using namespace std;

int chooseTypeMatrix();
int chooseFunctionMatrix();
void menuMatrix();

//1
void inputAndSaveMatrix(ArraySequence<Matrix<int>> *intArr,
                        ArraySequence<Matrix<float>> *floatArr,
                        ArraySequence<Matrix<complex<int>>> *complexArr);
template <class T>
void inputMatrixTyped(ArraySequence<Matrix<T>> *Arr, int count);
//2
void functionWithMatrix(ArraySequence<Matrix<int>> *intArr,
                        ArraySequence<Matrix<float>> *floatArr,
                        ArraySequence<Matrix<complex<int>>> *complexArr);
template<class T>
void functionMatrixTyped(ArraySequence<Matrix<T>> *Arr);
//3
void outputMatrix(ArraySequence<Matrix<int>> *intArr,
                        ArraySequence<Matrix<float>> *floatArr,
                        ArraySequence<Matrix<complex<int>>> *complexArr);
template<class T>
void outputTypedMatrix(ArraySequence<Matrix<T>> *Arr, int index);


#endif //LABORATORY_WORK_2_MENUMATRIX_H
