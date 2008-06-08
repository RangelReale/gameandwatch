#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.61)
AC_INIT(gameandwatch, 0.1, rreale@bol.com.br)
AM_INIT_AUTOMAKE(gameandwatch, 0.1)
AC_CONFIG_SRCDIR([src/gamewatch.cpp])
AC_CONFIG_HEADER([config.h])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC

# initialize
CXXFLAGS="-DGW_USE_ZDATA"
LIBS="-lzzip"

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
AC_CHECK_LIB(SDL_mixer, Mix_OpenAudio, [], [AC_MSG_ERROR(SDL_mixer required)])
LIBS="$LIBS -lSDL_mixer"

# Check for SDL_ttf
AC_CHECK_LIB(SDL_ttf, TTF_Init, [], [AC_MSG_ERROR(SDL_ttf required)])
LIBS="$LIBS -lSDL_ttf"

# Check for SDL_image
AC_CHECK_LIB(SDL_image, IMG_Load, [], [AC_MSG_ERROR(SDL_image required)])
LIBS="$LIBS -lSDL_image"

# Check for SDL_gfx
AC_CHECK_LIB(SDL_gfx, zoomSurface, [], [AC_MSG_ERROR(SDL_gfx required)])
LIBS="$LIBS -lSDL_gfx"

# boost-filesystem
AX_BOOST_BASE([1.33.1])
AX_BOOST_FILESYSTEM
LIBS="$LIBS $BOOST_LDFLAGS -lboost_filesystem"

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_C_CONST
AC_TYPE_MODE_T
AC_STRUCT_TM

# Checks for library functions.
AC_CHECK_FUNCS([atexit])

AC_OUTPUT(Makefile src/Makefile data/Makefile doc/Makefile)

