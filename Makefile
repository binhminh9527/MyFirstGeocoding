CC = g++

# Directories and target
SRC_DIR = src
BUILD_DIR = build
BIN = MyFirstGeocoding

# Find all source files (recursive). Using find is more portable for nested dirs.
SOURCES := $(shell find $(SRC_DIR) -name '*.cpp')
OBJECTS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))

# Derive -I include flags from source subdirectories and the public include dir
SRC_SUBDIRS := $(sort $(dir $(SOURCES)))
INC_DIRS := $(patsubst %,-I%,$(SRC_SUBDIRS))
CFLAGS := -Iinclude $(INC_DIRS) -DLOG_ENABLE -g -Wall -Wextra -std=c++17 

all: $(BUILD_DIR) $(BIN)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BIN): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(BIN)

.PHONY: all clean