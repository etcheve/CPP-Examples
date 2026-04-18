# Flyweight

Reduces memory usage by sharing the common (intrinsic) state among many fine-grained objects.
Each object stores only its unique (extrinsic) state and references shared state from a cache.

## Participants
- **Flyweight** — stores intrinsic (shared) state; receives extrinsic state via `operation()`
- **FlyweightFactory** — cache that creates or returns existing flyweights by key
- **SharedState** — data shared across many instances (e.g. car model, colour, brand)
- **UniqueState** — data unique to each instance (e.g. owner, licence plate)

## When to use
- Large numbers of similar objects are consuming too much RAM
- Most of the object state can be made extrinsic (passed in at call time)

## Build
```
g++ -std=c++20 -Wall -Wextra -Wpedantic main.cpp -o flyweight
```
