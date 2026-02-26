CXX      = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -Wpedantic
TARGET   = abstract_factory
SRCS     = product.cpp factory.cpp main.cpp

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: run clean
