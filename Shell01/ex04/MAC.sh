#!/bin/sh
ifconfig | awk '/ether/ {print $2}'| grep -v 'auto'
