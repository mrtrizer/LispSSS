cmake_minimum_required(VERSION 2.8)

project(LispSSS)

set(CMAKE_BUILD_TYPE Debug)

add_definitions("-std=c++1y")
add_definitions("-DGL_ES")
include_directories(
    "../../src/"
    "../../src/functions"
    "../../src/data_types"
)

file(GLOB SOURCES ../../src/*.cpp ../../src/functions/*.cpp ../../src/data_types/*.cpp ../lisp_console/*.cpp)
get_filename_component(result "../../src/externfunction.cpp" ABSOLUTE)
message(${result})
list(REMOVE_ITEM SOURCES "/home/trizer/Hobby/LispSSS/examples/lisp_web/../../src/externfunction.cpp"  )
message(${SOURCES})

set(EXECUTABLE_NAME LispSSS)

add_executable(${EXECUTABLE_NAME} ${SOURCES})

add_definitions(-DSDL_IMAGE_FOUND)

set(CMAKE_USE_RELATIVE_PATHS TRUE)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
