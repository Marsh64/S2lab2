#include "ArraySequence.h"
#include <cmath>


#ifndef LABORATORY_WORK_2_VECTOR_H
#define LABORATORY_WORK_2_VECTOR_H

template<class T>
class Vector {
private:
    ArraySequence<T> vector;
public:
    //Создание объекта
    Vector(){
        ArraySequence<T> new_vector;
        vector = new_vector;
    }//создание пустого вектора
    Vector(T* coords, int count){
        ArraySequence<T> new_vector(coords, count);
        vector = new_vector;
    }// создание вектора по массиву
    explicit Vector(ArraySequence<T> &n_vector){
        vector = n_vector;
    }//копирующий конструктор

    //Удаление объекта
    ~Vector(){
        vector.Delete_ArraySequence();
    }
    void Delete_Vector(){
        vector.Delete_ArraySequence();
    }

    //Декомпозиция
    T GetCoord(int index){
        return vector.Get(index);
    }
    int GetVectorLen(){
        return vector.GetLength();
    }

    //Операции
    Vector<T> SumOfVectors(Vector<T> &b){
        Vector<T> new_vector;
        for(int i = 0; i < vector.GetLength(); i++){
            new_vector.vector.Append(this->vector.Get(i) + b.vector.Get(i));
        }
        return new_vector;
    }
    Vector<T> SubOfVectors(Vector<T> &b){
        Vector<T> new_vector;
        for(int i = 0; i < vector.GetLength(); i++){
            new_vector.vector.Append(this->vector.Get(i) - b.vector.Get(i));
        }
        return new_vector;
    }
    Vector<T> MulOfVectors(T scalar){
        Vector<T> new_vector;
        for(int i = 0; i < vector.GetLength(); i++){
            new_vector.vector.Append(this->vector.Get(i) * scalar);
        }
        return new_vector;
    }
    Vector<T> Normalization(){
        T len = 0;
        for (int i = 0; i < vector.GetLength(); i++){
            len = len + vector.Get(i) * vector.Get(i);
        }
        //нужно сделать еще модуль len для комплексных чисел
        len = sqrt(len);
        Vector<T> new_vector;
        for(int i = 0; i < vector.GetLength(); i++){
            new_vector.vector.Append(this->vector.Get(i)/ len);
        }
        //деление сделать нормальное
        return new_vector;
    }
    T ScalarMulOfVectors(Vector<T> &b){
        T scalar = vector.Get(0) * b.vector.Get(0);
        for (int i = 1; i < vector.GetLength(); i++){
            scalar = scalar + vector.Get(i) * b.vector.Get(i);
        }

        return scalar;
    }

    //Перегрузка операторов
    friend std::ostream &operator << (std::ostream &cout, Vector<T> &n_vector) {
        cout << '{';
        for (int i = 0; i < n_vector.GetVectorLen(); i++) {
            cout << n_vector.GetCoord(i);
            if (i != n_vector.GetVectorLen() - 1) {
                cout << ", ";
            }
        }
        cout << '}';
        return cout;
    }



};


#endif //LABORATORY_WORK_2_VECTOR_H
