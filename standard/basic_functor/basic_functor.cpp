#include<vector>
#include<iostream>


class someFunctor {
  public:
    int operator()(int& x){
      return ++x;
    }
};


int main (){
  someFunctor afunct;
  int a =3;
  int b = afunct(a);

  std::cout << a << " " << b <<std::endl;
}
