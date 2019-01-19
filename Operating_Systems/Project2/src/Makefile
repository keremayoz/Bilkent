all: syn_phistogram syn_thistogram
	
syn_phistogram: syn_phistogram.c
	gcc -o syn_phistogram syn_phistogram.c -lm -ggdb -lrt -lpthread

syn_thistogram: syn_thistogram.c
	gcc -o syn_thistogram syn_thistogram.c -lm -ggdb -lrt -lpthread -pthread
