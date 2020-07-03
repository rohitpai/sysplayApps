	KERNEL_SRC:= /opt/sysplay/1.0/sysroots/armv7at2hf-neon-poky-linux-gnueabi/usr/src/kernel
	obj-m += kernel-threads.o work-queue.o mod-synch.o poll-wait.o
	SRC := $(shell pwd)
all:
	$(MAKE) -C $(KERNEL_SRC) M=$(SRC)
modules_install:
	$(MAKE) -C $(KERNEL_SRC) M=$(SRC) modules_install
clean: clean_build
	rm -f *.ko
clean_build:
	rm -f *.o *~ core .depend .*.cmd *.mod.c *.a *.mod
	rm -f Module.markers Module.symvers modules.order
	rm -rf .tmp_versions Modules.symvers	