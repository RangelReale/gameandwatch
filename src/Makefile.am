AM_CPPFLAGS=-DDATADIR='$(datadir)'
# what flags you want to pass to the C compiler & linker
#CFLAGS = --pedantic -Wall -std=c99 -O2
#LDFLAGS =

# this lists the binaries to produce, the (non-PHONY, binary) targets in
# the previous manual Makefile
bin_PROGRAMS = gameandwatch

if DEVEL_DEVICE
DEVSRC = devices/dev_banana.cpp devices/dev_banana.h devices/dev_sleepwlk.cpp devices/dev_sleepwlk.h \
	devices/dev_dkong.cpp devices/dev_dkong.h devices/deveng_vtech_banana.cpp devices/deveng_vtech_banana.h
else
DEVSRC =
endif

gameandwatch_SOURCES = device.cpp device.h gamelist.cpp gamelist.h gamewatch.cpp gwdefs.h menu.cpp menu.h platform.cpp platform.h \
	plat/plat_sdl.cpp plat/plat_sdl.h plat/SDL_rwops_zzip.c plat/SDL_rwops_zzip.h \
	devices/dev_defendo.cpp devices/dev_defendo.h devices/deveng_vtech_monkey.cpp devices/deveng_vtech_monkey.h devices/dev_monkey.cpp \
	devices/dev_monkey.h devices/dev_pirate.cpp devices/dev_pirate.h devices/deveng_vtech.cpp devices/deveng_vtech.h \
	devices/deveng_vtech_condor.cpp devices/deveng_vtech_condor.h devices/dev_condor.cpp devices/dev_condor.h \
	devices/dev_pancake.cpp devices/dev_pancake.h devices/dev_rollerc.cpp devices/dev_rollerc.h $(DEVSRC)


