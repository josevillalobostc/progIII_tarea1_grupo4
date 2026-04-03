#include "Tensor.h"

Tensor Tensor::apply ( const TensorTransform & transform ) const {

}

Tensor Tensor::operator+(const Tensor& other){
    if (this->ndims!=other.ndims) throw std::invalid_argument("Dimensiones incompatibles");
    for (size_t i=0;i<ndims;++i) {
        if (this->shape[i]!=other.shape[i]) throw std::invalid_argument("Dimensiones deben coincidir");
    }
    std::vector<double> result_values(total_elements);
    for (size_t i=0;i<total_elements;++i) {result_values[i]=this->data[i]+other.data[i];}
    std::vector<size_t> current_shape(shape,shape+ndims);
    return Tensor(current_shape,result_values);
}

Tensor Tensor::operator-(const Tensor& other){
    if (this->ndims!=other.ndims) throw std::invalid_argument("Dimensiones incompatibles");
    for (size_t i=0;i<ndims;++i) {
        if (this->shape[i]!=other.shape[i]) throw std::invalid_argument("Dimensiones deben coincidir");
    }
    std::vector<double> result_values(total_elements);
    for (size_t i=0;i<total_elements;++i) {result_values[i]=this->data[i]-other.data[i];}
    std::vector<size_t> current_shape(shape,shape+ndims);
    return Tensor(current_shape,result_values);
}

Tensor Tensor::operator*(const Tensor& other){
    if (this->ndims!=other.ndims) throw std::invalid_argument("Dimensiones incompatibles");
    for (size_t i=0;i<ndims;++i) {
        if (this->shape[i]!=other.shape[i]) throw std::invalid_argument("Dimensiones deben coincidir");
    }
    std::vector<double> result_values(total_elements);
    for (size_t i=0;i<total_elements;++i) {result_values[i]=this->data[i]*other.data[i];}
    std::vector<size_t> current_shape(shape,shape+ndims);
    return Tensor(current_shape,result_values);
}

Tensor Tensor::operator*(const double n){
    std::vector<double> result_values(total_elements);
    for (size_t i=0;i<total_elements;++i) {result_values[i]=this->data[i]*n;}
    std::vector<size_t> current_shape(shape,shape+ndims);
    return Tensor(current_shape, result_values);
}

// Funciones amigas

Tensor dot(const Tensor& a ,const Tensor& b){

}

Tensor matmul(const Tensor& a ,const Tensor& b){

}
