#include <iostream>

class Visitable;

class Visitor {
public:
    virtual ~Visitor() = default;
    virtual void visit(class A& a) = 0;
    virtual void visit(class B& b) = 0;
    virtual void visit(class C& c) = 0;
    virtual void visit(class D& d) = 0;
};

class Visitable {
public:
    virtual ~Visitable() = default;
    virtual void accept(Visitor& v) = 0;
};

class A : public Visitable {
public:
    void accept(Visitor& v) override { v.visit(*this); }
};

class B : public Visitable {
public:
    void accept(Visitor& v) override { v.visit(*this); }
};

class C : public Visitable {
public:
    void accept(Visitor& v) override { v.visit(*this); }
};

class D : public Visitable {
public:
    void accept(Visitor& v) override { v.visit(*this); }
};

class VisitAndPrint : public Visitor {
public:
    void visit(A&) override { std::cout << "A\n"; }
    void visit(B&) override { std::cout << "B\n"; }
    void visit(C&) override { std::cout << "C\n"; }
    void visit(D&) override { std::cout << "D\n"; }
};

int main() {
    A a; B b; C c; D d;
    VisitAndPrint v;
    a.accept(v);
    b.accept(v);
    c.accept(v);
    d.accept(v);
}
