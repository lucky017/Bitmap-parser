# Compiler
CC := gcc

# Collect sources
src     := $(wildcard src/*.c)

# Turn every source .c into an object under Lib/
lib_objs := $(patsubst src/%.c,Lib/%.o,$(src))

# Final target
ALL: bitmap

bitmap: Main.o $(lib_objs)
	$(CC) $^ -o $@

# Rule for Main.o (stays outside Lib/)
Main.o: Main.c
	$(CC) -c $< -o $@

# Generic rule: any .c in src → .o in Lib
Lib/%.o: src/%.c
	@mkdir -p $(dir $@)   # ensure Lib/... directory exists
	$(CC) -c $< -o $@

# Clean up
clean:
	rm -f Main.o bitmap $(lib_objs)

