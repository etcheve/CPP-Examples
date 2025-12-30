#pragma once
#include "product.hpp"

// Builder interface 
class Product::Builder {
    public:
        Builder& host(const std::string &host){
            product_.host_ = host;
            return *this;
        }
        Builder& port(int port){
            product_.port_ = port;
            return *this;
        }
        Builder& tls(bool tls){
            product_.tls_ = tls;
            return *this;
        }
        Builder& timeoutMs(int timeoutMs){
            product_.timeoutMs_ = timeoutMs;
            return *this;
        }
        Builder& retries(int retries){
            product_.retries_ = retries;
            return *this;
        }

        Product build() {
        // validation
        return std::move(product_);
    }
    private: 
        Product product_;


   
};