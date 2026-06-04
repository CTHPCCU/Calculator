cmake_minimum_required(VERSION 3.10)
project(Calculator)
set(CMAKE_CXX_STANDARD 17)
file(GLOB SOURCES "src/*.cpp")
add_executable(main ${SOURCES})
target_include_directories(main PRIVATE src)
 