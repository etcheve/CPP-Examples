# Facade

Provides a simplified interface to a complex subsystem.
Clients interact with one object instead of coordinating multiple subsystem classes directly.

## Participants
- **Subsystem classes** (`Engine`, `Lights`, `Aircon`) — do the real work; unaware of the facade
- **Facade** (`CarFacade`) — delegates to subsystem classes in the right order

## When to use
- Hide complexity behind a single entry point (e.g. SDK wrappers, service layers)
- Reduce coupling between clients and subsystem internals

## Build
```
g++ -std=c++20 -Wall -Wextra -Wpedantic main.cpp -o facade
```
