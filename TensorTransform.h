#pragma once


class Tensor;

class TensorTransform {
public:
    virtual Tensor apply(const Tensor& t) const = 0;
    virtual ~TensorTransform() = default;
};

class ReLu : public TensorTransform {
    Tensor apply(const Tensor& t) const override;
    //~ReLu();
};

class Sigmoid : public TensorTransform{
    Tensor apply(const Tensor& t) const override;
    //~Sigmoid();
};
