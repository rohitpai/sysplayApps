# sysplayApps

# Generic cross build instructions
[To build library]
export PKG_CONFIG_PATH=/opt/sysplay/1.0/sysroots/cortexa8hf-neon-poky-linux-gnueabi/usr/lib/pkgconfig
meson build --cross-file ../meson.cross 
sudo DESTDIR=/opt/sysplay/1.0/sysroots/cortexa8hf-neon-poky-linux-gnueabi/usr/lib/pkgconfig ninja install

# Build out of the tree kernel modules
1. Source the environment file for your SDK
2. cd to <SDKInstallPath>/sysroots/<mach>/usr/src/kernel and run 'make modules_prepare'
3. Now to compile the hello world or any other module.
KERNEL_SRC=<SDKInstallPath>/sysroots/<mach>/usr/src/kernel make

# DTB Conversion 
# dtc can be installed by this command on linux:
sudo apt-get install device-tree-compiler
# you can compile dts or dtsi files by this command:
dtc -I dts -O dtb -o devicetree_file_name.dtb devicetree_file_name.dts
# you can convert dts to dtb by this command:
dtc -I dts -O dtb -f devicetree_file_name.dts -o devicetree_file_name.dtb
# you can convert dtb to dts by this command:
dtc -I dtb -O dts -f devicetree_file_name.dtb -o devicetree_file_name.dts

