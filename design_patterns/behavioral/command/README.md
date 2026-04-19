## Command

Turns a request into a stand-alone object holding all the information needed to execute it. This lets you queue, log, or undo operations.

**Roles:**
- `Command` — interface with a single `execute()` method
- `SimpleCommand` — command with no external dependency
- `ReceiverCommand` — delegates work to a `Receiver` object
- `Receiver` — contains the actual business logic
- `Invoker` — triggers commands at the right moment (owns them via `unique_ptr`)
