## Strategy

Defines a family of algorithms, encapsulates each as an object, and makes them interchangeable at runtime.

**Roles:**
- `Strategy` — interface declaring `doAlgorithm()`
- `ConcreteStrategyA`, `ConcreteStrategyB` — interchangeable algorithm implementations
- `Context` — owns a `unique_ptr<Strategy>` and delegates execution to it via `executeStrategy()`
