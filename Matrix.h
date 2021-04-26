#include "Sequence/ArraySequence.h"

#ifndef LABORATORY_WORK_2_MATRIX_H
#define LABORATORY_WORK_2_MATRIX_H

template <class T>
class Matrix {
private:
    ArraySequence<ArraySequence<T>> matrix;
    int size = 0;
public:
    //Создание объекта
    Matrix(){
        ArraySequence<ArraySequence<T>> new_matrix;
        matrix = new_matrix;
        size = 0;
    }//Создание пустой матрицы
    Matrix(T** items, int count){
        for (int i = 0; i < count; i++) {
            ArraySequence<T> element;
            for (int j = 0; j < count; j++) {
                element.Append(items[i][j]);
            }
            matrix.Append(element);
        }
        size = count;
    }//Создание матрицы по массиву
    explicit Matrix(const ArraySequence<ArraySequence<T>> &n_matrix){
        int count = n_matrix.dynamicArray.GetLen();
        for (int i = 0; i < count; i++){
            ArraySequence<T> element;
            for (int j = 0; j < count; j++){
                element.Append(n_matrix.dynamicArray.Get(i).Get(j));
            }
            matrix.Append(element);
            size = n_matrix.dynamicArray.GetLen();
        }
        //matrix = n_matrix;
    }//Копирование исходной матрицы

    //Удаление объекта
    ~Matrix(){
        for (int i = 0; i < size; i++){
            matrix.Get(i).Delete_ArraySequence();
        }
        matrix.Delete_ArraySequence();
        size = 0;
    }//деконструктор
    void Delete_Matrix(){
        for (int i = 0; i < size; i++){
            matrix.Get(i).Delete_ArraySequence();
        }
        matrix.Delete_ArraySequence();
        size = 0;
    }//функция удаления

    //Декомпозиция
    T Get(int line, int column){
       return matrix.Get(line).Get(column);
    }
    int GetSize(){
        return size;
    }

    //Операции
    Matrix<T> SumOfMatrix(Matrix<T> &b_matrix){
        Matrix<T> new_matrix;
        for (int i = 0; i < size; i++){
            ArraySequence<T> element;
            for (int j = 0; j < size; j++) {
                element.Append(matrix.Get(i).Get(j) + b_matrix.matrix.Get(i).Get(j));
            }
            new_matrix.matrix.Append(element);
        }
        new_matrix.size = size;
        return new_matrix;
    }//сумма матриц
    Matrix<T> SubOfMatrix(Matrix<T> &b_matrix){
        Matrix<T> new_matrix;
        for (int i = 0; i < size; i++){
            ArraySequence<T> element;
            for (int j = 0; j < size; j++) {
                element.Append(matrix.Get(i).Get(j) - b_matrix.matrix.Get(i).Get(j));
            }
            new_matrix.matrix.Append(element);
        }
        new_matrix.size = size;
        return new_matrix;
    }//разность матриц
    Matrix<T> MultOfMatrix(T scalar){
        Matrix<T> new_matrix;
        for (int i = 0; i < size; i++){
            ArraySequence<T> element;
            for (int j = 0; j < size; j++) {
                element.Append(matrix.Get(i).Get(j) * scalar);
            }
            new_matrix.matrix.Append(element);
        }
        new_matrix.size = size;
        return new_matrix;
    }//Умножение на скаляр
    T NormOfMatrix(){}//TODO доделать
    void ElemTransformOfColumns(int column1, int column2, T scalar){
        Matrix<T> new_matrix;
        for (int i = 0; i < size; i++){
            ArraySequence<T> element;
            if (i == column1){
                for (int j = 0; j < size; j++){
                    element.Append(matrix.Get(column2).Get(j) * scalar + matrix.Get(column1).Get(j));
                };
            }else{
                for (int j = 0; j < size; j++) {
                    element.Append(matrix.Get(i).Get(j));
                }
            }
            new_matrix.matrix.Append(element);
        }
        new_matrix.size = size;
        matrix = new_matrix.matrix;
    }
    void ElemTransformOfLines(int line1, int line2, T scalar){
        Matrix<T> new_matrix;
        for (int i = 0; i < size; i++){
            ArraySequence<T> element;
            for (int j = 0; j < size; j++) {
                if (j == line1){
                    element.Append(matrix.Get(i).Get(line2) * scalar + matrix.Get(i).Get(line1));
                }else{
                    element.Append(matrix.Get(i).Get(j));
                }
            }
            new_matrix.matrix.Append(element);
        }
        new_matrix.size = size;
        matrix = new_matrix.matrix;
    }


    //Перегрузка опреаторов
    Matrix<T> &operator = (Matrix<T> n_matrix){
        matrix = n_matrix.matrix;
        size = n_matrix.size;
        return *this;
    }
    friend std::ostream &operator << (std::ostream &cout, Matrix<T> &n_matrix) {
        for (int j = 0; j < n_matrix.GetSize(); j++){ // по строкам
            for (int i = 0; i < n_matrix.GetSize(); i++){
                cout << n_matrix.Get(j, i) << "   ";
            }
            cout << std::endl;
        }
        cout << std::endl;

        return cout;
    }

};


#endif //LABORATORY_WORK_2_MATRIX_H
