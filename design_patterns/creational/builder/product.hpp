#pragma once 
#include <string>

class Product{
    public: 
        class Builder;
        void print() const;
    private:
        std::string host_;
        int port_;
        bool tls_;
        int timeoutMs_;
        int retries_;
        Product() = default;
};
