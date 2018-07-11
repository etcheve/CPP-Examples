#include<iostream>

int main(){

  int x=3;

  auto aLambda = [](int a,int b) {return a+b;};

  int a = aLambda(1,2);

  auto bLambda =   [=] (int a)->int  {
    return x + a;
  };

  std::cout << bLambda(3) << std::endl;

  std::cout << a << std::endl;

}
