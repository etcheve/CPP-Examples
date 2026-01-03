#pragma once
#include <string>

// Interface that all products must implement
class Product{
    public:
    virtual ~Product() {}

    // This is the common method that all products must implement
    virtual std::string operation() const = 0;
};

// Example of a concrete product, example a Product could be a shape,
// and Produc1 a circle
class Product1 : public Product{
    public:
    std::string operation() const override;
};

class Product2 : public Product{
    public:
    std::string operation() const override;
};