#pragma once
#include <iostream>

class shaps{
public:
    virtual ~shaps() {}
    virtual void draw() = 0;
    virtual shaps* clone() const = 0;
};

class Circle : public shaps {
public:
    Circle* clone() const override {
        return new Circle(*this);
    }
    void draw() override {
        // Drawing logic for Circle
        std::cout << "Drawing Circle\n";
    }   
};  

class Square : public shaps {
public:
    Square* clone() const override {
        return new Square(*this);
    }

    void draw() override {
        // Drawing logic for Square
        std::cout << "Drawing Square\n";
    }
};  
