KERNEL_SRC:= /opt/sysplay/1.0/sysroots/armv7at2hf-neon-poky-linux-gnueabi/usr/src/kernel
obj-m:= spi_client.o
SRC:= $(shell pwd)

all:
	$(MAKE) -C $(KERNEL_SRC) M=$(SRC)
modules_install:
	$(MAKE) -C $(KERNEL_SRC) M=$(SRC) modules_install
clean:
	rm -f *.o *~ core .depend .*.cmd *.ko *.mod.c built-in.* *.mod
	rm -f Module.markers Module.symvers modules.order
	rm -rf .tmp_versions Modules.symvers