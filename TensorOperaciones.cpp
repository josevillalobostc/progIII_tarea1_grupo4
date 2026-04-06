#include "Tensor.h"
#include <iomanip>

Tensor Tensor::apply (const TensorTransform& transform) const {
    return transform.apply(*this);
}

Tensor Tensor::operator+(const Tensor& other){
    if (this->ndims!=other.ndims) throw std::invalid_argument("Dimensiones incompatibles.");
    for (size_t i=0;i<ndims;++i) {
        if (this->shape[i]!=other.shape[i]) throw std::invalid_argument("Dimensiones deben coincidir.");
    }
    std::vector<double> result_values(total_elements);
    for (size_t i=0;i<total_elements;++i) {result_values[i]=this->data[i]+other.data[i];}
    std::vector<size_t> current_shape(shape,shape+ndims);
    return Tensor(current_shape,result_values);
}

Tensor Tensor::operator-(const Tensor& other){
    if (this->ndims!=other.ndims) throw std::invalid_argument("Dimensiones incompatibles.");
    for (size_t i=0;i<ndims;++i) {
        if (this->shape[i]!=other.shape[i]) throw std::invalid_argument("Dimensiones deben coincidir.");
    }
    std::vector<double> result_values(total_elements);
    for (size_t i=0;i<total_elements;++i) {result_values[i]=this->data[i]-other.data[i];}
    std::vector<size_t> current_shape(shape,shape+ndims);
    return Tensor(current_shape,result_values);
}

Tensor Tensor::operator*(const Tensor& other){
    if (this->ndims!=other.ndims) throw std::invalid_argument("Dimensiones incompatibles.");
    for (size_t i=0;i<ndims;++i) {
        if (this->shape[i]!=other.shape[i]) throw std::invalid_argument("Dimensiones deben coincidir.");
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

double dot(const Tensor& a ,const Tensor& b){
    if (a.ndims!=1 or b.ndims!=1) throw std::invalid_argument("Dimensiones incompatibles.\n"
        "Ambos tensores deben tener 1 sola dimensión para realizar el producto punto.");
    if (a.shape[0]!=b.shape[0]) throw std::invalid_argument("Dimensiones deben coincidir.");
    double dot=0.0;
    for(size_t C=0;C<a.total_elements;++C){dot+=a.data[C]*b.data[C];}
    return dot;
}

Tensor matmul(const Tensor& a, const Tensor& b){
    if (a.ndims!=2 or b.ndims!=2) {
        throw std::invalid_argument("Dimensiones incompatibles.\n"
        "Ambos tensores deben tener 2 dimensiones para realizar el producto matricial.");
    }
    if (a.shape[1] != b.shape[0]) {
        throw std::invalid_argument("Dimensiones incompatibles para matmul.\n"
        "La segunda dimensión del primer tensor debe ser igual a la primera dimensión\n"
        "del segundo tensor.");
    }
    std::vector<double> result_values(a.shape[0]*b.shape[1],0.0);
    for (size_t C=0;C<a.shape[0];++C) {
        for (size_t D=0;D<b.shape[1];++D) {
            double sigma=0.0;
            for (size_t E=0;E<a.shape[1];++E) {
                sigma+=a.data[C*a.shape[1]+E]*b.data[E*b.shape[1]+D];
            }
            result_values[C*b.shape[1]+D]=sigma;
        }
    }
    return Tensor({a.shape[0],b.shape[1]}, result_values);
}


std::ostream& operator<<(std::ostream& os, const Tensor &tens){
    switch(tens.ndims){
        case 0:
            os << tens.data[0];
            break;
        case 1: {
            os << "[ ";
            for(size_t i = 0; i < tens.shape[0]; i++){
                os << std::setw(5) << tens.data[i] << " ";
            }
            os << "]";
            break;
        }
        case 2: {
            size_t rows = tens.shape[0];
            size_t cols = tens.shape[1];
            for (size_t i = 0; i < rows; ++i) {
                    os << "[ ";
                    for (size_t j = 0; j < cols; ++j) {
                        os << std::setw(5) << tens.data[i * cols + j] << " ";
                    }
                    os << "]\n";
                }
            break; 
        }       
        case 3:{
            size_t rows = tens.shape[1];
            size_t cols = tens.shape[2];
            size_t fond = tens.shape[0];
            for (size_t k = 0; k < fond; ++k) {
                    os << "Capa " << k << ":\n";
                    for (size_t i = 0; i < rows; ++i) {
                        os << "  [ ";
                        for (size_t j = 0; j < cols; ++j) {
                            
                            size_t ind = k * (rows * cols) + i * cols + j;
                            os << std::setw(5) << tens.data[ind] << " ";
                        }
                        os << "]\n";
                    }
                    os << "\n";
                }
            break;
        }
    }
    return os;
}