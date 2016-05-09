cmake_minimum_required(VERSION 2.8)
project (LispSSS)

add_compile_options("-std=c++1y")

file(GLOB SOURCES src/*.cpp src/functions/*.cpp src/data_types/*.cpp )

add_library(${PROJECT_NAME} STATIC ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC src/ src/functions/ src/data_types/)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ".")

find_package(LibFFI REQUIRED)

if (LIBFFI_FOUND)
    target_include_directories(${PROJECT_NAME} PUBLIC ${LIBFFI_INCLUDE_DIRS})
    target_link_libraries(${PROJECT_NAME} ${LIBFFI_LIBRARIES})
endif()
