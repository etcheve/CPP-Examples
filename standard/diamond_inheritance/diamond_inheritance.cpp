#include<iostream>

class A{
public:
A(){a=0;}
A(int i){a=i;}

int getA(){
  return a;
}

private:
int a;
};

class B: virtual public A{
public:
  B() : A(1) {}
};

class C : public virtual A{
public:
  C() : A(2) {}
};

class D : public B, public C{
public:
  D() : B(), C(), A(8) {}
};

int main(){
D d;
std::cout << "Value: " <<d.getA() << std::endl;
}
