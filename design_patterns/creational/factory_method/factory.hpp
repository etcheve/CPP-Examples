#pragma once
#include <memory>
#include "product.hpp"

class Factory {
public:
    virtual ~Factory() {}
    virtual std::unique_ptr<Product> createProduct() const = 0;
};

class ConcreteFactory1 : public Factory {
public:
    std::unique_ptr<Product> createProduct() const override;
};

class ConcreteFactory2 : public Factory {
public:
    std::unique_ptr<Product> createProduct() const override;
};