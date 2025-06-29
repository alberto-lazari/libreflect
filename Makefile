# Compiler
CXX := g++

# Directories
BUILD_DIR := build
SRC_DIR := src/reflect
LIB_DIR := $(BUILD_DIR)/lib
BIN_DIR := $(BUILD_DIR)/bin
OBJ_DIR := $(BUILD_DIR)/obj
TEST_EXE := $(BIN_DIR)/test

# Library Name
LIB_NAME := reflect
SHARED_LIB := $(LIB_DIR)/lib$(LIB_NAME).dylib

# Source & Headers
SRC := $(wildcard $(SRC_DIR)/*.cpp)
INCLUDE_PATHS := include
OBJ := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC))

# Test File
TEST_SRC := tests/test.cpp

# Compiler & Linker Flags
CXXFLAGS := -std=c++20 -Wall -Wextra "-I$(INCLUDE_PATHS)" -fPIC
LDFLAGS := -L$(LIB_DIR) -l$(LIB_NAME) -Wl,-rpath,$(LIB_DIR)

# Dependency files
DEPS := $(OBJ:.o=.d)

# Default target
all: $(SHARED_LIB)

# Compile object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@echo "[compile] $(patsubst $(SRC_DIR)/%.cpp,%.cpp,$<)"
	@"$(CXX)" $(CXXFLAGS) -MMD -MF "$(OBJ_DIR)/$*.d" -c "$<" -o "$@"

# Build shared library
$(SHARED_LIB): $(OBJ) | $(LIB_DIR)
	@$(CXX) -dynamiclib -o $@ $^

# Compile test program (dynamically link library)
$(TEST_EXE): $(TEST_SRC) $(SHARED_LIB) | $(BIN_DIR)
	@"$(CXX)" $(CXXFLAGS) $(OBJ) "$<" -o "$@" $(LDFLAGS)

# Run tests
test: $(TEST_EXE)
	@echo '[test] >'
	@"$(TEST_EXE)"

# Create necessary directories
$(BUILD_DIR) $(LIB_DIR) $(BIN_DIR) $(OBJ_DIR):
	@mkdir -p "$@"

# Clean rule
clean:
	@rm -rf "$(BUILD_DIR)"

# Include dependency files
-include $(DEPS)

.PHONY: all clean test
