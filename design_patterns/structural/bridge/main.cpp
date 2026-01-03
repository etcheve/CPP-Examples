#include "bridge.hpp"


int main() {
    UserService users{ std::make_unique<PostgresStorage>() };
    OrderService orders{ std::make_unique<RedisStorage>() };

    users.createUser("42", "Alice");
    orders.createOrder("A1", "Keyboard");
}
