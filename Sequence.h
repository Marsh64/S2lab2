template <class T>
class Sequence {
public:
    //Создание объектов
    //Конструкторы будут создаваться прямо там

    //Декомпозиция
    virtual T GetFirst(){};//Получение первого элемента
    virtual T GetLast(){};//Получение последнего элемента
    virtual T Get(int index){};//Получение элемента по индексу
    virtual Sequence<T>* GetSubsequence(int startIndex, int endIndex){};//Получене списка элемента по индексам
    virtual int GetLength(){};//Получение длины последовательности

    //Операции
    virtual void Append(T item){}; //Добавление элемента в конец последовательности
    virtual void Prepend(T item){}; //Добавление элемента в начало последовательности
    virtual void InsertAt(T item, int index){}; //Вставка элемента в заданную позицию последовательности
    virtual Sequence <T>* Concat(Sequence <T> *list){}; //Сцепление двух последовательностей
};

