#include "prototype.hpp"
#include <iostream>

Circle* Circle::clone() const {
    return new Circle(*this);
}

void Circle::draw() {
    std::cout << "Drawing Circle\n";
}

Square* Square::clone() const {
    return new Square(*this);
}

void Square::draw() {
    std::cout << "Drawing Square\n";
}
