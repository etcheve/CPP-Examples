#include <iostream>
#include <memory>

class AbstractClass {
    public: 
    virtual ~AbstractClass() = default;
    void templateMethod() const {
        baseOperation1();   
        requiredOperation1();
        baseOperation2();
        hook();
        requiredOperation2();
    }

    void baseOperation1() const {
        std::cout << "AbstractClass: baseOperation1\n";
    }   
    void baseOperation2() const {
        std::cout << "AbstractClass: baseOperation2\n";
    }
    virtual void requiredOperation1() const = 0;
    virtual void requiredOperation2() const = 0;
    virtual void hook() const {}
};


class ConcreteClass1 : public AbstractClass {
    public:
    void requiredOperation1() const override {
        std::cout << "ConcreteClass1: requiredOperation1\n";
    }
    void requiredOperation2() const override {
        std::cout << "ConcreteClass1: requiredOperation2\n";
    }
};
class ConcreteClass2 : public AbstractClass {
    public:
    void requiredOperation1() const override {
        std::cout << "ConcreteClass2: requiredOperation1\n";
    }
    void requiredOperation2() const override {
        std::cout << "ConcreteClass2: requiredOperation2\n";
    }
    void hook() const override {
        std::cout << "ConcreteClass2: Overridden Hook\n";
    }
};

int main() {
    std::cout << "Same client code can work with different subclasses:\n";
    auto class1 = std::make_unique<ConcreteClass1>();
    class1->templateMethod();

    auto class2 = std::make_unique<ConcreteClass2>();
    class2->templateMethod();

    return 0;
}