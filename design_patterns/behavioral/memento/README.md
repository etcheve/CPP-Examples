## Memento

Saves and restores the previous state of an object without exposing its internal implementation.

**Roles:**
- `Memento` — interface for reading saved state (`getState`, `getName`, `getDate`)
- `ConcreteMemento` — stores the actual snapshot
- `Originator` — the object whose state is saved; creates and consumes mementos
- `History` — caretaker that holds a stack of mementos and implements `undo()`
