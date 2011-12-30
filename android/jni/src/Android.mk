LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := main

SDL_PATH := ../SDL
FREETYPE_PATH := ../freetype
SDLGFX_PATH := ../sdl_gfx
SDLTTF_PATH := ../sdl_ttf
SDLMIXER_PATH := ../sdl_mixer

LOCAL_CFLAGS += -DGW_PLAT_ANDROID -DEXCLUDEGW_NO_SDL_GFX -DEXCLUDEGW_NO_SDL_MIXER -DEXCLUDEGW_NO_SDL_TTF -DGW_DEBUG
LOCAL_C_INCLUDES := $(LOCAL_PATH)/$(SDL_PATH)/include $(LOCAL_PATH)/$(SDLGFX_PATH)/include \
	$(LOCAL_PATH)/$(FREETYPE_PATH)/include $(LOCAL_PATH)/$(SDLTTF_PATH)/include \
	$(LOCAL_PATH)/$(SDLMIXER_PATH)/include $(LOCAL_PATH)/include

# Add your application source files here...
LOCAL_SRC_FILES := $(SDL_PATH)/src/main/android/SDL_android_main.cpp \
	src/device.cpp \
	src/gamelist.cpp \
	src/gamewatch.cpp \
	src/menu.cpp \
	src/platform.cpp \
	src/plat/plat_sdl.cpp \
	src/plat/plat_android.cpp \
	src/devices/deveng_vtech.cpp \
	src/devices/deveng_vtech_banana.cpp \
	src/devices/deveng_vtech_condor.cpp \
	src/devices/deveng_vtech_monkey.cpp \
	src/devices/dev_banana.cpp \
	src/devices/dev_condor.cpp \
	src/devices/dev_defendo.cpp \
	src/devices/dev_monkey.cpp \
	src/devices/dev_pancake.cpp \
	src/devices/dev_pirate.cpp \
	src/devices/dev_rollerc.cpp \
	src/util/anyoption.cpp

LOCAL_SHARED_LIBRARIES := SDL sdl_gfx sdl_ttf sdl_mixer

LOCAL_LDLIBS := -lGLESv1_CM -llog

include $(BUILD_SHARED_LIBRARY)
