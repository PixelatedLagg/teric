set(CMAKE_GENERATOR, "mingw32-make")
cmake_minimum_required(VERSION 3.22.5)
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")

project (teric)

file(GLOB SOURCES src/*.cpp)

add_executable(teric ${SOURCES})

target_include_directories(teric
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/src/include
)