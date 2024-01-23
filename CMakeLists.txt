project(test)
include_directories(.)
# file(GLOB SOURCES ".*.cpp")
add_executable(test ./main.cpp ./circularBuffer.cpp)