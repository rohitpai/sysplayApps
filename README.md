# sysplayApps

# Generic cross build instructions
[To build library]
export PKG_CONFIG_PATH=/opt/poky/2.7.3/sysroots/cortexa8hf-neon-poky-linux-gnueabi/usr/lib/pkgconfig
meson build --cross-file ../meson.cross 
sudo DESTDIR=/opt/poky/2.7.3/sysroots/cortexa8hf-neon-poky-linux-gnueabi/usr/lib/pkgconfig ninja install
