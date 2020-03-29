default: main

main.o: main.c $(HEADERS)
	gcc -c main.c -o main.o -lm

main: main.o
	gcc main.o -o main -lm