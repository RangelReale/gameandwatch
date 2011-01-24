#!/bin/sh


LOCAL_PATH=`dirname $0`
LOCAL_PATH=`cd $LOCAL_PATH && pwd`

#ln -sf libsdl-1.2.so $LOCAL_PATH/../../../obj/local/armeabi/libSDL.so

if [ \! -f ./configure ] ; then
	sh -c "./autogen.sh"
fi

#if [ \! -f Makefile ] ; then
	../setEnvironment.sh sh -c "./configure --host=arm-eabi"
#fi

../setEnvironment.sh sh -c "make > error.log 2>&1" && mv -f gameandwatch libapplication.so


