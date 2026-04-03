#include "Tensor.h"
#include <random>
#include <algorithm>
using namespace std;

Tensor Tensor::zeros(const std::vector<size_t>& _shape){
    size_t total_elementos = 1;
    for(const size_t val : _shape)
        total_elementos *= val;
    vector<double> _values(total_elementos,0);
    Tensor zerifico(_shape,_values);
    return zerifico;

}

Tensor Tensor::ones(const std::vector<size_t>& _shape){
    
    size_t total_elementos = 1;
    for(const size_t val : _shape)
        total_elementos *= val;
    vector<double> _values(total_elementos,1);
    
    Tensor unifico(_shape,_values);
    return unifico;
}

Tensor Tensor::random(const std::vector<size_t>& _shape,const double min,const double max){
    size_t total_elementos = 1;
    for(const size_t val : _shape)
        total_elementos *= val;
    vector<double> _values(total_elementos);
    
    static std::random_device rd;
    static std::mt19937 randomin(rd());
    uniform_real_distribution<double> dis(min,max);
    
    for(size_t i = 0; i < total_elementos; i++)
        _values[i] = dis(randomin);
    Tensor randomifico(_shape,_values);
    return randomifico;
}

Tensor Tensor::arange(const int in, const int fin){
    if (fin <= in) {
            throw std::invalid_argument("El inicio debe ser menor al final."); 
        }
    const size_t tamaño = static_cast <size_t>(fin-in);
    vector<double> valores(tamaño);
    double i = static_cast<double>(in);
    for(auto & val : valores){
        val = i;
        i+=1;
    }
    Tensor arangifico({tamaño},valores);
    return arangifico;
}
