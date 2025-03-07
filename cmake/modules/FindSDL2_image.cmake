# This module defines
# SDL2_image_LIBRARY, the name of the library to link against
# SDL2_image_FOUND, if false, do not try to link to SDL2_image
# SDL2_image_INCLUDE_DIR, where to find SDL.h
#
# This module responds to the the flag:
# SDL2_image_BUILDING_LIBRARY
# If this is defined, then no SDL2_imagemain will be linked in because
# only applications need main().
# Otherwise, it is assumed you are building an application and this
# module will attempt to locate and set the the proper link flags
# as part of the returned SDL2_image_LIBRARY variable.
#
# Don't forget to include SDLmain.h and SDLmain.m your project for the
# OS X framework based version. (Other versions link to -lSDL2_imagemain which
# this module will try to find on your behalf.) Also for OS X, this
# module will automatically add the -framework Cocoa on your behalf.
#
#
# Additional Note: If you see an empty SDL2_image_LIBRARY_TEMP in your configuration
# and no SDL2_image_LIBRARY, it means CMake did not find your SDL2_image library
# (SDL2_image.dll, libSDL2_image.so, SDL2_image.framework, etc).
# Set SDL2_image_LIBRARY_TEMP to point to your SDL2_image library, and configure again.
# Similarly, if you see an empty SDL2_imageMAIN_LIBRARY, you should set this value
# as appropriate. These values are used to generate the final SDL2_image_LIBRARY
# variable, but when these values are unset, SDL2_image_LIBRARY does not get created.
#
#
# $SDL2_imageDIR is an environment variable that would
# correspond to the ./configure --prefix=$SDL2_imageDIR
# used in building SDL2_image.
# l.e.galup  9-20-02
#
# Modified by Eric Wing.
# Added code to assist with automated building by using environmental variables
# and providing a more controlled/consistent search behavior.
# Added new modifications to recognize OS X frameworks and
# additional Unix paths (FreeBSD, etc).
# Also corrected the header search path to follow "proper" SDL guidelines.
# Added a search for SDL2_imagemain which is needed by some platforms.
# Added a search for threads which is needed by some platforms.
# Added needed compile switches for MinGW.
#
# On OSX, this will prefer the Framework version (if found) over others.
# People will have to manually change the cache values of
# SDL2_image_LIBRARY to override this selection or set the CMake environment
# CMAKE_INCLUDE_PATH to modify the search paths.
#
# Note that the header path has changed from SDL2_image/SDL.h to just SDL.h
# This needed to change because "proper" SDL convention
# is #include "SDL.h", not <SDL2_image/SDL.h>. This is done for portability
# reasons because not all systems place things in SDL2_image/ (see FreeBSD).

#=============================================================================
# Copyright 2003-2009 Kitware, Inc.
#
# Distributed under the OSI-approved BSD License (the "License");
# see accompanying file Copyright.txt for details.
#
# This software is distributed WITHOUT ANY WARRANTY; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# See the License for more information.
#=============================================================================
# (To distribute this file outside of CMake, substitute the full
#  License text for the above reference.)

# message("<FindSDL2_image.cmake>")

SET(SDL2_image_SEARCH_PATHS
        ~/Library/Frameworks
        /Library/Frameworks
        /usr/local
        /usr
        /sw # Fink
        /opt/local # DarwinPorts
        /opt/csw # Blastwave
        /opt
        ${SDL2_image_PATH}
)

FIND_PATH(SDL2_image_INCLUDE_DIR SDL2/SDL_image.h
        HINTS
        $ENV{SDL2_imageDIR}
        PATH_SUFFIXES include/SDL2_image include
        PATHS ${SDL2_image_SEARCH_PATHS}
)

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(PATH_SUFFIXES lib64 lib/x64 lib)
else()
    set(PATH_SUFFIXES lib/x86 lib)
endif()

FIND_LIBRARY(SDL2_image_LIBRARY_TEMP
        NAMES SDL2_image
        HINTS
        $ENV{SDL2_imageDIR}
        PATH_SUFFIXES ${PATH_SUFFIXES}
        PATHS ${SDL2_image_SEARCH_PATHS}
)

IF(NOT SDL2_image_BUILDING_LIBRARY)
    IF(NOT ${SDL2_image_INCLUDE_DIR} MATCHES ".framework")
        # Non-OS X framework versions expect you to also dynamically link to
        # SDL2_imagemain. This is mainly for Windows and OS X. Other (Unix) platforms
        # seem to provide SDL2_imagemain for compatibility even though they don't
        # necessarily need it.
        FIND_LIBRARY(SDL2_imageMAIN_LIBRARY
                NAMES SDL2_imagemain
                HINTS
                $ENV{SDL2_imageDIR}
                PATH_SUFFIXES ${PATH_SUFFIXES}
                PATHS ${SDL2_image_SEARCH_PATHS}
        )
    ENDIF(NOT ${SDL2_image_INCLUDE_DIR} MATCHES ".framework")
ENDIF(NOT SDL2_image_BUILDING_LIBRARY)

# SDL2_image may require threads on your system.
# The Apple build may not need an explicit flag because one of the
# frameworks may already provide it.
# But for non-OSX systems, I will use the CMake Threads package.
IF(NOT APPLE)
    FIND_PACKAGE(Threads)
ENDIF(NOT APPLE)

# MinGW needs an additional link flag, -mwindows
# It's total link flags should look like -lmingw32 -lSDL2_imagemain -lSDL2_image -mwindows
IF(MINGW)
    SET(MINGW32_LIBRARY mingw32 "-mwindows" CACHE STRING "mwindows for MinGW")
ENDIF(MINGW)

IF(SDL2_image_LIBRARY_TEMP)
    # For SDL2_imagemain
    IF(NOT SDL2_image_BUILDING_LIBRARY)
        IF(SDL2_imageMAIN_LIBRARY)
            SET(SDL2_image_LIBRARY_TEMP ${SDL2_imageMAIN_LIBRARY} ${SDL2_image_LIBRARY_TEMP})
        ENDIF(SDL2_imageMAIN_LIBRARY)
    ENDIF(NOT SDL2_image_BUILDING_LIBRARY)

    # For OS X, SDL2_image uses Cocoa as a backend so it must link to Cocoa.
    # CMake doesn't display the -framework Cocoa string in the UI even
    # though it actually is there if I modify a pre-used variable.
    # I think it has something to do with the CACHE STRING.
    # So I use a temporary variable until the end so I can set the
    # "real" variable in one-shot.
    IF(APPLE)
        SET(SDL2_image_LIBRARY_TEMP ${SDL2_image_LIBRARY_TEMP} "-framework Cocoa")
    ENDIF(APPLE)

    # For threads, as mentioned Apple doesn't need this.
    # In fact, there seems to be a problem if I used the Threads package
    # and try using this line, so I'm just skipping it entirely for OS X.
    IF(NOT APPLE)
        SET(SDL2_image_LIBRARY_TEMP ${SDL2_image_LIBRARY_TEMP} ${CMAKE_THREAD_LIBS_INIT})
    ENDIF(NOT APPLE)

    # For MinGW library
    IF(MINGW)
        SET(SDL2_image_LIBRARY_TEMP ${MINGW32_LIBRARY} ${SDL2_image_LIBRARY_TEMP})
    ENDIF(MINGW)

    # Set the final string here so the GUI reflects the final state.
    SET(SDL2_image_LIBRARY ${SDL2_image_LIBRARY_TEMP} CACHE STRING "Where the SDL2_image Library can be found")
    # Set the temp variable to INTERNAL so it is not seen in the CMake GUI
    SET(SDL2_image_LIBRARY_TEMP "${SDL2_image_LIBRARY_TEMP}" CACHE INTERNAL "")
ENDIF(SDL2_image_LIBRARY_TEMP)

# message("</FindSDL2_image.cmake>")

INCLUDE(FindPackageHandleStandardArgs)

FIND_PACKAGE_HANDLE_STANDARD_ARGS(SDL2_image REQUIRED_VARS SDL2_image_LIBRARY SDL2_image_INCLUDE_DIR)