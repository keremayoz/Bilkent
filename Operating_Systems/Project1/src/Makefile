all: phistogram thistogram
	
phistogram: phistogram.c
	cc -Wall  -o phistogram phistogram.c -lm -ggdb

thistogram: thistogram.c
	cc -Wall -pthread -o thistogram thistogram.c -lm -ggdb