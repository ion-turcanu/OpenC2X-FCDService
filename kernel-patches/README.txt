For setting up openC2X kernel with ath9k chipset, following needs to be done:

$ git clone https://github.com/CTU-IIG/802.11p-linux.git
$ cd 802.11p-linux
$ git checkout its-g5_v3
$ git am < 0001-Enable-queueing-in-all-4-ACs-BE-BK-VI-VO.patch
$ git am < 0002-Get-hw-queue-pending-stats-from-ath9k-via-netlink.patch

Build the kernel and have fun with openC2X!


----------------------------------------------------------------------------------------------------
                                      To compile kernel
----------------------------------------------------------------------------------------------------
$ mkdir _build_i386
$ make O=_build_i386 i386_defconfig
$ cd _build_i386
$ make menuconfig # important: select wireless card drivers (atheros) and other necessary drivers
$ make deb-pkg LOCALVERSION=-openc2x KDEB_PKGVERSION=1 -j4 # replace 4 with number of cpu cores you have


----------------------------------------------------------------------------------------------------
                                      To enable OCB
----------------------------------------------------------------------------------------------------
$ wget https://www.infradead.org/~tgr/libnl/files/libnl-1.1.4.tar.gz
$ tar -zxvf libnl-1.1.4.tar.gz
$ cd libnl-1.1.4
$ ./configure
$ make -j4
$ make install

$ sudo apt install libnl-3-dev

$ sudo apt install libnl-genl-3-dev

$ git clone https://github.com/CTU-IIG/802.11p-iw.git
$ cd 802.11p-iw
$ git checkout its-g5_v3
$ make -j4
$ make install
# check if the installation was successfull
$ iw | grep -i ocb
	# dev <devname> ocb join <freq in MHz> <5MHZ|10MHZ>
	# dev <devname> ocb leave

$ sudo apt install python-m2crypto
$ git clone https://github.com/CTU-IIG/802.11p-wireless-regdb.git
$ cd 802.11p-wireless-regdb
$ git checkout its-g5_v1
# add the following to the db.txt file:
country AA:
        (2402 - 2482 @ 40), (20)
        (5170 - 5250 @ 80), (17)
        (5250 - 5330 @ 80), (24)
        (5490 - 5730 @ 80), (24)
        (5735 - 5835 @ 80), (30)
        # For ITS-G5 evaluation
        (5840 - 5935 @ 10), (20)
$ make -j4
$ make install

$ sudo apt install libgcrypt11-dev
$ git clone https://github.com/CTU-IIG/802.11p-crda.git
$ cd 802.11p-crda
$ git checkout its-g5_v1
$ cp /usr/lib/crda/pubkeys/<username>.key.pub.pem pubkeys/
$ cp /usr/lib/crda/pubkeys/linville.key.pub.pem pubkeys/
$ make -j4
$ make install

# Test CRDA + generated regulatory.bin
$ /sbin/regdbdump ../802.11p-wireless-regdb/regulatory.bin | grep -i ocb
	# country 00: invalid
	# (5850.000 - 5925.000 @ 20.000), (20.00), NO-CCK, OCB-ONLY
