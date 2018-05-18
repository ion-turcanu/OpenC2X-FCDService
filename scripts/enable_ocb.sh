#!/bin/bash

IFACE=wlan0		# wireless interface
FREQ=5890		# in MHz
BAND=10MHZ		# 10 MHZ is default in ITS-G5
IP_ADDR=192.168.1.2

# set the proper regulatory domain
iw reg set AA

# set iface mode to OCB
ip link set $IFACE down
iw dev $IFACE set type ocb
ip link set $IFACE up

# use the ETSI ITS-G5 CCH channel
iw dev $IFACE ocb join $FREQ $BAND

# set an IP address
ifconfig $IFACE $IP_ADDR

# print iface info to make sure everything is ok
iw $IFACE info
