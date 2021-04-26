#include <iostream>

#ifndef DynamicArray1
#define DynamicArray1

template <class T>
class DynamicArray {
private:
    T* array;
    int len; //длина массива
    int size; //на сколько элементов массив расчитан - кол-во ячеек
public:
    class IndexOutOfRange{};

    //Создание объекта
    DynamicArray(T* items, int count); //создает пустой массив и копирует элементы из переданного массива (получается идентичный по размеру массив)
    explicit DynamicArray(int newSize); //создает пустой массив заданой длины
    DynamicArray(DynamicArray<T> const &dynamicArray); //создание копии исходного масива
    DynamicArray(); //создание пустого массива

    //Удаление объекта
    ~DynamicArray();//деструктор
    void Delete_DynamicArray();//операция удаления массива

    //Декомпозиция
    T& Get(int index);//возвращает элемент по индексу
    int GetSize(); //возвращает длину массива(кол-во всех ячеек)
    int GetLen();//возвращает длину массива (кол-во заполненных ячеек)

    //Операции над параметрами массивов
    void Set(int index, T value); //Задает элемент по индексу
    void Resize(int newSize); //изменяет размерность массива
    void Relen(int newLen); //Изменяет длину массива

    //Перегрузка операторов
    DynamicArray<T> &operator = (DynamicArray<T> dynamicArray) {
        Resize(dynamicArray.GetSize());
        size = dynamicArray.GetSize();
        len = dynamicArray.GetLen();
        for (int i = 0; i < len; i++){
            array[i] = dynamicArray.array[i];
        }
        return *this;
    }
};

#endif