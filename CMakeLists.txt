cmake_minimum_required(VERSION 3.0.2)
project(conspiracy)

set(CXX_STANDARD 11)
set(CXX_STANDARD_REQUIRED ON)

# Set directory folders
set (SRC_DIR     "${PROJECT_SOURCE_DIR}/code")
set (ASSETS_DIR  "${PROJECT_SOURCE_DIR}/assets")
set (CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/install)

# Gets the list of files inside the src directory
file(GLOB_RECURSE SOURCES "${SRC_DIR}/*.cpp"
                          "${SRC_DIR}/*.c")

#### Compilation ####

# Compilation Flags
set(COMPILE_FLAGS "")

if (${CMAKE_CXX_COMPILER_ID} STREQUAL Clang)
    set(COMPILE_FLAGS "${COMPILE_FLAGS} -std=c++11 -W -Wall -fstack-protector-all -pedantic -Wshadow -O2 -g")
elseif (${CMAKE_CXX_COMPILER_ID} STREQUAL GNU)
    set(COMPILE_FLAGS "${COMPILE_FLAGS} -std=c++11 -W -Wall -fstack-protector-all -pedantic -Wshadow -O2 -g")
elseif (${CMAKE_CXX_COMPILER_ID} STREQUAL MSVC)
    set(COMPILE_FLAGS "${COMPILE_FLAGS} /Wall /W4")
endif()

# Cmake compilation flags redefinition
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMPILE_FLAGS}")

#### Dependencies ####

# Add engine
set (ENGINE_DIR "${PROJECT_SOURCE_DIR}/code/engine")
add_subdirectory(${ENGINE_DIR})
set (ENGINE_INCLUDE_DIR "${ENGINE_DIR}/include")
include_directories(${ENGINE_INCLUDE_DIR})

# Add game
set (GAME_DIR "${PROJECT_SOURCE_DIR}/code/game")
set (GAME_INCLUDE_DIR "${GAME_DIR}/include")
add_subdirectory(${GAME_DIR})
include_directories(${GAME_INCLUDE_DIR})

#### Executable ####

add_executable(conspiracy ${SOURCES})

target_link_libraries(conspiracy
                      engine
                      #game
                      SDL2 SDL2_image SDL2_ttf SDL2_mixer)

#### Custom Commands ####

# Copy assets folder to build
add_custom_command(TARGET conspiracy POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                   ${ASSETS_DIR} ${CMAKE_BINARY_DIR}/assets)

#### Install/Packaging ####

install(TARGETS conspiracy
  RUNTIME DESTINATION bin
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
)

install(DIRECTORY ${PROJECT_ASSETS_DIR}
  DESTINATION bin/
)

#TODO: Add SDL2 libraries to the install phase

include(CPack.cmake)
