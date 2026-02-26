#include "prototype.hpp"

int main() {
    Shape* circle1 = new Circle();
    Shape* circle2 = circle1->clone();

    Shape* square1 = new Square();
    Shape* square2 = square1->clone();

    circle1->draw();
    circle2->draw();
    square1->draw();
    square2->draw();

    delete circle1;
    delete circle2;
    delete square1;
    delete square2;

    return 0;
}