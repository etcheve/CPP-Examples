#include "singleton.hpp"

    Singleton* Singleton::instance_ = nullptr;
    Singleton::Singleton(int value) : value_(value) {}

    // note this is not thread safe 
    Singleton* Singleton::getSingleton(int value) {
        if (instance_ == nullptr){
            instance_ = new Singleton(value);
        }
        return instance_;
    }
