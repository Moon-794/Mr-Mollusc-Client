cmake_minimum_required(VERSION 3.6.0)
project (mrmollusc)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)
add_executable(mrmollusc ../src/main.cpp)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

target_link_libraries(mrmollusc ${SDL2_LIBRARIES})