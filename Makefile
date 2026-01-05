# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -g

# Source files: find all .cc files in the current directory
SOURCE_FILES := $(wildcard *.cc)
CLANG_FORMAT := clang-format
SRC := $(shell find . -name "*.cc" -o -name "*.h")

# Binary targets: convert each .cc file to a binary in bin/ directory
# Example: add_two_numbers.cc -> bin/add_two_numbers
BINARY_TARGETS := $(SOURCE_FILES:%.cc=bin/%)

# Phony targets (targets that don't create files with the same name)
.PHONY: all clean format

format:
	@echo "Formatting source files..."
	@$(CLANG_FORMAT) -i $(SRC)
	@echo "Done."

# Default target: build all binaries
all: $(BINARY_TARGETS)

# Create bin directory if it doesn't exist
bin:
	@echo "Creating bin directory..."
	@mkdir -p bin
	@echo "Done."

# Pattern rule: compile each .cc file into a binary in bin/
# The | bin ensures the bin directory exists before compilation
bin/%: %.cc | bin
	@echo "Compiling $<..."
	$(CXX) $(CXXFLAGS) $< -o $@
	@echo "Done."

# Clean target: remove all compiled binaries
clean:
	@echo "Cleaning up..."
	@rm -rf bin/*
	@echo "Done."