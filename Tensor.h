#pragma once
#include <iostream>
#include <vector>



class Tensor{

public:
    Tensor(const std::vector<size_t>& shape,
        const std::vector<double>& values);

    Tensor zeros(const std::vector<size_t>);


    Tensor ones(const std::vector<size_t>);
    Tensor random(const std::vector<size_t>,const double min,const double max);
    Tensor arrange(const int in, const int fin);


};
