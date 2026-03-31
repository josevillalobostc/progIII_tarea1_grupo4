cmake_minimum_required(VERSION 3.28)
project(Tarea1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Tarea1 main.cpp
    Tensor.h
    TensorConstructores.cpp
    Tensor
    TensorTransform.h
    TensorTransform.cpp)
