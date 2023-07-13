OS := $(shell uname)
ifeq ($(OS),Linux)
	BIN_EXT := .exe
	RM := rm -rf
	PS := /
else
	BIN_EXT := 
	RM := del /Q
	PS := \\
endif

CC := gcc
CFLAGS := -g -Wall -Wextra -Iinclude

SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin

SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
BIN := $(BIN_DIR)$(PS)main$(BIN_EXT)

.PHONY: all clean

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

run:
	$(BIN)

ifeq ($(OS),Linux)
valgrind:
	valgrind --leak-check=yes -s ./$(BIN)
endif

clean:
	$(RM) $(OBJ_DIR)$(PS)*
	$(RM) $(BIN_DIR)$(PS)*