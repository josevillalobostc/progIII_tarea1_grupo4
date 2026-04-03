#include "Tensor.h"
using namespace std;

Tensor Tensor::zeros(const std::vector<size_t>& _shape){
    int total_elementos = 1;
    for(const size_t val : _shape)
        total_elementos *= val;
    vector<double> _values(total_elementos,0);
    Tensor zerifico(_shape,_values);
    return zerifico;    

}

Tensor Tensor::ones(const std::vector<size_t>){

}

Tensor Tensor::random(const std::vector<size_t>,const double min,const double max){

}

Tensor Tensor::arrange(const int in, const int fin){

}
