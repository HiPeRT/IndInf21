CC=gcc
RM=rm -rf
EXENAME=03-main
INCDIR=-I 03-lib-folder
LDFLAG=-l stdc++
CFLAG=-Wall $(INCDIR)
CSRCS=03-main.cpp 03-lib-folder/03-lib.cpp

all:
	$(RM) *.o $(EXENAME)
	$(CC) $(CFLAG) -o $(EXENAME) $(CSRCS) $(LDFLAG)
	
clean:
	$(RM) *.o $(EXENAME)

run: all
	./$(EXENAME)