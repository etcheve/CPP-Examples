# Creational Design Patterns

Creational patterns deal with **object creation mechanisms**, decoupling the client from the specific classes it needs to instantiate. They increase flexibility and reuse of existing code.

## Patterns

| Pattern | Intent |
|---------|--------|
| [Singleton](singleton/) | Ensure only one instance exists; provide a global access point |
| [Builder](builder/) | Construct complex objects step by step with a fluent interface |
| [Factory Method](factory_method/) | Let subclasses decide which class to instantiate |
| [Abstract Factory](abstract_factory/) | Create families of related objects without specifying concrete classes |
| [Prototype](prototype/) | Create new objects by cloning an existing one |

## Build & run all

From this directory:

```bash
make        # build all patterns
make run    # build and run all patterns
make clean  # remove all binaries
```

Or build/run a single pattern:

```bash
make -C singleton run
make -C builder run
make -C factory_method run
make -C abstract_factory run
make -C prototype run
```
