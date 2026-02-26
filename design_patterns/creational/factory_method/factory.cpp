#include "factory.hpp"

std::unique_ptr<Product> ConcreteFactory1::createProduct() const {
    return std::make_unique<Product1>();
}

std::unique_ptr<Product> ConcreteFactory2::createProduct() const {
    return std::make_unique<Product2>();
}
