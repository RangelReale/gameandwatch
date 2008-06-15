#!/bin/sh
#
aclocal -I m4
automake --foreign -a -c
autoconf

