#include<iostream>
class A{
  public:
    A(){
      std::cout << "A contructor" << std::endl;
    }  

      virtual ~A(){
        std::cout << "A Destructor" << std::endl;
      }
};

class B : public A{
  public:
    B(){
      std::cout << "B contructor" << std::endl;
    }
    ~B(){
      std::cout << "B destructor" << std::endl;
    }
};

class D{
  public:
    D(){
      std::cout << "D contructor" << std::endl;
    }
    ~D(){
      std::cout << "D destructor" << std::endl;
    }
};

class C : public B,virtual D{
  public:
    C(){
      std::cout << "C contructor" << std::endl;
    }
    ~C(){
      std::cout << "C destructor" << std::endl;
    }
};

int main (){

  C c;
  return 0;
}
