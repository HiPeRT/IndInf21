CC=gcc
RM=rm -rf
EXENAME=02-main
INCDIR=-I 02-lib-folder
LDFLAG=-l stdc++
CFLAG=-Wall $(INCDIR)
CSRCS=02-main.cpp 02-lib-folder/02-lib.cpp

all:
	$(RM) *.o $(EXENAME)
	$(CC) $(CFLAG) -o $(EXENAME) $(CSRCS) $(LDFLAG)
	
clean:
	$(RM) *.o $(EXENAME)

run: all
	./$(EXENAME)