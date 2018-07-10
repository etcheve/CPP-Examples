#include<iostream>

class Car{
   public:
     virtual void ride()=0;
 };

class Nissan : public Car{
   public:
   virtual void ride(){
     std::cout << "Ride on a Nissan" ;
   }
};

class Decorator : public Car{
   public:
     Car *car;
     Decorator(Car *c){
       car = c;
    }
    virtual void ride(){
       car->ride();
    }
};

class AddSpoiler : public Decorator{
   public:
     AddSpoiler(Car *c): Decorator(c){}
     virtual void ride(){
       car->ride();
       std::cout << " with a spoiler" ;
     }
};

class Addwheels : public Decorator{
   public:
     Addwheels(Car *c): Decorator(c){}
     virtual void ride(){
       car->ride();
       std::cout << " with Wheels" ;
     }
};

class AddPinkPaint : public Decorator{
   public:
     AddPinkPaint(Car *c): Decorator(c){}
     virtual void ride(){
       car->ride();
       std::cout << " with Pink Paint" ;
     }
};

int main(){
   Car *car;
   car = new Nissan();
   car = new AddSpoiler(car);
   car = new Addwheels(car);
   car = new AddPinkPaint(car);
   car->ride();
   std::cout << std::endl;
}
