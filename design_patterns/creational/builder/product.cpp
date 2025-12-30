#include "product.hpp"
#include <iostream>

void Product::print() const{
    std::cout << "Host: " << host_ << "\n"
              << "Port: " << port_ << "\n"
              << "TLS: " << (tls_ ? "enabled" : "disabled") << "\n"
              << "Timeout (ms): " << timeoutMs_ << "\n"
              << "Retries: " << retries_ << "\n";
}