all: ts clean

ts: ts.o tsl.o
	gcc -o ts ts.o tsl.o

ts.o: ts.c
	gcc -g -std=c99 -Wall -c -o ts.o ts.c

tsl.o: tsl.c
	gcc -g -std=c99 -Wall -c -o tsl.o tsl.c

clean: 
	del *.o
