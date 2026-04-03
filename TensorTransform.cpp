#include "TensorTransform.h"
#include "Tensor.h"
#include <algorithm>
#include <cmath>

// ReLu
Tensor ReLu::apply(const Tensor& t) const{
    Tensor reluifico = t;
    for (size_t i = 0; i < t.total_elements; i++){
        reluifico.data[i] = std::max(0.0,t.data[i]);
    }
    return reluifico;
}

//ReLu::~ReLu(){}

//Sigmoid
Tensor Sigmoid::apply(const Tensor& t) const{
    Tensor sigmoiduifico = t;
    for (size_t i = 0; i < t.total_elements; i++){
        sigmoiduifico.data[i] = 1 / (1 + std::exp(-t.data[i]));
    }
    return sigmoiduifico;
}

//Sigmoid::~Sigmoid(){}
