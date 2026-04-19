## State

Lets an object alter its behavior when its internal state changes — it looks as if it changed its class.

**Roles:**
- `State` — abstract base holding a back-pointer to `Context`; declares `handle()`
- `Context` — owns the current state and delegates `request()` to it; calls `transitionTo()` to switch states
- `ConcreteStateA`, `ConcreteStateB` — implement `handle()` and trigger transitions

States own their own transition logic, keeping `Context` free of conditionals.
