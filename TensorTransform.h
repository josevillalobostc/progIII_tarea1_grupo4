#pragma once
#include "Tensor.h"

class TensorTransform {
public:
    virtual Tensor apply ( const Tensor & t ) const = 0;
    virtual ~ TensorTransform () = default ;
};

class ReLu : public TensorTransform {

};

class Sigmoid : public TensorTransform {

};
