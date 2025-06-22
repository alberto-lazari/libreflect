# Compiler
CXX := g++

# Directories
BUILD_DIR := build
SRC_DIR := src
BIN_DIR := $(BUILD_DIR)/bin
OBJ_DIR := $(BUILD_DIR)/obj
TEST_EXE := $(BIN_DIR)/test

# Source & Headers
SRC := $(wildcard $(SRC_DIR)/*.cpp)
INCLUDE_PATHS := $(SRC_DIR)
OBJ := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC))

# Test File
TEST_SRC := tests/test.cpp

# Compiler & Linker Flags
CXXFLAGS := -std=c++20 -Wall -Wextra "-I$(INCLUDE_PATHS)" -fPIC

# Dependency files
DEPS := $(OBJ:.o=.d)

# Default target
all: $(OBJ)

# Compile object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@echo "[compile] $(patsubst $(SRC_DIR)/%.cpp,%.cpp,$<)"
	@"$(CXX)" $(CXXFLAGS) -MMD -MF "$(OBJ_DIR)/$*.d" -c "$<" -o "$@"

# Compile test program
$(TEST_EXE): $(TEST_SRC) $(OBJ) | $(BIN_DIR)
	@"$(CXX)" $(CXXFLAGS) $(OBJ) "$<" -o "$@"

# Run tests
test: $(TEST_EXE)
	@echo '[test] >'
	@"$(TEST_EXE)"

# Create necessary directories
$(BUILD_DIR) $(BIN_DIR) $(OBJ_DIR):
	@mkdir -p "$@"

# Clean rule
clean:
	@rm -rf "$(BUILD_DIR)"

# Include dependency files
-include $(DEPS)

.PHONY: all clean test
