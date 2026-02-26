#pragma once

class Shape {
public:
    virtual ~Shape() {}
    virtual void draw() = 0;
    virtual Shape* clone() const = 0;
};

class Circle : public Shape {
public:
    Circle* clone() const override;
    void draw() override;
};

class Square : public Shape {
public:
    Square* clone() const override;
    void draw() override;
};
