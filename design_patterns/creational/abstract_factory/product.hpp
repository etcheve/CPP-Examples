#pragma once

class Chair {
public:
    virtual ~Chair() = default;
    virtual void method() = 0;
};

class Sofa {
public:
    virtual ~Sofa() = default;
    virtual void method() = 0;
};

class VictorianChair : public Chair {
public:
    void method() override;
};

class VictorianSofa : public Sofa {
public:
    void method() override;
};

class ModernChair : public Chair {
public:
    void method() override;
};

class ModernSofa : public Sofa {
public:
    void method() override;
};
