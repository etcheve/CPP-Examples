#pragma once
#include "product.hpp"

class Factory {
    public:
    virtual ~Factory (){}
    virtual std::unique_ptr<Product> createProduct() const = 0;
};

// Concrete Factory 1
class ConcreteFactory1 : public Factory {
    public:
    std::unique_ptr<Product> createProduct() const override {
        return std::make_unique<Product1>();
    }
};
// Concrete Factory 2
class ConcreteFactory2 : public Factory {
    public:
    std::unique_ptr<Product> createProduct() const override {
        return std::make_unique<Product2>();
    }
};


// in this case no default implementation is provided for the factory method