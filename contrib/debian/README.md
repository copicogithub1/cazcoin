
Debian
====================
This directory contains files used to package cazcoind/cazcoin-qt
for Debian-based Linux systems. If you compile cazcoind/cazcoin-qt yourself, there are some useful files here.

## cazcoin: URI support ##


cazcoin-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install cazcoin-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your cazcoinqt binary to `/usr/bin`
and the `../../share/pixmaps/cazcoin128.png` to `/usr/share/pixmaps`

cazcoin-qt.protocol (KDE)

