#include "Sequence.h"
#include "DynamicArray.h"

template <class T>
class ArraySequence : Sequence<T>{
private:
    DynamicArray<T> arraySequence;
public:
    class IndexOutOfRange : DynamicArray<T> :: IndexOutOfRange{};

    //Создание объекта
    ArraySequence (T* items, int count){
        arraySequence = DynamicArray<T>(items, count);
    }//Создает последовательность с элементами из исходного массива
    ArraySequence (){
        arraySequence = DynamicArray<T>(0);
    }//Создает пустую последовательность
    explicit ArraySequence (const DynamicArray<T> & dynamicArray){
        arraySequence = DynamicArray<T>(dynamicArray);
    }//Копирующий конструктор

    //Декомпозиция
    T GetFirst(){
        return arraySequence.Get(0);
    }//Возвращает первй элемент
    T GetLast(){
        return arraySequence.Get(arraySequence.GetLen() - 1);
    }//Возвращает последний элемент
    T Get(int index){
        return arraySequence.Get(index);
    }//Возвращает элемент по индексу
    ArraySequence<T>* GetSubsequence(int startIndex, int endIndex){
        if (startIndex >= arraySequence.GetLen() || endIndex >= arraySequence.GetLen()|| startIndex < 0 || endIndex < 0){
            throw IndexOutOfRange();
        }

        auto *new_arraySequence = new ArraySequence<T>;
        new_arraySequence = ArraySequence<T>();
        int iter;
        if (startIndex < endIndex){
            iter = 1;
        }else{
            iter = -1;
        }

        for (int i = startIndex; i != endIndex; i += iter){
            new_arraySequence->Append(arraySequence.Get(i));
        }

        return new_arraySequence;
    }//Получить список из всех элементов, начиная с startIndex и заканчивая endIndex
    int GetLength(){
        return arraySequence.GetLen();
    }//Возвращает длину последовательности

    //Операции
    void Append(T item){
        arraySequence.Resize(arraySequence.GetLen() + 1);
        arraySequence.Set(arraySequence.GetLen() - 1, item);
    }//дабавляет элемент в конец последовательности
    void Prepend(T item){
        arraySequence.Resize(arraySequence.GetLen() + 1);
        T saved_cell = arraySequence.Get(0);
        T this_cell;
        arraySequence.Set(0,item);

        for(int i = 1; i < arraySequence.GetLen(); i++){
            this_cell = arraySequence.Get(i);
            arraySequence.Set(i, saved_cell);
            saved_cell = this_cell;
        }
    }//Добавляет элемент в начало строки
    void InsertAt(T item, int index){
        if (index < 0 || index >= arraySequence.GetLen()){throw IndexOutOfRange();}

        arraySequence.Resize(arraySequence.GetLen() + 1);
        T this_cell;
        T saved_cell = arraySequence.Get(index);
        arraySequence.Set(index, item);
        for (int i = index + 1; i < arraySequence.GetLen(); i++){
            this_cell = arraySequence.Get(i);
            arraySequence.Set(i, saved_cell);
            saved_cell = this_cell;
        }
    }//Вставляет элемент по заданному индексу
    ArraySequence<T>* Concat(ArraySequence<T> *list){
        auto *new_arraySequence = new ArraySequence<T>;
        new_arraySequence = ArraySequence<T>();

        for (int i = 0; i < arraySequence.GetLen(); i++){
            new_arraySequence->Append(arraySequence.Get(i));
        }
        for (int i = 0; i < list->GetLength(); i++){
            new_arraySequence->Append(list->Get(i));
        }

        return new_arraySequence;
    }//Сцепляет две последовательности
};

