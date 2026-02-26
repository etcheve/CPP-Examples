#include "factory.hpp"

Chair* VictorianFactory::createChair() const {
    return new VictorianChair();
}

Sofa* VictorianFactory::createSofa() const {
    return new VictorianSofa();
}

Chair* ModernFactory::createChair() const {
    return new ModernChair();
}

Sofa* ModernFactory::createSofa() const {
    return new ModernSofa();
}
