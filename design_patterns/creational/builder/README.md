# Builder

## Intent

Separate the construction of a complex object from its representation, allowing the same construction process to produce different configurations.

## When to use

- An object requires many optional parameters or configuration steps.
- You want to avoid telescoping constructors.
- Construction should be done step by step, with only a final `build()` call producing the object.

## Key points

- `Product` has a **private default constructor** — it can only be created through its inner `Builder`.
- The `Builder` stores a `Product` internally and fills its fields via fluent setter methods.
- Each setter returns `*this` (a `Builder&`) enabling **method chaining**.
- `build()` moves the fully configured `Product` out of the builder.

## Structure

```mermaid
classDiagram
    class Product {
        -host_ : string
        -port_ : int
        -tls_ : bool
        -timeoutMs_ : int
        -retries_ : int
        -Product()
        +print() void
    }
    class Builder {
        -product_ : Product
        +host(h : string) Builder&
        +port(p : int) Builder&
        +tls(t : bool) Builder&
        +timeoutMs(ms : int) Builder&
        +retries(n : int) Builder&
        +build() Product
    }
    Product +-- Builder : inner class
    Builder ..> Product : builds
```

## Files

| File | Description |
|------|-------------|
| `product.hpp` | `Product` class declaration with inner `Builder` forward declaration |
| `product.cpp` | `Product::print()` implementation |
| `builder.hpp` | `Product::Builder` class declaration |
| `builder.cpp` | Builder method implementations |
| `main.cpp` | Demo: fluent builder call to configure an HTTP client |

## Build & run

```bash
make        # build
make run    # build and run
make clean  # remove binary
```
