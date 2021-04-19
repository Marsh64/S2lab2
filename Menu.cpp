#include "Menu.h"

int chooseType(){
    int type;
    cout << "Выберете тип, с которым будете работать: \n"
         << "\t1: int\n"
         << "\t2: float\n"
         << "\t3: complex\n"
         << "Введите число: ";
    cin >> type;

    return type;
}

void menu(){
    ArraySequence<Vector<int>> *intArr;
    ArraySequence<Vector<float>> *floatArr;
    ArraySequence<Vector<complex<int>>> *complexArr;

    int oper;
    while(true){
        cout << "Выберете операцию: \n"
             << "\t1: Ввести и запомнить вектор\n"
             << "\t2: Выполнить операцию над векторами\n"
             << "\t3: Вывести вектор в консоль\n"
             << "\t4: Закончить выполнение программы\n"
             << "Введите число: ";
        cin >> oper;

        if (oper == 4)
            break;

        switch(oper){
            case 1: inputAndSaveVector(intArr, floatArr, complexArr);
            case 2: functionWithVector(intArr, floatArr, complexArr);
            case 3: outputVector(intArr, floatArr, complexArr);
            default: break;
        }
    }
}

void inputAndSaveVector(ArraySequence<Vector<int>> *intArr,
                        ArraySequence<Vector<float>> *floatArr,
                        ArraySequence<Vector<complex<int>>> *complexArr){

    int type = chooseType();
    int count;
    cout << "Введите размерность вектора:";
    cin >> count;

    switch(type){
        case 1: inputVector(intArr, count); break;
        case 2: inputVector(floatArr, count); break;
        case 3: inputVector(complexArr, count); break;
        default: break;
    }
}

template<class T>
void inputVector(ArraySequence<Vector<T>> *Arr, int count){
    cout << "Введите координаты вектора по порядку ";
    ArraySequence<T> n_arr;
    T item;
    for (int i = 0; i < count; i++){
        cin >> item;
        n_arr.Append(item);
    }
    Vector<T> n_vector(n_arr);
    Arr->Append(n_vector);
}

void functionWithVector(ArraySequence<Vector<int>> *intArr,
                        ArraySequence<Vector<float>> *floatArr,
                        ArraySequence<Vector<complex<int>>> *complexArr){

}