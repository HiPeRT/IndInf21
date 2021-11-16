SRCROUTE=$(PWD)
CC=gcc
CFLAGS=-Wall
CSRC=src/00-blink.cpp 
CINC=inc/00-blink.h

all: clean
	$(CC) $(CFLAGS) 00-main.cpp $(SRCROUTE)/$(CSRC) -o $(SRCROUTE)/build/01test -l stdc++ $(SRCROUTE)/$(CINC)

clean:
	rm -f $(SRCROUTE)/build/*

run: all
	$(SRCROUTE)/build/01test
