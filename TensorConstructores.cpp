#include "Tensor.h"
#include <algorithm>

Tensor::Tensor(const std::vector<size_t>& _shape, const std::vector<double>& _values){
    if (_shape.size() > 3) throw std::invalid_argument("Máximo 3 dimensiones."); 
    ndims=_shape.size();
    shape=new size_t[ndims];
    total_elements=1;
    for (size_t i=0; i < ndims; ++i) {
        shape[i]=_shape[i];
        total_elements *= shape[i];
    }
    if (_values.size()!=total_elements) {
        delete[] shape;
        throw std::invalid_argument("El tamaño de values no coincide con las dimensiones."); 
    }
    data=new double[total_elements]; 
    std::copy(_values.begin(), _values.end(), data);
}

Tensor::Tensor(const Tensor& other){
    ndims=other.ndims;
    total_elements=other.total_elements;
    shape=new size_t[ndims];
    std::copy(other.shape, other.shape+ndims, shape);
    data=new double[total_elements];
    std::copy(other.data, other.data+total_elements, data);
}

Tensor::Tensor(Tensor&& other) noexcept : data(other.data), shape(other.shape), ndims(other.ndims), total_elements(other.total_elements) {
    other.data = nullptr;
    other.shape = nullptr;
    other.ndims = 0;
    other.total_elements = 0;
}

Tensor& Tensor::operator=(const Tensor& other){
    if (this == &other) return *this;
    delete[] data;
    delete[] shape;
    ndims = other.ndims;
    total_elements = other.total_elements;
    shape = new size_t[ndims];
    std::copy(other.shape, other.shape + ndims, shape);
    data = new double[total_elements];
    std::copy(other.data, other.data + total_elements, data);
    return *this;
}

Tensor& Tensor::operator=(Tensor&& other) noexcept{
    if (this == &other) return *this;
    delete[] data;
    delete[] shape;
    data = other.data;
    shape = other.shape;
    ndims = other.ndims;
    total_elements = other.total_elements;
    other.data = nullptr;
    other.shape = nullptr;
    return *this;
}

Tensor::~Tensor(){
    delete[] data;
    delete[] shape;
}
