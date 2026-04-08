# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -g -std=c++17

# Find all main.cpp files under src/*/
SOURCE_FILES := $(wildcard src/*/main.cpp)
CLANG_FORMAT := clang-format
SRC := $(shell find src -name "*.cpp" -o -name "*.hpp")

# Binary targets: extract <name> from src/<name>/main.cpp and create bin/<name>
BINARY_TARGETS := $(patsubst src/%/main.cpp,bin/%,$(SOURCE_FILES))

# Phony targets
.PHONY: all clean fmt

# Default target: build all binaries
all: $(BINARY_TARGETS)

# Create bin directory if it doesn't exist
bin:
	@echo "Creating bin directory..."
	@mkdir -p bin
	@echo "Done."

# Pattern rule: compile src/<name>/main.cpp into bin/<name>
bin/%: src/%/main.cpp | bin
	@echo "Compiling $<..."
	$(CXX) $(CXXFLAGS) $< -o $@
	@echo "Done."

# Format source files
fmt:
	@echo "Formatting source files..."
	@$(CLANG_FORMAT) -i $(SRC)
	@echo "Done."

# Clean target: remove all compiled binaries
clean:
	@echo "Cleaning up..."
	@rm -rf bin/*
	@echo "Done."
