#compiler
GCC = g++

#flags
FLAGS = -Wall -g

#lib file
LIB = chessLib.cpp

#source file
SOURCE = main.cpp

#out file
OUT = test.x

all:
	$(GCC) $(FLAGS) $(LIB) $(SOURCE) -o $(OUT)

clean:
	rm -rf $(OUT)
