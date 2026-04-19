## Chain of Responsibility

Passes a request along a chain of handlers. Each handler decides to process it or forward it to the next.

**Roles:**
- `Handler` — interface declaring `setNext` and `handleRequest`
- `AbstractHandler` — base class implementing the `setNext` / `next_` boilerplate
- `BasicHandler`, `HttpAuthHandler`, `LoggingHandler` — concrete handlers

`setNext` returns the next handler so the chain can be built fluently:
```cpp
basic.setNext(&httpAuth)->setNext(&logger);
```

Similar to middleware chains in web frameworks (Gin, Express, ASP.NET).
