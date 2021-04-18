#ifndef LABORATORY_WORK_2_MATRIX_H
#define LABORATORY_WORK_2_MATRIX_H

#include "ArraySequence.h"

template <class T>
class Matrix {
private:
    ArraySequence<ArraySequence<T>> matrix;
    int size;
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
            size = count;
        }
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
        //matrix = n_matrix
    }//Копирование исходной матрицы

    //Удаление объекта
    ~Matrix(){
        matrix.Delete_ArraySequence();
        size = 0;
    }//деконструктор
    void Delete_Matrix(){
        matrix.Delete_ArraySequence();
        size = 0;
    }//процедура удаления

    //Декомпозиция
    T Get(int column, int line){
       return matrix.Get(column).Get(line);
    }
    int GetSize(){
        return size;
    }

    //Операции
    Matrix<T> SumOfMatrix(const Matrix<T> &b_matrix){
        Matrix<T> new_matrix;
        for (int i = 0; i < size; i++){
            ArraySequence<T> element;
            for (int j = 0; j < size; j++) {
                element.Append(matrix.Get(i)[j] + b_matrix.matrix.Get(i)[j]);
            }
            new_matrix.matrix.Append(element);
        }
        return new_matrix;
    }//сумма матриц
    Matrix<T> SubOfMatrix(const Matrix<T> &b_matrix){
        Matrix<T> new_matrix;
        for (int i = 0; i < size; i++){
            ArraySequence<T> element;
            for (int j = 0; j < size; j++) {
                element.Append(matrix.Get(i)[j] - b_matrix.matrix.Get(i)[j]);
            }
            new_matrix.matrix.Append(element);
        }
        return new_matrix;
    }//разность матриц
    Matrix<T> MultOfMatrix(T scalar){
        Matrix<T> new_matrix;
        for (int i = 0; i < size; i++){
            ArraySequence<T> element;
            for (int j = 0; j < size; j++) {
                element.Append(matrix.Get(i)[j] * scalar);
            }
            new_matrix.matrix.Append(element);
        }
        return new_matrix;
    }//Умножение на скаляр
    void ElemTransformOfColumns(int column1, int column2, T scalar){
        Matrix<T> new_matrix;
        for (int i = 0; i < size; i++){
            ArraySequence<T> element;
            if (i == column1){
                for (int j = 0; j < size; j++){
                    element.Append(matrix.Get(column2)[j] * scalar + matrix.Get(column1)[j]);
                };
            }else{
                for (int j = 0; j < size; j++) {
                    element.Append(matrix.Get(i)[j]);
                }
            }
            new_matrix.matrix.Append(element);
        }

        matrix = new_matrix;
    }
    void ElemTransformOfLines(int line1, int line2, T scalar){
        Matrix<T> new_matrix;
        for (int i = 0; i < size; i++){
            ArraySequence<T> element;
            for (int j = 0; j < size; j++) {
                if (j == line1){
                    element.Append(matrix.Get(line2).Get(j) * scalar + matrix.Get(line1).Get(j));
                }else{
                    element.Append(matrix.Get(i).Get(j));
                }
            }
            new_matrix.matrix.Append(element);
        }

        matrix = new_matrix;
    }


    //Перегрузка опреаторов
    Matrix<T> &operator = (Matrix<T> n_matrix){
        matrix = n_matrix;
    }
    friend std::ostream &operator << (std::ostream &cout, Matrix<T> &n_matrix) {
        for (int j = 0; j < n_matrix.GetSize(); j++){ // по строкам
            for (int i = 0; i < n_matrix.GetSize(); i++){
                cout << n_matrix.Get(i, j) << "   ";
            }
            cout << std::endl;
        }
        cout << std::endl;

        return cout;
    }

};


#endif //LABORATORY_WORK_2_MATRIX_H
