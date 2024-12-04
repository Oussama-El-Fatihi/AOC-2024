# Compiler
CXX = g++

# Compiler Flags
CXXFLAGS = -std=c++17

# Target executable name
TARGET = program

# Default rule: compile and link
all: $(TARGET)

# Rule to build the executable
$(TARGET): day4.cpp
	$(CXX) $(CXXFLAGS) day4.cpp -o $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Clean up build files
clean:
	rm -f $(TARGET)
