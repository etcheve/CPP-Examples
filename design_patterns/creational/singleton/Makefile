CXX      = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -Wpedantic
TARGET   = singleton
SRCS     = singleton.cpp main.cpp

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: run clean
