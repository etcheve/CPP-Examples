#include <iostream>

class myInt{
  int _myNumber;

  public:
    myInt(int i){
      _myNumber = i;
    }

    myInt& operator++()
    {
      _myNumber++;
      return *this;
    }

    myInt operator++(int)
    {
      myInt tmp(*this); // copy
      operator++(); // pre-increment
      return tmp;   // return old value
    }

    int getNumber() const {
      return _myNumber;
    }
};

int main (){
  myInt a(1);
  myInt b=a++;
  myInt c(1);
  myInt d=++c;
  
  std::cout <<"a: "<< a.getNumber() << std::endl;
  std::cout <<"b: "<< b.getNumber() << std::endl;
  std::cout <<"c: "<< c.getNumber() << std::endl;
  std::cout <<"d: "<< d.getNumber() << std::endl;
}
