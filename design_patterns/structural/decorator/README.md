# Decorator

Attaches additional behaviour to an object at runtime by wrapping it in decorator objects.
Each decorator holds a reference to the wrapped object and delegates to it, then adds its own behaviour.

## Participants
- **Component** (`Car`) — interface shared by base objects and decorators
- **Concrete component** (`Nissan`) — the base object being decorated
- **Base decorator** (`CarDecorator`) — holds a `unique_ptr<Car>` and forwards calls
- **Concrete decorators** (`AddSpoiler`, `AddWheels`, `AddPinkPaint`) — add behaviour before/after the delegate call

## vs Builder
Builder constructs an object in one shot at one place; Decorator wraps an already-constructed object
and the wrapping can happen anywhere, in any order, at runtime.

## Common use case
Loggers: wrap a base service with a logging decorator without changing the service class.

## Build
```
g++ -std=c++20 -Wall -Wextra -Wpedantic decorator.cpp -o decorator
```
