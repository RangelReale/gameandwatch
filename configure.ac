#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.61)
AC_INIT(gameandwatch, 0.3, rreale@bol.com.br)
AM_INIT_AUTOMAKE(gameandwatch, 0.3)
AC_CONFIG_SRCDIR([src/gamewatch.cpp])
AC_CONFIG_HEADER([config.h])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC

# initialize
CXXFLAGS="${CXXFLAGS} -DGW_USE_ZDATA"
#LIBS="-lzzip"

# parameters
AC_ARG_WITH(develdevices, [  --with-develdevices            enable in-development devices])

AC_MSG_CHECKING([if in-development devices should be included])
if test "$with_develdevices" == "yes"
then
	AC_DEFINE([GW_DEVEL_DEVICE], [], [Enable in-development devices])
	GW_DEVEL_DEVICE=true
	AC_SUBST(GW_DEVEL_DEVICE)
	AC_MSG_RESULT([yes])
else
	AC_MSG_RESULT([no])
fi
AM_CONDITIONAL(DEVEL_DEVICE, test x$GW_DEVEL_DEVICE = xtrue)

AC_ARG_ENABLE(plat-pandora, AS_HELP_STRING([--enable-plat-pandora], [enable the Pandora platform]))

AC_MSG_CHECKING([if the Pandora platform should be included])

AS_IF([test "x$enable_plat_pandora" = "xyes"], [
	AC_DEFINE([GW_PLAT_PANDORA], [], [Enable the Pandora platform])
	GW_PLAT_PANDORA=true
	AC_SUBST(GW_PLAT_PANDORA)
	AC_MSG_RESULT([yes])
],[
	AC_MSG_RESULT([no])
])
AM_CONDITIONAL(PLAT_PANDORA, test x$GW_PLAT_PANDORA = xtrue)

# Checks for libraries.

# Use the macro SDL provides to check the installed version of the SDL
# development environment.  Abort the configuration process if the
# minimum version we require isn't available.
SDL_VERSION=1.2.0
AM_PATH_SDL($SDL_VERSION,
            :,
	    AC_MSG_ERROR([*** SDL version $SDL_VERSION not found!])
)
# Add the SDL preprocessor flags and libraries to the build process
CFLAGS="$CFLAGS $SDL_CFLAGS"
CXXFLAGS="$CXXFLAGS $SDL_CFLAGS"
LIBS="$LIBS $SDL_LIBS"

# Check for SDL_mixer
#AC_CHECK_LIB(SDL_mixer, Mix_OpenAudio, [], [AC_MSG_ERROR(SDL_mixer required)])
LIBS="$LIBS -lsdl_mixer"

# Check for SDL_ttf
#AC_CHECK_LIB(SDL_ttf, TTF_Init, [], [AC_MSG_ERROR(SDL_ttf required)])
LIBS="$LIBS -lsdl_ttf"

# Check for SDL_image
#AC_CHECK_LIB(SDL_image, IMG_Load, [], [AC_MSG_ERROR(SDL_image required)])
LIBS="$LIBS -lsdl_image"

# Check for SDL_gfx
#AC_CHECK_LIB(SDL_gfx, zoomSurface, [], [AC_MSG_ERROR(SDL_gfx required)])
LIBS="$LIBS -lsdl_gfx"

# check for zzip
#PKG_CHECK_MODULES([ZZIP],[zziplib >= 0.10.75])
LIBS="$LIBS -lzzip"

CFLAGS="$CFLAGS $ZZIP_CFLAGS"
CXXFLAGS="$CXXFLAGS $ZZIP_CFLAGS"
LIBS="$LIBS $ZZIP_LIBS"

LIBS="$LIBS -lgcc"

LIBS="$LIBS /home/rreale/prog/sdk/android-ndk-r4-crystax/build/prebuilt/linux-x86/arm-eabi-4.4.0/arm-eabi/lib/libstdc++.a"

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_C_CONST
AC_TYPE_MODE_T
AC_STRUCT_TM

# Checks for library functions.
AC_CHECK_FUNCS([atexit])

AC_OUTPUT(Makefile src/Makefile data/Makefile doc/Makefile)

