NAMEBIN = 001

CC = gcc
CFLAGS = -Wall
CSRC = src/*.cpp
CINC = inc/


all: clean
	$(CC) $(CFLAGS) main.cpp -D NO_PI $(CSRC) -I $(CINC) -o bin/$(NAMEBIN) -l stdc++ -l wiringPi

clean:
	rm -f bin/$(NAMEBIN)

run: all
	bin/$(NAMEBIN)