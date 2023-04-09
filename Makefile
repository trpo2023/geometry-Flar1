CC = gcc
CFLAGS = -Wall -Werror

SrcDir = src
BinDir = bin
ObjDir = obj
	
MainSrcs = $(wildcard $(SrcDir)/geometry/*.c)
MainObj = $(MainSrcs:$(SrcDir)/geometry/%.c=$(ObjDir)/geometry/%.o)

LibSrcs = $(wildcard $(SrcDir)/libgeometry/*.c)
LibObj = $(LibSrcs:$(SrcDir)/libgeometry/%.c=$(ObjDir)/libgeometry/%.o)

LibTarget = $(BinDir)/libgeometry.a
Target = $(BinDir)/main

.PHONY: all clean test

all: $(LibTarget) $(Target)

$(Target): $(MainObj) 
	$(CC) $(CFLAGS) $^ -lm -L$(BinDir) -lgeometry -o $@

$(ObjDir)/geometry/%.o: $(SrcDir)/geometry/%.c
	$(CC) $(CFLAGS) -c -Isrc $< -o $@

$(LibTarget): $(LibObj)
	ar rcs $@ $^

$(ObjDir)/libgeometry/%.o: $(SrcDir)/libgeometry/%.c
	$(CC) $(CFLAGS) -c $< -o $@

run:
	./$(Target)

clean:
	rm -rf $(ObjDir)/libgeometry/*.o $(ObjDir)/geometry/*.o $(Target)
	rm -rf $(BinDir)/*.a