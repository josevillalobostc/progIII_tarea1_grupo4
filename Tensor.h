#pragma once
#include <iostream>
#include <vector>
#include "TensorTransform.h"



class Tensor{
    double* data;
    size_t* shape;
    size_t ndims;
    size_t total_elements;
public:
    // Constructores
    Tensor(const std::vector<size_t>& shape,
        const std::vector<double>& values);

    Tensor(const Tensor& other);
    Tensor(Tensor&& other) noexcept;
    Tensor& operator=(const Tensor& other);
    Tensor& operator=(Tensor&& other) noexcept;
    ~Tensor();

    // Tensores predefinidos
    Tensor zeros(const std::vector<size_t>);
    Tensor ones(const std::vector<size_t>);
    Tensor random(const std::vector<size_t>,const double min,const double max);
    Tensor arrange(const int in, const int fin);

    //ModDimensiones
    Tensor view(const std::vector<size_t>);
    Tensor unsqueeze(const int n);
    Tensor concat(const std::vector<Tensor>, const int n);

    //Operaciones
    Tensor apply ( const TensorTransform & transform ) const ;
    Tensor operator+(const Tensor& other);
    Tensor operator-(const Tensor& other);
    Tensor operator*(const Tensor& other);
    Tensor operator*(const double n);

    friend Tensor dot(const Tensor& a ,const Tensor& b);
    friend Tensor matmul(const Tensor& a ,const Tensor& b);
};
