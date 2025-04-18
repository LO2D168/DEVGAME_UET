cmake_minimum_required(VERSION 3.30)
project(DevGame)
set(CMAKE_CXX_STANDARD 20)

# Must set the path to the main.cpp, for example: scripts/main.cpp if it is inside a folder
add_executable(${PROJECT_NAME} main.cpp
        Objects/Obj.h
)

# --- SDL2 SETUP ---
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules)
set(SDL2_PATH "SDL2-2.26.0/x86_64-w64-mingw32")
set(SDL2_image_PATH "SDL2_image-2.8.8/x86_64-w64-mingw32")
set(SDL2_mixer_PATH "SDL2_mixer-2.8.1/x86_64-w64-mingw32")
set(SDL2_ttf_PATH "SDL2_ttf-2.24.0/x86_64-w64-mingw32")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(SDL2_ttf REQUIRED)


include_directories(${SDL2_INCLUDE_DIR})
include_directories(${SDL2_image_INCLUDE_DIR})
include_directories(${SDL2_mixer_INCLUDE_DIR})
include_directories(${SDL2_ttf_INCLUDE_DIR})
include_directories(${CMAKE_SOURCE_DIR})

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY} ${SDL2_image_LIBRARY} ${SDL2_mixer_LIBRARY} ${SDL2_ttf_LIBRARY})

