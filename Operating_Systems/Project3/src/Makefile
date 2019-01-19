obj-m+=pagewalk.o

all:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) modules
	make app
clean:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) clean
