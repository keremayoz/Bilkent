default: bwtfm

bwtfm.o: bwtfm.c $(HEADERS)
	gcc -c bwtfm.c -o bwtfm.o -lm

bwtfm: bwtfm.o
	gcc bwtfm.o -o bwtfm -lm