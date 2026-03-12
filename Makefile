CC := gcc
CFLAGS := -Wall -Wextra -O2 -std=c99 -Wpedantic

SRCS := $(wildcard src/*.c)
OBJS := $(patsubst src/%.c,build/%.o,$(SRCS))
EXE_NAME := build/stilton

# Default target
all: $(EXE_NAME)

# Link the executable from object files
$(EXE_NAME): $(OBJS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ $^

# Compile .c files into build/ directory
build/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $<

# Clean everything in build/
clean:
	rm -rf build

.PHONY: all clean