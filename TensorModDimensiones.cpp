#include "Tensor.h"
#include <algorithm>

Tensor Tensor::view(const std::vector<size_t>& _shape){
    if (_shape.size() > 3) throw std::invalid_argument("Máximo 3 dimensiones."); 
    size_t nuevoTam = 1;
    for(const size_t &el : _shape)
        nuevoTam*=el;
    if (nuevoTam != total_elements) throw std::invalid_argument("La cantidad de elementos no coinciden."); 
    
    Tensor viewifico = std::move(*this);
    delete[] viewifico.shape;
    viewifico.ndims = _shape.size();
    viewifico.shape = new size_t[viewifico.ndims];
    for(size_t i = 0; i < viewifico.ndims; i++){
        viewifico.shape[i] = _shape[i];
    }
    
    return viewifico;
}

Tensor Tensor::unsqueeze(const size_t n){
    if (ndims >= 3) throw std::invalid_argument("No se pueden agregar más dimensiones, ya se tienen 3."); 
    if (n >= ndims) throw std::invalid_argument("Indice inválido"); 
    std::vector <size_t> new_shape;
    new_shape.reserve(ndims + 1);
    
    for (size_t i = 0, j = 0; i <= ndims; i++){
        if(i == n) {
            new_shape.push_back(1);
        }
        else {
            new_shape.push_back(shape[j]);
            j++;
        }
    }
    
    Tensor unsquizico = std::move(*this);
    
    delete[] unsquizico.shape;
    unsquizico.ndims = unsquizico.ndims + 1;
    unsquizico.shape = new size_t[unsquizico.ndims];
    for(size_t i = 0; i < unsquizico.ndims; i++){
        unsquizico.shape[i] = new_shape[i];
    }
    
    return unsquizico;
    
}

Tensor Tensor::concat(const std::vector<Tensor>& tensores, const size_t n){
    if (tensores.empty()) throw std::invalid_argument("Lista de tensores vacía.");
    size_t dims = tensores[0].ndims;
    std::vector<size_t> new_shape(dims);
    
    for (size_t i = 0; i < dims; i++) {
            if (i == n) {
                size_t sum_axis = 0;
                for (const auto& t : tensores) sum_axis += t.shape[i];
                new_shape[i] = sum_axis;
            } else {
                new_shape[i] = tensores[0].shape[i];
                for (const auto& t : tensores) {
                    if (t.shape[i] != new_shape[i]) throw std::invalid_argument("Dimensiones incompatibles.");
                }
            }
        }
    Tensor concatifico = Tensor::zeros(new_shape);
    
    size_t interc = 1;
    size_t ante_salto = 1;
    
    for(size_t i = 0; i < n;i++)
        interc *= concatifico.shape[i];
    
    for(size_t i = n + 1; i < concatifico.ndims; i++)
        ante_salto *= concatifico.shape[i];
    size_t acumulado = 0;
    for(size_t i = 0; i < interc; i++){
        for(const Tensor& tens : tensores){
            size_t salto = ante_salto * tens.shape[n];
            std::copy(tens.data + i * salto,tens.data + i * salto + salto ,concatifico.data + acumulado);
            acumulado+= salto;
        }
    }
    return concatifico;
}
