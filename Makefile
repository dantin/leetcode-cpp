# Compiler and flags
CC = g++
CFLAGS = -Wall -g

# Source files: find all .cc files in the current directory
SOURCE_FILES := $(wildcard *.cc)

# Binary targets: convert each .cc file to a binary in bin/ directory
# Example: add_two_numbers.cc -> bin/add_two_numbers
BINARY_TARGETS := $(SOURCE_FILES:%.cc=bin/%)

# Phony targets (targets that don't create files with the same name)
.PHONY: all clean

# Default target: build all binaries
all: $(BINARY_TARGETS)

# Create bin directory if it doesn't exist
bin:
	@mkdir -p bin

# Pattern rule: compile each .cc file into a binary in bin/
# The | bin ensures the bin directory exists before compilation
bin/%: %.cc | bin
	$(CC) $(CFLAGS) $< -o $@

# Clean target: remove all compiled binaries
clean:
	@rm -rf bin/*
