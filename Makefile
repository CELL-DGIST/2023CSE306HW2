obj-m += pmuon.o
KDIR : = /home/YOUR_ACCOUNT/RPdev/rpi-linux  #your kernel source directory
PWD = $(shell pwd)

all:
	make -C $(KDIR)  M=$(PWD) ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) modules

clean:
	make -C $(KDIR)  M=$(PWD) clean
