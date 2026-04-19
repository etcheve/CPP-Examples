## Template Method

Defines the skeleton of an algorithm in a base class, deferring some steps to subclasses without changing the overall structure.

**Roles:**
- `AbstractClass` — defines `templateMethod()` which calls fixed steps (`baseOperation1/2`) and abstract steps (`requiredOperation1/2`)
- `hook()` — optional override point with a default no-op implementation
- `ConcreteClass1`, `ConcreteClass2` — fill in the abstract steps; `ConcreteClass2` also overrides the hook
