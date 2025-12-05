
CC := gcc
CFLAGS := -Iinclude -Wall -Wextra -O2

# Collect source files
SRC_FILES := $(wildcard src/*.c) $(wildcard src/Header/*.c)

# Turn each src/... into Lib/... but keep subdirectories
OBJ_FILES := $(patsubst src/%,Lib/%,$(SRC_FILES:.c=.o))

# Final executable
TARGET := bitmap

all: $(TARGET)

$(TARGET): Main.o $(OBJ_FILES)
	$(CC) $^ -o $@

Main.o: Main.c
	$(CC) $(CFLAGS) -c $< -o $@

# Pattern rule: src/... → Lib/...
Lib/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f Main.o $(TARGET) $(OBJ_FILES)

.PHONY: all clean

