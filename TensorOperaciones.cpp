#include "Tensor.h"
#include <iomanip>

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
        case 3:
            size_t rows = tens.shape[0];
            size_t cols = tens.shape[1];
            size_t fond = tens.shape[2];
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
            
    }
    return os;
}