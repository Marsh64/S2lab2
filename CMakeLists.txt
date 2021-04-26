cmake_minimum_required(VERSION 3.17)
project(laboratory_work_2)

set(CMAKE_CXX_STANDARD 14)

add_executable(laboratory_work_2 main.cpp Base/DynamicArray.cpp Base/DynamicArray.h Base/LinkedList.cpp Base/LinkedList.h Sequence/Sequence.cpp Sequence/Sequence.h Sequence/ArraySequence.cpp Sequence/ArraySequence.h Sequence/LinkedListSequence.cpp Sequence/LinkedListSequence.h "Tests/Tests_DA and LL.cpp" "Tests/Tests_DA and LL.h" "Tests/Tests_AS and LLS.cpp" "Tests/Tests_AS and LLS.h" Vector.cpp Vector.h Matrix.cpp Matrix.h MenuVector.h MenuVector.cpp MenuMatrix.h MenuMatrix.cpp MenuAll.cpp MenuAll.h)