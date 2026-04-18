# Adapter

Converts the interface of a class into another interface that clients expect.
Lets classes with incompatible interfaces work together without modifying their source.

## Participants
- **Target** (`TargetMarketData`) — interface the client expects
- **Adaptee** (`LegacyMarketData`) — existing class with an incompatible interface
- **Adapter** (`AdapterMarketData`) — wraps the adaptee and translates calls

## When to use
- Integrating third-party or legacy code that can't be modified
- Reusing existing classes whose interface doesn't match what you need

## Build
```
g++ -std=c++20 -Wall -Wextra -Wpedantic main.cpp -o adapter
```
