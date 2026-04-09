# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -g -std=c++17

# Source files: find all main.cpp files in the src directory
SOURCE_FILES := $(wildcard src/*/main.cpp)
SRC := $(shell find src -name "*.cpp" -o -name "*.hpp" -o -name "*.cc" -o -name "*.h" 2>/dev/null)
CLANG_FORMAT := clang-format

# Binary targets: extract <name> from src/<name>/main.cpp and create bin/<name>
BINARY_TARGETS := $(patsubst src/%/main.cpp,bin/%,$(SOURCE_FILES))

# Phony targets (targets that don't create files with the same name)
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
fmt: fmt-cpp fmt-py

fmt-py: sync.py
	@echo "Formatting Python files..."
	@black sync.py
	@isort sync.py
	@echo "Done."

fmt-cpp:
	@echo "Formatting source files..."
	@if [ -n "$(SRC)" ]; then $(CLANG_FORMAT) -i --style=file:$(CURDIR)/.clang-format $(SRC); else echo "No source files to format."; fi
	@echo "Done."

# Clean target: remove all compiled binaries
clean:
	@echo "Cleaning up..."
	@rm -rf bin/*
	@echo "Done."
