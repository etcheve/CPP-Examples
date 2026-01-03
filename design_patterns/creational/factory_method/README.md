separates product construction code from the code that actually uses the product. Therefore it’s easier to extend the product construction code independently from the rest of the code.

 Factory Method is based on inheritance but doesn’t require an initialization step.

Many designs start by using Factory Method (less complicated and more customizable via subclasses) and evolve toward Abstract Factory, Prototype, or Builder (more flexible, but more complicated).

 g++ -std=c++20 -Wall -Wextra -Wpedantic product.cpp  main.cpp -o test_factory
