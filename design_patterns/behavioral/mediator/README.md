## Mediator

Reduces direct dependencies between objects by routing all communication through a central mediator.

**Roles:**
- `Mediator` — interface with `notify(sender, event)`
- `BaseComponent` — holds a pointer to the mediator; concrete components call `mediator_->notify()`
- `Component1`, `Component2` — participants that trigger and react to events
- `ConcreteMediator` — wires components together and implements the coordination logic
