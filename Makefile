CC := gcc
CFLAGS := -Wall -Wextra -O2 -std=c99 -Wpedantic -MMD -MP

SRCS := $(wildcard src/*.c)
HDRS := $(wildcard src/*.h)
OBJS := $(patsubst src/%.c,build/%.o,$(SRCS))
DEPS := $(OBJS:.o=.d)
EXE_NAME := build/stilton

all: $(EXE_NAME)

$(EXE_NAME): $(OBJS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ $^

build/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $<

format:
	clang-format -i $(SRCS) $(HDRS)

clean:
	rm -rf build

-include $(DEPS)

.PHONY: all clean format