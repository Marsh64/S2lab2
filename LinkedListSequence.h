#include "Sequence.h"
#include "LinkedList.h"

#ifndef LinkedListSequence

template <class T>
class LinkedListSequence : Sequence<T>{
private:
    LinkedList<T> listSequence;
public:
    class IndexOutOfRange : LinkedList<T>::IndexOutOfRange{};

    //Создание объекта
    LinkedListSequence (T* items, int count){
        listSequence = LinkedList<T>(items, count);
    }//Копирует элемнеты из переданного массива
    LinkedListSequence (){
        listSequence = LinkedList<T>();
    }//Создает пустую последовательность
    explicit LinkedListSequence (const LinkedList <T> & list){
        listSequence = LinkedList<T>(list);
    }//Копирующий конструктор

    //Декомпозиция
    T GetFirst(){
        return listSequence.GetFirst();
    }//Возвращает первый элемент
    T GetLast(){
        return listSequence.GetLast();
    }//Возвращает последний элемент
    T Get(int index){
        return listSequence.Get(index);
    }//Возвращает элемент по индексу
    LinkedListSequence<T>* GetSubsequence(int startIndex, int endIndex){
        auto *new_LinkedList = new LinkedList<T>;
        new_LinkedList = listSequence.GetSubList(startIndex, endIndex);
        return new_LinkedList;
    }//Получить список из всех элементов, начиная с startIndex и заканчивая endIndex
    int GetLength(){
        return listSequence.GetLength();
    }

    //Операции
    void Append(T item){
        listSequence.Append(item);
    }//Добавляет элемент в конец списка
    void Prepend(T item){
        listSequence.Prepend(item);
    }//Добавляет элемент в начало списка
    void InsertAt(T item, int index){
        listSequence.InsertAt(item, index);
    }//Вставляет элемент в заданную позицию
    LinkedListSequence<T>* Concat(LinkedListSequence<T> *list){
        auto *new_LinkedList = new LinkedListSequence<T>;
        new_LinkedList->listSequence = listSequence.Concat(list->listSequence);
        return new_LinkedList;
    }//Сцепляет два списка
};

#endif