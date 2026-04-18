#include "decorator.hpp"

int main() {
    std::unique_ptr<Car> car = std::make_unique<Nissan>();
    car = std::make_unique<AddSpoiler>(std::move(car));
    car = std::make_unique<AddWheels>(std::move(car));
    car = std::make_unique<AddPinkPaint>(std::move(car));
    car->ride();
    std::cout << '\n';
}
