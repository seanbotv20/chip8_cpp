cmake_minimum_required (VERSION 3.1)

set (CMAKE_CXX_STANDARD 17)
# set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -Wextra")


project (chip8)
add_executable(chip8 src/main.cpp src/MemoryManager.cpp src/chip8.cpp  src/display.cpp)