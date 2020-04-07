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