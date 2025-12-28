#pragma once
class Singleton {


private:
    Singleton(int value);
    static Singleton *instance_;
    int value_;

public:
    // disable copy constructor
    Singleton(Singleton &other) = delete;

    void operator=(const Singleton &) = delete;

    static Singleton* getSingleton(int value) ;
    int getValue() const {
        return value_;
    }
};