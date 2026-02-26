#pragma once
#include "product.hpp"

class Factory {
public:
    virtual ~Factory() {}
    virtual Chair* createChair() const = 0;
    virtual Sofa* createSofa() const = 0;
};

class VictorianFactory : public Factory {
public:
    Chair* createChair() const override;
    Sofa* createSofa() const override;
};

class ModernFactory : public Factory {
public:
    Chair* createChair() const override;
    Sofa* createSofa() const override;
};
