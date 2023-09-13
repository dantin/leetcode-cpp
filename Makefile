CC = g++
CFLAGS=-Wall -g

SRCS := $(wildcard *.cc)
# This is a substitution reference. http://www.gnu.org/software/make/manual/make.html#Substitution-Refs
BINS := $(SRCS:%.cc=bin/%)

# Tell make that the all target has every binary as a prequisite and tell make that it will not create an `all` file (see http://www.gnu.org/software/make/manual/make.html#Phony-Targets).
.PHONY: all
all: $(BINS)

$(BINS) : bin/% : % | bin
	@mv $^ $@

# %.cc.o: %.cc
#	$(CC) -c $< -o $@
clean:
	@rm -rf bin/*
