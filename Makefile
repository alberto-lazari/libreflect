# Compiler
CXX := g++

# Directories
BUILD_DIR := build
BIN_DIR := $(BUILD_DIR)/bin
OBJ_DIR := $(BUILD_DIR)/obj
TEST_EXE := $(BIN_DIR)/test

# Source & Headers
SRC := $(wildcard *.cpp)
INCLUDE_PATHS := .
OBJ := $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRC))

# Test File
TEST_SRC := tests/test.cpp

# Compiler & Linker Flags
CXXFLAGS := -std=c++20 -Wall -Wextra -I$(INCLUDE_PATHS) -fPIC

# Dependency files
DEPS := $(OBJ:.o=.d)

# Default target
all: $(OBJ)

# Compile object files
$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	@$(CXX) $(CXXFLAGS) -MMD -MF $(OBJ_DIR)/$*.d -c $< -o $@

# Compile test program
$(TEST_EXE): $(TEST_SRC) $(OBJ) | $(BIN_DIR)
	@$(CXX) $(CXXFLAGS) $(OBJ) $< -o $@

# Run tests
test: $(TEST_EXE)
	@$(TEST_EXE)

# Create necessary directories
$(BUILD_DIR) $(BIN_DIR) $(OBJ_DIR):
	@mkdir -p $@

# Clean rule
clean:
	@rm -rf $(BUILD_DIR)

# Include dependency files
-include $(DEPS)

.PHONY: all clean test
