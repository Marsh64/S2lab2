#ifndef LABORATORY_WORK_2_MENU_H
#define LABORATORY_WORK_2_MENU_H
#include <iostream>
#include "Vector.h"
#include <complex>

using namespace std;

int chooseType();

void menu();
//1
void inputAndSaveVector(ArraySequence<Vector<int>> *intArr,
                        ArraySequence<Vector<float>> *floatArr,
                        ArraySequence<Vector<complex<int>>> *complexArr);
template <class T>
void inputVector(ArraySequence<Vector<T>> *Arr, int count);
//2
void functionWithVector(ArraySequence<Vector<int>> *intArr,
                         ArraySequence<Vector<float>> *floatArr,
                         ArraySequence<Vector<complex<int>>> *complexArr);


//3
void outputVector(ArraySequence<Vector<int>> *intArr,
                  ArraySequence<Vector<float>> *floatArr,
                  ArraySequence<Vector<complex<int>>> *complexArr);















#endif //LABORATORY_WORK_2_MENU_H
