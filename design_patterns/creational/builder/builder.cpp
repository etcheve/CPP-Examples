#include "builder.hpp"

Product::Builder& Product::Builder::host(const std::string &host) {
    product_.host_ = host;
    return *this;
}

Product::Builder& Product::Builder::port(int port) {
    product_.port_ = port;
    return *this;
}

Product::Builder& Product::Builder::tls(bool tls) {
    product_.tls_ = tls;
    return *this;
}

Product::Builder& Product::Builder::timeoutMs(int timeoutMs) {
    product_.timeoutMs_ = timeoutMs;
    return *this;
}

Product::Builder& Product::Builder::retries(int retries) {
    product_.retries_ = retries;
    return *this;
}

Product Product::Builder::build() {
    return std::move(product_);
}
