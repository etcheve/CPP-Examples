#pragma once
#include "product.hpp"
class Factory{
    public:
    virtual ~Factory (){}
    virtual Chair* createChair() const = 0;
    virtual Sofa* createSofa() const = 0;
};


// Concrete Factory 1
class VictorianFactory : public Factory {
    public:
    Chair* createChair() const override {
        return new VictorianChair();
    }
    Sofa* createSofa() const override {
        return new VictorianSofa();
    }
};
// Concrete Factory 2
class ModernFactory : public Factory {
    public:
    Chair* createChair() const override {
        return new ModernChair();
    }
    Sofa* createSofa() const override {
        return new ModernSofa();
    }
};  
