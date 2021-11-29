NAMEBIN = 001

CC = gcc
CFLAGS = -Wall
CSRC = src/*.cpp
CINC = inc/


all: clean
	$(CC) $(CFLAGS) main.cpp $(CSRC) -I $(CINC) -o bin/$(NAMEBIN) -l stdc++

clean:
	rm -f bin/$(NAMEBIN)

run: all
	bin/$(NAMEBIN)