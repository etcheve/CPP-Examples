#include <iostream>
#include <memory>

class Engine {
public:
    void start() { std::cout << "Engine started\n"; }
    void stop()  { std::cout << "Engine stopped\n"; }
};

class Lights {
public:
    void turnOn()  { std::cout << "Lights turned on\n"; }
    void turnOff() { std::cout << "Lights turned off\n"; }
};

class Aircon {
public:
    void turnOn()  { std::cout << "Aircon turned on\n"; }
    void turnOff() { std::cout << "Aircon turned off\n"; }
};

class CarFacade {
public:
    CarFacade()
        : engine_(std::make_unique<Engine>()),
          lights_(std::make_unique<Lights>()),
          aircon_(std::make_unique<Aircon>()) {}

    void startCar() {
        engine_->start();
        lights_->turnOn();
        aircon_->turnOn();
        std::cout << "Car ready\n";
    }

    void stopCar() {
        aircon_->turnOff();
        lights_->turnOff();
        engine_->stop();
        std::cout << "Car stopped\n";
    }

private:
    std::unique_ptr<Engine> engine_;
    std::unique_ptr<Lights> lights_;
    std::unique_ptr<Aircon> aircon_;
};

int main() {
    CarFacade car;
    car.startCar();
    car.stopCar();
}
