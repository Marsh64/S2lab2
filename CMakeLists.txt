cmake_minimum_required(VERSION 3.17)
project(laboratory_work_2)

set(CMAKE_CXX_STANDARD 14)

add_executable(laboratory_work_2 main.cpp DynamicArray.cpp DynamicArray.h LinkedList.cpp LinkedList.h Sequence.cpp Sequence.h ArraySequence.cpp ArraySequence.h LinkedListSequence.cpp LinkedListSequence.h "Tests_DA and LL.cpp" "Tests_DA and LL.h" "Tests_AS and LLS.cpp" "Tests_AS and LLS.h")