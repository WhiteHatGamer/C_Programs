# $(subst from,to,text)
# $(patsubst pattern,replacement,text)

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
TEST_CFLAGS:= -g -Wall -Iinclude

SRC_DIR   := src
OBJ_DIR   := obj
BIN_DIR   := bin
LIB_DIR   := lib
TEST_DIR  := tests
INC_DIR	  := include

MAINOBJ	:= $(OBJ_DIR)$(PS)main.o
SRCS 	:= $(wildcard $(SRC_DIR)/*.c)
TESTS 	:= $(wildcard $(TEST_DIR)/*.c)
TESTBIN := $(patsubst $(TEST_DIR)/%.c, $(TEST_DIR)/bin/%, $(TESTS))
OBJS 	:= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
BIN 	:= $(BIN_DIR)$(PS)main$(BIN_EXT)
LIBSA 	:= $(patsubst $(OBJ_DIR)/%.o, $(LIB_DIR)/lib%.a, $(filter-out $(OBJ_DIR)/main.o, $(OBJS)))

ifeq ($(OS),Linux)
	LIBS := $(patsubst $(OBJ_DIR)/%.o, $(LIB_DIR)/lib%.so, $(filter-out $(OBJ_DIR)/main.o, $(OBJS)))
	RM_LIB:= $(RM) $(LIB_DIR)$(PS)*.so
else
	LIBS := $(patsubst $(OBJ_DIR)/%.o, $(LIB_DIR)/lib%.dll, $(filter-out $(OBJ_DIR)/main.o, $(OBJS)))
	RM_LIB:= $(RM) $(LIB_DIR)$(PS)*.dll
endif

.PHONY: all clean

all: clean $(BIN) $(LIBS) $(LIBSA)

$(LIB_DIR)/lib%.a: $(OBJ_DIR)/%.o
	ar -crs $@ $^

$(LIB_DIR)/lib%.dll: $(OBJS)
	$(CC) $(CFLAGS) -fPIC -shared -o $@ $^

$(LIB_DIR)/lib%.so: $(SRC_DIR)/%.c $(INC_DIR)/%.h
	$(CC) $(CFLAGS) -fPIC -shared -o $@ $< -lc

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TEST_DIR)/bin/%: $(TEST_DIR)/%.c $(LIBSA)
	$(CC) $(TEST_CFLAGS) $< $(LIBSA) -o $@ -lcriterion

run: clean $(BIN)
	$(BIN)

ifeq ($(OS),Linux)
valgrind: all
	valgrind --leak-check=yes -s ./$(BIN)
endif

$(BIN_DIR):
	mkdir $@

$(LIB_DIR):
	mkdir $@

$(OBJ_DIR):
	mkdir $@

$(SRC_DIR):
	mkdir $@

$(TEST_DIR):
	mkdir $@

$(TEST_DIR)/bin:
	mkdir $@

test: $(LIBSA) $(TEST_DIR)/bin $(TESTBIN)
	$(foreach test, $(TESTBIN), $(test))

test-v: $(LIBSA) $(TEST_DIR)/bin $(TESTBIN)
	$(foreach test, $(TESTBIN), $(test)) --verbose
# for test in $(TESTBIN) ; do ./$$test ; done

clean:
	$(RM) $(OBJ_DIR)$(PS)*
	$(RM) $(BIN_DIR)$(PS)*
	$(RM) $(LIB_DIR)$(PS)*.a
	$(RM_LIB)
	$(RM) $(TEST_DIR)$(PS)bin$(PS)*