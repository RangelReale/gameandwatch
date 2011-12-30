LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := freetype

#APP_SUBDIRS := $(patsubst $(LOCAL_PATH)/%, %, $(shell find $(LOCAL_PATH)/src -type d))
APP_SUBDIRS = src/autofit \
src/base \
src/bdf \
src/cache \
src/cff \
src/cid \
src/gxvalid \
src/gzip \
src/lzw \
src/otvalid \
src/pcf \
src/pfr \
src/psaux \
src/pshinter \
src/psnames \
src/raster \
src/sfnt \
src/smooth \
src/truetype \
src/type1 \
src/type42 \
src/winfonts


LOCAL_CFLAGS := -Os $(foreach D, $(APP_SUBDIRS), -I$(LOCAL_PATH)/$(D)) \
				-I$(LOCAL_PATH)/include -DFT2_BUILD_LIBRARY


LOCAL_CPP_EXTENSION := .cpp

LOCAL_SRC_FILES := $(foreach F, $(APP_SUBDIRS), $(addprefix $(F)/,$(notdir $(wildcard $(LOCAL_PATH)/$(F)/*.cpp))))
LOCAL_SRC_FILES += $(foreach F, $(APP_SUBDIRS), $(addprefix $(F)/,$(notdir $(wildcard $(LOCAL_PATH)/$(F)/*.c))))

LOCAL_SHARED_LIBRARIES := 

LOCAL_STATIC_LIBRARIES := 

LOCAL_LDLIBS :=

include $(BUILD_STATIC_LIBRARY)
