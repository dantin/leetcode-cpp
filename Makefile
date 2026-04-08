# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -g -std=c++17

# Source files: find all .cc and .h files in the current directory
SOURCE_FILES := $(wildcard *.cc *.h)
CLANG_FORMAT := clang-format

# Binary targets: extract <name> from src/<name>/main.cpp and create bin/<name>
BINARY_TARGETS := $(patsubst src/%/main.cpp,bin/%,$(SOURCE_FILES))

# Phony targets (targets that don't create files with the same name)
.PHONY: all clean format

format:
	@echo "Formatting source files..."
	@$(CLANG_FORMAT) -i $(SOURCE_FILES)
	@echo "Done."

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
