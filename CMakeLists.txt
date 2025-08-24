cmake_minimum_required(VERSION 3.30)

project (
    lapine
    VERSION 0.1
    DESCRIPTION "procgen time again"
    LANGUAGES C CXX
)

set(RAYLIB_VERSION "5.5.0")
set(RAYLIB_CPP_VERSION "5.5.0")

set (CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})
set (CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(raygui)
include(raylib)
include(raylib_cpp)

add_subdirectory(src)
