#include "DynamicArray.h"
#include <iostream>
using namespace std;

/*
template <class T>
void DynamicArray<T>::Copy_array(T* array_from, T* array_to, int count){
    for (int i = 0; i < count; i++){
        array_to[i] = array_from[i];
    }
}
*/
template <class T>
void DynamicArray<T>::Resize(int newSize){
    if (newSize < 0){throw IndexOutOfRange();}// неправильный размер массива

    if (newSize == 0){
        delete[] array;
        array = nullptr;
        size = 0;
        len = 0;
        return;
    }// удаление массива

    if (newSize == size){return;}// длина не изменится

    if (newSize < size){
        T *new_array = new T[newSize];
        for (int i = 0; i < newSize; i++){
            new_array[i] = array[i];
        }
        delete[] array;
        size = newSize;
        if (len > newSize){len = newSize;}
        array = new_array;
        return;
    }// укорачивание массива

    if (newSize > 0 && size == 0){
        T *new_array = new T[newSize];
        delete[] array;
        size = newSize;
        array = new_array;
    }//увеличение размера массива 0 длины

    if (newSize > size){
        T *new_array = new T[newSize];
        for (int i = 0; i < len; i++){
            new_array[i] = array[i];
        }
        delete[] array;
        size = newSize;
        //len = newSize; //это надо убрать
        array = new_array;
        return;
    }// увеличение длины
}

template <class T>
DynamicArray<T>::DynamicArray() {
    array = nullptr;
    len = 0;
    size = 0;
}

template <class T>
DynamicArray<T>::DynamicArray(T *items, int count) {
    array = nullptr;
    size = 0;
    len = count;

    Resize(count);
    for (int i = 0; i < count; i++){
        array[i] = items[i];
    }
}

template <class T>
DynamicArray<T>::DynamicArray(int newSize){
    if (newSize < 0){newSize = 0;}

    array = nullptr;
    size = 0;
    len = 0;
    Resize(newSize);
}

template <class T>
DynamicArray<T>::DynamicArray(DynamicArray<T> const &dynamicArray) {
    array = nullptr;
    size = 0;
    len = dynamicArray.len;
    Resize(dynamicArray.size);

    for (int i = 0; i < len; i++){
        array[i] = dynamicArray.array[i];
    }
}

template <class T>
T DynamicArray<T>::Get(int index) {
    if (index < 0 || index >= len){throw IndexOutOfRange();}

    return array[index];
}

template <class T>
int DynamicArray<T>::GetSize() {
    return size;
}

template <class T>
int DynamicArray<T>::GetLen() {
    return len;
}

template <class T>
void DynamicArray<T>::Set(int index, T value) {
    if (index < 0 || index>= len){throw IndexOutOfRange();}

    array[index] = value;
}

template <class T>
void DynamicArray<T> :: Delete_DynamicArray(){
    delete[] array;
    array = nullptr;
    size = 0;
    len = 0;
}

template <class T>
DynamicArray<T> :: ~DynamicArray(){
    delete[] array;
    array = nullptr;
    size = 0;
    len = 0;
}


