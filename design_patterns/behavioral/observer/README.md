## Observer

Defines a subscription mechanism so multiple objects are notified automatically when the subject's state changes.

**Roles:**
- `Subject` — interface for `attach`, `detach`, and `notify`
- `Observer` — interface with `update(message)`
- `ConcreteSubject` — maintains the observer list and broadcasts messages
- `ConcreteObserver` — subscribes on construction and detaches itself after the first notification

Note: `notify()` iterates over a copy of the list so observers can safely detach themselves during the callback.
