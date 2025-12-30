 lets you construct complex objects step by step. 

  is a well-known pattern in C++ world. It’s especially useful when you need to create an object with lots of possible configuration options.

a single creation method and several methods to configure the resulting object. 

Having a director class in your program isn’t strictly necessary. You can always call the building steps in a specific order directly from the client code. However, the director class might be a good place to put various construction routines so you can reuse them across your program.


g++ -std=c++20 -Wall -Wextra -Wpedantic product.cpp main.cpp -o test_builder