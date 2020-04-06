# sysplayApps

# Generic cross build instructions
[To build library]
export PKG_CONFIG_PATH=/opt/sysplay/1.0/sysroots/cortexa8hf-neon-poky-linux-gnueabi/usr/lib/pkgconfig
meson build --cross-file ../meson.cross 
sudo DESTDIR=/opt/sysplay/1.0/sysroots/cortexa8hf-neon-poky-linux-gnueabi/usr/lib/pkgconfig ninja install
