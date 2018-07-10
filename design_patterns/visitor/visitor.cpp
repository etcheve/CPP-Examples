#include<iostream>

class Visitor{
  public:
  virtual void visit(class A &a) =0;
  virtual void visit(class B &b) =0;
  virtual void visit(class C &c) =0;
  virtual void visit(class D &d) =0;
};

class VisitAndPrint : public Visitor{
public:


virtual void visit(class A &a){
  std::cout << "A" << std::endl;
}
virtual void visit(class B &b){
  std::cout << "B" << std::endl;
}
virtual void visit(class C &c){
  std::cout << "C" << std::endl;
}
virtual void visit(class D &d){
  std::cout << "D" << std::endl;
}

};
class toBeVisited{
  public:
  virtual void accept(Visitor &v) = 0;
};

class A : public toBeVisited{
  public:
 virtual void accept(Visitor &v ) {
   v.visit( *this );
 }
};

class B: public toBeVisited{
  public:
  virtual void accept( Visitor &v ) {
    v.visit( *this );
  }
};

class C: public toBeVisited{
  public:
  virtual void accept( Visitor &v ) {
    v.visit( *this );
  }
};

class D: public toBeVisited{
  public:
  virtual void accept( Visitor &v ) {
    v.visit( *this );
  }
};

int main(){
A a;
B b;
C c;
D d;
VisitAndPrint v;
a.accept(v);
b.accept(v);
c.accept(v);
d.accept(v);
}
