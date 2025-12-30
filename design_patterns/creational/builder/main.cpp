#include "product.hpp"
#include "builder.hpp"

int main (){
     Product client =
        Product::Builder{}
            .host("api.myservice.com")
            .port(443)
            .tls(true)
            .timeoutMs(2000)
            .retries(3)
            .build();

    client.print();
    return 0;
}