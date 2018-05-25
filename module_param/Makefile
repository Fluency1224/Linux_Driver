ifneq ($(KERNELRELEASE),)
$(info "2nd")
obj-m:=hello.o
else
KDIR:=/lib/modules/$(shell uname -r)/build
#KDIR:=/home/fluency/sbc/am3352-sbc/src/am335x-linux-3.14.26
PWD:=$(shell pwd)
all:
	$(info "1st")
	make -C $(KDIR) M=$(PWD) modules
clean:
	rm -r *.o *.mod.c *.order *.symvers *.ko
endif