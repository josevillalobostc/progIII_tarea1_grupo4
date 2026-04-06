#include <iostream>
#include "Tensor.h"
#include "TensorTransform.h"

using namespace std;

int main() {
    Tensor eldimensional = Tensor::random({1000, 20, 20}, -50, 50);
    Tensor elerror = eldimensional.view({15,15});
    cout << "Tensor 1000x20x20 creado" << endl;

    Tensor viewificado = eldimensional.view({1000, 400});
    cout << "view a 1000x400 completado" << endl;

    Tensor peso1 = Tensor::random({400, 100}, -10, 10);
    
    Tensor temp = Tensor::random({1, 100}, -10, 10);
    vector<Tensor> paconcatenar(1000,temp);
    Tensor bias = Tensor::concat(paconcatenar,0);
    
    Tensor suma = matmul(viewificado, peso1) + bias;
    cout << "matmul (1000x400 * 400x100) y suma de bias (1x100) completado" << endl;

    ReLu ojo;
    Tensor aplicado = suma.apply(ojo);
    cout << "relu aplicado" << endl;

    Tensor peso2 = Tensor::random({100, 10}, -10, 10);
    Tensor temp2 = Tensor::random({1, 10}, -10, 10);
    vector<Tensor> paconcatenar2(1000,temp2);
    Tensor bias2 = Tensor::concat(paconcatenar2,0);
    
    Tensor suma2 = matmul(aplicado, peso2) + bias2;
    cout << "segunda matmul (1000x100 * 100x10) y suma de bias (1x10) completado" << endl;

    Sigmoid sigma;
    Tensor final = suma2.apply(sigma);
    cout << "sigmoid aplicado" << endl;

    //cout << final;
    
    cout << "todo corrió" << endl;
    return 0;
}