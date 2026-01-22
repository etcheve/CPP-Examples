#include <iostream>

template <typename Derived>
class Shape {
public:
    void draw() const {
        // Downcast safely at compile time
        static_cast<const Derived*>(this)->drawImpl();
    }
};



class Circle : public Shape<Circle> {
public:
    void drawImpl() const {
        std::cout << "Drawing Circle\n";
    }
};

class Square : public Shape<Square> {
public:
    void drawImpl() const {
        std::cout << "Drawing Square\n";
    }
};


int main() {
    Circle c;
    Square s;

    // compile-time dispatch
    c.draw(); 
    s.draw();
}
