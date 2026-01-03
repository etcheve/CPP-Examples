#include "factory.hpp"

int main (){
    auto victorianFactory = new VictorianFactory();
    Chair* victorianChair = victorianFactory->createChair();
    Sofa* victorianSofa = victorianFactory->createSofa();   
    victorianChair->method();
    victorianSofa->method();

    auto modernFactory = new ModernFactory();
    Chair* modernChair = modernFactory->createChair();
    Sofa* modernSofa = modernFactory->createSofa();
    modernChair->method();
    modernSofa->method();

    delete victorianChair;
    delete victorianSofa;
    delete victorianFactory;
    delete modernChair;
    delete modernSofa;
    delete modernFactory;
    
    return 0;
}