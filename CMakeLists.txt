cmake_minimum_required(VERSION 3.10)
project(uneviedefourmi LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SOURCES "./src/*.cpp")

add_executable(uneviedefourmi ${SOURCES})

target_include_directories(uneviedefourmi PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)