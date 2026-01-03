#pragma once
#include <iostream>
class Chair {
public:
    virtual ~Chair() = default;
    virtual void method() = 0;
};

class Sofa {
public:
    virtual ~Sofa() = default;
    virtual void method() = 0;
};

class VictorianChair : public Chair {
public:
    void method() override {
        // Implementation for Victorian Chair
        std::cout << "Victorian Chair method called." << std::endl;
    }
};
 

class VictorianSofa : public Sofa {
public:
    void method() override {
        // Implementation for Victorian Sofa
        std::cout << "Victorian Sofa method called." << std::endl;
    }
};

class ModernChair : public Chair {
public:
    void method() override {
        // Implementation for Modern Chair
        std::cout << "Modern Chair method called." << std::endl;
    }
};

class ModernSofa : public Sofa {         
public:
    void method() override {
        // Implementation for Modern Sofa
        std::cout << "Modern Sofa method called." << std::endl;
    }
};
