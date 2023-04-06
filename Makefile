CC = gcc
CFLAGS = -Wall -Werror

SRC_DIR = src
OUT_DIR = bin
OBJ_DIR = obj
	
MAIN_SRCS = $(wildcard $(SRC_DIR)/geometry/*.c)
MAIN_OBJ = $(MAIN_SRCS:$(SRC_DIR)/geometry/%.c=$(OBJ_DIR)/geometry/%.o)

LIB_SRCS = $(wildcard $(SRC_DIR)/libgeometry/*.c)
LIB_OBJ = $(LIB_SRCS:$(SRC_DIR)/libgeometry/%.c=$(OBJ_DIR)/libgeometry/%.o)

LIB_TARGET = $(OUT_DIR)/libgeometry.a
TARGET = $(OUT_DIR)/main

.PHONY: all clean test

all: $(LIB_TARGET) $(TARGET)

$(TARGET): $(MAIN_OBJ) 
	$(CC) $(CFLAGS) $^ -lm -L$(OUT_DIR) -lgeometry -o $@

$(OBJ_DIR)/geometry/%.o: $(SRC_DIR)/geometry/%.c
	$(CC) $(CFLAGS) -c -Isrc $< -o $@

$(LIB_TARGET): $(LIB_OBJ)
	ar rcs $@ $^

$(OBJ_DIR)/libgeometry/%.o: $(SRC_DIR)/libgeometry/%.c
	$(CC) $(CFLAGS) -c $< -o $@

run:
	./$(TARGET)

clean:
	rm -rf $(OBJ_DIR)/libgeometry/*.o $(OBJ_DIR)/geometry/*.o $(TARGET)
	rm -rf $(OUT_DIR)/*.a