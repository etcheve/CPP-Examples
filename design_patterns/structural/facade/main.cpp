#include <iostream>

class Engine{
    public: 
      virtual void start(){
        std::cout << "Engine started" << std::endl;
      }
      virtual void stop(){
        std::cout << "Engine stopped" << std::endl;
      }
};

class Lights{
    public:
      virtual void turnOn(){
        std::cout << "Lights turned on" << std::endl;
      }
      virtual void turnOff(){
        std::cout << "Lights turned off" << std::endl;
      }
};

class Aircon{
    public:
      virtual void turnOn(){    
        std::cout << "Aircon turned on" << std::endl;
      }

    virtual void turnOff(){
        std::cout << "Aircon turned off" << std::endl;
    }

};

class CarFacade{
    private:
      Engine *engine_;
      Lights *lights_;
      Aircon *aircon_;
    public:
      CarFacade(Engine* engine = nullptr, Lights* lights = nullptr, Aircon* aircon = nullptr){
        engine_ = engine ? engine : new Engine();
        lights_ = lights ? lights : new Lights();
        aircon_ = aircon ? aircon : new Aircon();
      }
      void startCar(){
        engine_->start();
        lights_->turnOn();
        aircon_->turnOn();
        std::cout << "Car started" << std::endl;
      }
      void stopCar(){
        aircon_->turnOff();
        lights_->turnOff();
        engine_->stop();
        std::cout << "Car stopped" << std::endl;
      }
};

int main(){
    CarFacade car;
    car.startCar();
    car.stopCar();
}