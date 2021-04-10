#include <iostream>

#ifndef DynamicArray1
#define DynamicArray1

template <class T>
class DynamicArray {
private:
    T* array;
    int len; //длина массива
    int size; //на сколько элементов массив расчитан
    //const size_t element_size = sizeof(T);
public:
    class IndexOutOfRange{};

    //Создание объекта
    DynamicArray(T* items, int count); //создает пустой массив и копирует элементы из переданного массива (получается идентичный по размеру массив)
    explicit DynamicArray(int newSize); //создает пустой массив заданой длины
    DynamicArray(DynamicArray<T> const &dynamicArray); //создание пустого массива и копирование элементов из исходного в него
    DynamicArray(); //создание пустого массива

    //Удаление объекта
    ~DynamicArray();
    void Delete_DynamicArray();

    //Декомпозиция
    T Get(int index);//возвращает элемент по индексу
    int GetSize(); //возвращает длину массива(кол-во всех ячеек)
    int GetLen();//возвращает длину массива (кол-во заполненных ячеек)

    //Операции
    void Set(int index, T value); //Задает элемент по индексу
    void Resize(int newSize); //изменяет размер массива

    DynamicArray<T> &operator = (DynamicArray<T> dynamicArray) {
        Resize(dynamicArray.GetLen());
        size = dynamicArray.GetSize();
        len = dynamicArray.GetLen();
        for (int i = 0; i < len; i++){
            array[i] = dynamicArray.array[i];
        }
        return *this;
    }/**/
    //void Copy_array(T* array_from, T* array_to, int count);
};

#endif