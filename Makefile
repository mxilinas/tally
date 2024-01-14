# Directories
SRC_DIR := src
INC_DIR := include
OBJ_DIR := obj

CFLAGS := -Wall \
		 -Wextra \
		 -pedantic \
		 -std=c11 \
		 -Wunused-variable \
		 -I$(INC_DIR) \
		 -g

CFLAGS += -DMAIN
#
# List of all source files
SRC := $(wildcard $(SRC_DIR)/*.c)

# Object files
OBJ := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

# Target executable
TARGET := countwords

# Build rule
$(TARGET): $(OBJ)
	$(CC) $^ -o $@

# Object file rule
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c mkdir
	$(CC) $(CFLAGS) -c $< -o $@

mkdir:
	if [ ! -d "obj" ]; then mkdir obj; fi

# Clean rule
clean:
	rm -rf $(OBJ_DIR)/*.o $(TARGET)
