# Proxy

Provides a substitute object that controls access to the real object.
The proxy and the real object share the same interface, so clients are unaware of the indirection.

## Participants
- **Subject** — interface implemented by both the real object and the proxy
- **RealSubject** — the actual object doing the work
- **Proxy** — intercepts calls and adds access control, logging, caching, or lazy init

## Common proxy types
| Type | Purpose |
|---|---|
| Protection proxy | Access control before delegating |
| Virtual proxy | Lazy initialisation of expensive objects |
| Caching proxy | Memoises results of repeated calls |
| Logging proxy | Records calls for auditing |

## Build
```
g++ -std=c++20 -Wall -Wextra -Wpedantic proxy.cpp -o proxy
```
