# Chatgbted, I really need to learn Make

CC = gcc

CFLAGS = -Wall -Wextra -I./src/include
LDFLAGS = -lraylib -lm

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = compiled

EXEC = $(BIN_DIR)/tetris

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(EXEC)

$(EXEC): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) -o $(EXEC) $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)/*.o $(BIN_DIR)/*

distclean: clean
	rm -f $(EXEC)

.PHONY: all clean distclean

