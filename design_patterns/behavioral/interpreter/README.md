## Interpreter

Defines a grammar for a language and provides an interpreter to evaluate sentences in that language. Useful for expression parsers, rule engines, or query languages.

**Roles:**
- `Expression` — interface with a single `interpret()` method
- `NumberExpression` — terminal expression (a literal value)
- `AddExpression`, `MultiplicationExpression` — non-terminal expressions (composite nodes)
- `Interpreter` — builds the expression tree and evaluates it

The example hardcodes the tree for `2 + 3 * 4 = 14`.
