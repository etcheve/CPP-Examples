#include<iostream>

using namespace std;
class A{
  public:
    A(){cout << "a";}
    virtual ~A(){cout << "a";}
    virtual void foo(){cout << "a";}
};

class A1: public A{
  public:
    A1(){cout << "b";}
    virtual ~A1(){cout << "b";}
    virtual void foo(){cout << "b";}
};

class B{
  public:
    void foo(const A1& a1){cout << "b";}
    void foo(const A& a){cout << "a";}
};

int main(){
  A a;
  A1 a1;
  A& aa = a1;

  aa.foo();
  B b;
  b.foo(aa);
}
