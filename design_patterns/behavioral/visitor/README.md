## Visitor

Lets you add new operations to a class hierarchy without modifying the classes themselves. The element "accepts" a visitor, which dispatches to the right overload.

**Roles:**
- `Visitor` — interface with one `visit()` overload per element type
- `Visitable` — interface with `accept(Visitor&)`, implemented by every element
- `A`, `B`, `C`, `D` — concrete elements; each calls `v.visit(*this)`
- `VisitAndPrint` — concrete visitor that prints the element type

Double dispatch: `accept()` resolves the element type, then `visit()` resolves the visitor type.

Compile with: `g++ -std=c++14 visitor.cpp && ./a.out`
