LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := main

SDL_PATH := ../SDL
FREETYPE_PATH := ../freetype
SDLGFX_PATH := ../sdl_gfx
SDLTTF_PATH := ../sdl_ttf
SDLMIXER_PATH := ../sdl_mixer

LOCAL_CFLAGS += -DGW_PLAT_ANDROID -DGW_DEBUG
LOCAL_C_INCLUDES := $(LOCAL_PATH)/$(SDL_PATH)/include $(LOCAL_PATH)/$(SDLGFX_PATH)/include \
	$(LOCAL_PATH)/$(FREETYPE_PATH)/include $(LOCAL_PATH)/$(SDLTTF_PATH)/include \
	$(LOCAL_PATH)/$(SDLMIXER_PATH)/include $(LOCAL_PATH)/include

# Add your application source files here...
LOCAL_SRC_FILES := $(SDL_PATH)/src/main/android/SDL_android_main.cpp \
	gamewatch/src/device.cpp \
	gamewatch/src/gamelist.cpp \
	gamewatch/src/gamewatch.cpp \
	gamewatch/src/menu.cpp \
	gamewatch/src/platform.cpp \
	gamewatch/src/plat/plat_sdl.cpp \
	gamewatch/src/plat/plat_android.cpp \
	gamewatch/src/devices/deveng_vtech.cpp \
	gamewatch/src/devices/deveng_vtech_banana.cpp \
	gamewatch/src/devices/deveng_vtech_condor.cpp \
	gamewatch/src/devices/deveng_vtech_monkey.cpp \
	gamewatch/src/devices/dev_banana.cpp \
	gamewatch/src/devices/dev_condor.cpp \
	gamewatch/src/devices/dev_defendo.cpp \
	gamewatch/src/devices/dev_monkey.cpp \
	gamewatch/src/devices/dev_pancake.cpp \
	gamewatch/src/devices/dev_pirate.cpp \
	gamewatch/src/devices/dev_rollerc.cpp \
	gamewatch/src/util/anyoption.cpp

LOCAL_SHARED_LIBRARIES := SDL sdl_mixer sdl_gfx sdl_ttf 
LOCAL_STATIC_LIBRARIES := freetype jpeg png

LOCAL_LDLIBS := -lGLESv1_CM -llog

#APP_LIB_DEPENDS := $(foreach LIB, $(LOCAL_SHARED_LIBRARIES), $(abspath $(LOCAL_PATH)/../../obj/local/armeabi/lib$(LIB).so)) 
#APP_LIB_DEPENDS += $(foreach LIB, $(LOCAL_STATIC_LIBRARIES), $(abspath $(LOCAL_PATH)/../../obj/local/armeabi/lib$(LIB).a))

include $(BUILD_SHARED_LIBRARY)
