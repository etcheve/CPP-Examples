# Composite

Composes objects into tree structures to represent part-whole hierarchies.
Clients can treat individual objects (leaves) and compositions (nodes) uniformly through a common interface.

## Participants
- **Component** (`FileSystemObject`) — common interface for leaves and composites
- **Leaf** (`File`) — has no children; implements operations directly
- **Composite** (`Directory`) — stores children and delegates operations to them

## Key operations
| Method | Leaf | Composite |
|---|---|---|
| `Add` | throws | appends child |
| `Delete(obj*)` | prints deletion | removes matching child |
| `Clear()` | no-op | removes all children |
| `DisplayAll()` | prints self | prints self + recurses |

## Watch out
Ownership matters: moving a `unique_ptr` into `Add()` transfers it — keep no reference to it after that point.

## Build
```
g++ -std=c++20 -Wall -Wextra -Wpedantic main.cpp -o composite
```
