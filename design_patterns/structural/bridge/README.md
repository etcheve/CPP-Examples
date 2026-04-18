# Bridge

Decouples an abstraction from its implementation so the two can vary independently.
Instead of a single inheritance hierarchy that mixes "what" with "how", the abstraction
holds a pointer to an implementation interface.

## Participants
- **Implementation interface** (`Storage`) — declares the low-level operations
- **Concrete implementations** (`PostgresStorage`, `RedisStorage`) — platform-specific details
- **Abstraction** (`Service`) — high-level logic, delegates to `Storage`
- **Refined abstractions** (`UserService`, `OrderService`) — domain-specific operations

## When to use
- You want to avoid a permanent binding between abstraction and implementation
- Both the abstraction and implementation should be extensible via subclassing
- Looks similar to dependency injection — the key difference is that Bridge is a structural
  design decision (the abstraction owns the interface), while DI is about supplying dependencies from outside

## Build
```
g++ -std=c++20 -Wall -Wextra -Wpedantic main.cpp -o bridge
```
