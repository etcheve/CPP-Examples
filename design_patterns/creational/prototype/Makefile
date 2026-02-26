CXX      = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -Wpedantic
TARGET   = prototype
SRCS     = prototype.cpp main.cpp

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: run clean
