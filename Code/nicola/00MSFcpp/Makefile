SOURCE=$(PWD)
CC=gcc
CFLAGS=-Wall
CSRC=src/next_state.cpp src/check_state.cpp src/input.cpp 
CINC=inc/next_state.hpp inc/check_state.hpp inc/input.hpp

all: clean
	$(CC) $(CFLAGS) main.cpp $(SOURCE)/$(CSRC) -o $(SOURCE)/build/test -l stdc++ $(SOURCE)/$(CINC)

clean:
	rm -f $(SOURCE)/build/*

run: all
	$(SOURCE)/build/test