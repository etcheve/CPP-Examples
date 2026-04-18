#include "proxy.hpp"
#include <memory>

static void clientCode(const Subject& subject) {
    subject.request();
}

int main() {
    auto real = std::make_unique<RealSubject>();

    std::cout << "Client: direct call\n";
    clientCode(*real);

    std::cout << "\nClient: call via proxy\n";
    Proxy proxy(real.get());
    clientCode(proxy);
}
