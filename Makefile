# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Iinclude

# Application source files
APP_SRC = src/main.c src/user.c src/utils.c src/app.c
APP_OBJ = $(APP_SRC:src/%.c=build/%.o)
APP_OUT = build/user_mgmt

# Test source files
TEST_SRC = test/user_tests.c src/user.c src/utils.c
TEST_OUT = build/user_tests

# Default build target
all: $(APP_OUT)

# Build application executable
$(APP_OUT): $(APP_OBJ)
	@mkdir -p build
	@$(CC) $(CFLAGS) -o $@ $^

# Compile object files to build/
build/%.o: src/%.c
	@mkdir -p build
	@$(CC) $(CFLAGS) -c $< -o $@

# Build and run unit tests
test: $(TEST_SRC)
	@mkdir -p build
	@$(CC) $(CFLAGS) -o $(TEST_OUT) $(TEST_SRC)
	@echo
	@$(TEST_OUT)

# Clean build files silently
clean:
	@rm -rf build

# Run application
run: all
	@./$(APP_OUT)

# Build and run everything
full: clean all test

.PHONY: all clean run test full
