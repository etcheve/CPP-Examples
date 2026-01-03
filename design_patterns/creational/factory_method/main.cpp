#include "factory.hpp"
#include "product.hpp"
#include <iostream>

void ClientCode(const Product& product) {
  // ...
  std::cout << "Client: I'm not aware of the creator's class, but it still works.\n"
            << product.operation() << std::endl;
  // ...
}



int main (){
  Factory* factory;
  factory = new ConcreteFactory1();
  auto product1 = factory->createProduct(); 
  ClientCode(*product1);
  delete factory; 

  factory = new ConcreteFactory2();
  auto product2 = factory->createProduct(); 
  ClientCode(*product2);
  delete factory;

}

