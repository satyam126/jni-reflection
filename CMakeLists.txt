cmake_minimum_required(VERSION 3.8)

# Project name
set(PROJECT_NAME jni-reflection)
project(${PROJECT_NAME})

# Directories
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

# C++ language standard
set(CMAKE_CXX_STANDARD 17)

# 64-bit mode
set(CMAKE_CXX_FLAGS -m64)

# Link everything statically
set(CMAKE_SHARED_LINKER_FLAGS -static)

# Required packages
find_package(JNI REQUIRED)

# Glob source files
set(SRC_T ${SRC_DIR}/*.cpp ${SRC_DIR}/*.c ${SRC_DIR}/*.hpp ${SRC_DIR}/*.h)
file(GLOB SRCS ${SRC_T})

# Create library
add_library(${PROJECT_NAME} SHARED ${SRCS})

# Add include directories
include_directories(${JNI_INCLUDE_DIRS})

# Remove lib prefix
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "")