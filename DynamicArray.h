#include <iostream>

template <class T>
class DynamicArray {
private:
    T* array;
    int len; //длина массива
    int size; //на сколько элементов массив расчитан
    const size_t element_size = sizeof(T);
public:
    class IndexOutOfRange{};

    //Создание объекта
    DynamicArray(T* items, int count); //создает пустой массив и копирует элементы из переданного массива (получается идентичный по размеру массив)
    explicit DynamicArray(int newSize); //создает пустой массив заданой длины
    DynamicArray(const DynamicArray<T> & dynamicArray); //создание пустого массива и копирование элементов из исходного в него

    //Декомпозиция
    T Get(int index);//возвращает элемент по индексу
    int GetSize(); //возвращает длину массива(кол-во всех ячеек)
    int GetLen();//возвращает длину массива (кол-во заполненных ячеек)

    //Операции
    void Set(int index, T value); //Задает элемент по индексу
    void Resize(int newSize); //изменяет размер массива

    //void Copy_array(T* array_from, T* array_to, int count);
};

