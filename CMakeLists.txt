cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_OSX_ARCHITECTURES "arm64;x86_64")
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_INTERPROCEDURAL_OPTIMIZATION ON)

project(ZMenu7 VERSION 1.0.0 LANGUAGES CXX)

set(MACOS_SOURCES "")
if (APPLE)
  enable_language(OBJCXX)
  set(MACOS_SOURCES src/modules/keybinds/mouse/macos.mm)
endif()

file(GLOB_RECURSE SOURCES src/*.cpp)
add_library(${PROJECT_NAME} SHARED ${SOURCES} ${MACOS_SOURCES})

set_property(TARGET ${PROJECT_NAME} PROPERTY INTERPROCEDURAL_OPTIMIZATION TRUE)
target_include_directories(${PROJECT_NAME} PRIVATE src include)

execute_process(
    COMMAND git log -1 --format=%h
    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
    OUTPUT_VARIABLE GIT_HASH
    OUTPUT_STRIP_TRAILING_WHITESPACE
)
target_compile_definitions(${PROJECT_NAME} PRIVATE GIT_HASH="${GIT_HASH}")

if (WIN32)
  target_compile_definitions(${PROJECT_NAME} PRIVATE _CRT_SECURE_NO_WARNINGS)
  set_target_properties(${PROJECT_NAME} PROPERTIES WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

if (APPLE)
  set_source_files_properties(${MACOS_SOURCES} PROPERTIES SKIP_PRECOMPILE_HEADERS ON)
endif()

if (NOT DEFINED ENV{GEODE_SDK})
  message(FATAL_ERROR "Unable to find Geode SDK! Please define GEODE_SDK environment variable to point to Geode")
else()
  message(STATUS "Found Geode: $ENV{GEODE_SDK}")
endif()
add_subdirectory($ENV{GEODE_SDK} ${CMAKE_CURRENT_BINARY_DIR}/geode)

include(${CMAKE_SOURCE_DIR}/cmake/IncludeLibs.cmake)
target_link_libraries(${PROJECT_NAME} third_party)
setup_geode_mod(${PROJECT_NAME})
