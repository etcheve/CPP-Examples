#pragma once
#include "product.hpp"

class Product::Builder {
public:
    Builder& host(const std::string &host);
    Builder& port(int port);
    Builder& tls(bool tls);
    Builder& timeoutMs(int timeoutMs);
    Builder& retries(int retries);
    Product build();

private:
    Product product_;
};