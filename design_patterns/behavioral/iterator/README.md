## Iterator

Lets you traverse elements of a collection without exposing its underlying representation.

**Roles:**
- `Iterator<T, Z>` — traversal cursor with `first()`, `next()`, `isDone()`, `currentItem()`
- `Container<T>` — collection that creates its own iterator via `createIterator()`

The example uses two containers: one of `int` and one of a custom `Data` type, showing the template works for any element type.
