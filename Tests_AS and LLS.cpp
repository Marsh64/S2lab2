/*
#include "Tests_AS and LS.h"
#include <cassert>
#include "iostream"
#include "ArraySequence.h"
#include "ArraySequence.cpp"
#include "LinkedListSequence.h"
#include "LinkedListSequence.cpp"

float round_float(float a, int order){
    for (int i = 0; i < order; i++){
        a = a * 10;
    }
    a = (float)(int)a / 10;
    for (int i = 0; i < order - 1; i++){
        a = a / 10;
    }
    return a;
}


//end code_LL_cpp
/*
//it is new code_AS_h
void constructor_1_AS(){
   int arr[] = {2, 4, 5, 6, 7};
   ArraySequence<int> seq(arr, 5);
   assert(seq.GetLength() == 5);
   assert(seq.Get(4) == 7);
}
void constructor_2_AS(){
   ArraySequence<int> seq;
   assert(seq.GetLength == 0);
}
void constructor_3_AS(){
   int arr[] = {1, 2, 3, 4, 5};
   DynamicArray<int> d(arr, 5);
   ArraySequence<int> seq (d);
   assert(seq.GetLength == 5);
   assert(seq.Get(2) == d.Get(2));
}
void GetFirst_AS(){
   int arr[] = {2, 4, 5, 6, 7};
   ArraySequence<int> seq(arr, 5);
   assert(arr.GetFirst() == 2);
}
void GetLast_AS(){
   int arr[] = {2, 4, 5, 6, 7};
   ArraySequence<int> seq(arr, 5);
   assert(arr.GetFirst() == 7);
}
void Get_AS(){
   int arr[] = {2, 4, 5, 6, 7};
   ArraySequence<int> seq(arr, 5);
   assert(seq.Get(3) == 6);
   assert(seq.Get(2) == 5);
   assert(seq.Get(0) == 2);
}
void GetSubsequence_AS(){
   int arr[] = {2, 4, 5, 6, 7};
   ArraySequence<int> seq1(arr, 5);
   ArraySequence<int> seq2(seq1.GetSubsequence(2, 4));
   assert(seq2.Get(0) == 5);
   assert(seq2.Get(1) == 6);
   assert(seq2.Get(2) == 7);
   ArraySequence<int> seq3(seq1.GetSubsequence(4, 2));
   assert(seq2.Get(2) == 5);
   assert(seq2.Get(1) == 6);
   assert(seq2.Get(0) == 7);
}
void GetLength_AS(){
   int arr[] = {2, 4, 5, 6, 7};
   ArraySequence<int> seq1(arr, 5);
   assert(seq1.GetLength() == 5);
}
void Append_AS(){
   int arr[] = {2, 4, 5, 6, 7};
   ArraySequence<int> seq1(arr, 5);
   seq1.Append(8);
   assert(seq1.GetLength == 6);
   assert(seq1.Get(5) == 8);
}
void Prepend_AS(){
   int arr[] = {2, 4, 5, 6, 7};
   ArraySequence<int> seq1(arr, 5);
   seq1.Prepend(1);
   assert(seq1.GetLength == 6);
   assert(seq1.Get(0) == 1);
}
void InsertAt_AS(){
   int arr[] = {2, 4, 5, 6, 7};
   ArraySequence<int> seq1(arr, 5);
   seq1.InsertAt(5, 3);
   assert(seq1.GetLength == 6);
   assert(seq1.Get(3) == 5);
   assert(seq1.Get(2) == 5);
   assert(seq1.Get(4) == 6);
}


void Delete_ArraySequence(){
   ArraySequence.Delete_DynamicArray();
}
//end

/*
void constructor_1_LL(){
   float arr[] = {5.5, 6.6, -7.8, -9.9, 0};
   LinkedList<float> list(arr, 5);
   assert(list.GetLength() == 5);
   assert(list.Get(2) == 6.6);
   cout << "1" << endl;
}
*/
