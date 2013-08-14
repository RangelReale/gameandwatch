SET( TARGET_BASE_NAME gameandwatch )
SET( LIB_NAME "${TARGET_BASE_NAME}Lib" )
SET( BUILD_AS_LIB OFF )

SET(BASE_SOURCE_PATH ".")


include_directories(${SDL_INCLUDE_DIR})
include_directories(${SDL_MIXER_INCLUDE_DIRS})
include_directories(${SDL_IMAGE_INCLUDE_DIRS})
include_directories(${SDL_TTF_INCLUDE_DIRS})
include_directories(${SDLGFX_INCLUDE_DIR})
include_directories(${ZZIPLIB_INCLUDE_DIR})
include_directories(${ZLIB_INCLUDE_DIRS})


IF(ANDROID)
	SET( BUILD_AS_LIB ON )
	SET( BUILD_AS_LIB_SHARED ON )
ELSEIF(IOS)
	SET( BUILD_AS_LIB ON )
	SET( BUILD_AS_LIB_STATIC ON )
ENDIF()

IF(WITH_DEVELDEVICES)
  add_definitions(-DGW_DEVEL_DEVICE)
ENDIF()

IF (BUILD_AS_LIB)
	add_definitions(-DBUILD_AS_LIB)
ENDIF()

#-----------------------------------------------------------------------------

SET( EXE_NAME "${TARGET_BASE_NAME}" )

# Add any source files here.
SET( EXE_SRCS
	${BASE_SOURCE_PATH}/device.cpp ${BASE_SOURCE_PATH}/gamelist.cpp
	${BASE_SOURCE_PATH}/menu.cpp ${BASE_SOURCE_PATH}/platform.cpp ${BASE_SOURCE_PATH}/plat/plat_sdl.cpp 
	${BASE_SOURCE_PATH}/plat/SDL_rwops_zzip.cpp ${BASE_SOURCE_PATH}/devices/dev_defendo.cpp 
	${BASE_SOURCE_PATH}/devices/deveng_vtech_monkey.cpp ${BASE_SOURCE_PATH}/devices/dev_monkey.cpp
	${BASE_SOURCE_PATH}/devices/dev_pirate.cpp ${BASE_SOURCE_PATH}/devices/deveng_vtech.cpp
	${BASE_SOURCE_PATH}/devices/deveng_vtech_condor.cpp ${BASE_SOURCE_PATH}/devices/dev_condor.cpp
	${BASE_SOURCE_PATH}/devices/dev_pancake.cpp ${BASE_SOURCE_PATH}/devices/dev_rollerc.cpp
	${BASE_SOURCE_PATH}/util/anyoption.cpp
)

# Add any include files here.
SET( EXE_INCS
	${BASE_INCLUDE_PATH}/device.h ${BASE_INCLUDE_PATH}/gamelist.h ${BASE_INCLUDE_PATH}/gwdefs.h
	${BASE_INCLUDE_PATH}/menu.h ${BASE_INCLUDE_PATH}/platform.h
	${BASE_INCLUDE_PATH}/plat/plat_sdl.h ${BASE_INCLUDE_PATH}/plat/SDL_rwops_zzip.h
	${BASE_INCLUDE_PATH}/devices/dev_defendo.h ${BASE_INCLUDE_PATH}/devices/deveng_vtech_monkey.h
	${BASE_INCLUDE_PATH}/devices/dev_monkey.h ${BASE_INCLUDE_PATH}/devices/dev_pirate.h
	${BASE_INCLUDE_PATH}/devices/deveng_vtech.h ${BASE_INCLUDE_PATH}/devices/deveng_vtech_condor.h 
	${BASE_INCLUDE_PATH}/devices/dev_condor.h ${BASE_INCLUDE_PATH}/devices/dev_pancake.h
	${BASE_INCLUDE_PATH}/devices/dev_rollerc.h ${BASE_INCLUDE_PATH}/util/anyoption.h
)

if (WITH_DEVELDEVICES)
	SET( EXE_SRCS ${EXE_SRCS}
		${BASE_SOURCE_PATH}/devices/dev_banana.cpp ${BASE_SOURCE_PATH}/devices/dev_sleepwlk.cpp
		${BASE_SOURCE_PATH}/devices/dev_dkong.cpp ${BASE_SOURCE_PATH}/devices/deveng_vtech_banana.cpp
	)
	SET( EXE_INCS ${EXE_INCS}
		${BASE_INCLUDE_PATH}/devices/dev_banana.h ${BASE_INCLUDE_PATH}/devices/dev_sleepwlk.h
		${BASE_INCLUDE_PATH}/devices/dev_dkong.h ${BASE_INCLUDE_PATH}/devices/deveng_vtech_banana.h
	)
endif()

#-----------------------------------------------------------------------------

SET(BASE_SRCS
		gamewatch.cpp
)
SET(BASE_INCS
)

# The executable.
IF (BUILD_AS_LIB_SHARED)
	ADD_LIBRARY(${EXE_NAME} SHARED ${BASE_SRCS} ${BASE_INCS} ${EXE_SRCS} ${EXE_INCS})
ELSEIF (BUILD_AS_LIB_STATIC)
	ADD_LIBRARY(${EXE_NAME} STATIC ${BASE_SRCS} ${BASE_INCS} ${EXE_SRCS} ${EXE_INCS})
ELSE()
	ADD_EXECUTABLE(${EXE_NAME} WIN32 ${BASE_SRCS} ${BASE_INCS} ${EXE_SRCS} ${EXE_INCS})
ENDIF()

TARGET_LINK_LIBRARIES ( ${EXE_NAME}
	${SDL_LIBRARY}
	${SDL_MIXER_LIBRARIES}
	${SDL_IMAGE_LIBRARIES}
	${SDL_TTF_LIBRARIES}
	${SDLGFX_LIBRARY}
	${ZLIB_LIBRARIES}
	${ZZIPLIB_LIBRARIES}
)

if (WIN32)
	TARGET_LINK_LIBRARIES ( ${EXE_NAME} ${SDLMAIN_LIBRARY} )
endif()

if (ANDROID)
	TARGET_LINK_LIBRARIES ( ${EXE_NAME} log )
endif()


install (TARGETS ${EXE_NAME}
	RUNTIME DESTINATION bin
	LIBRARY DESTINATION lib
)

