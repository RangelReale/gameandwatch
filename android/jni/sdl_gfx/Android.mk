LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := sdl_gfx

LOCAL_CFLAGS := -O3 -I$(LOCAL_PATH) -I$(LOCAL_PATH)/.. \
                -I$(LOCAL_PATH)/../SDL/include -I$(LOCAL_PATH)/include -Os

LOCAL_CPP_EXTENSION := .cpp

# Note this simple makefile var substitution, you can find even simpler examples in different Android projects
LOCAL_SRC_FILES := $(notdir $(wildcard $(LOCAL_PATH)/*.c))

LOCAL_SHARED_LIBRARIES := SDL

include $(BUILD_SHARED_LIBRARY)

