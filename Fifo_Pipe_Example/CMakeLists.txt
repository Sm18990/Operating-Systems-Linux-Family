cmake_minimum_required(VERSION 3.23)
project(PipeTest)

set(CMAKE_CXX_STANDARD 14)

add_executable(PipeTest main.c ErrorHandling.c ErrorHandling.h )
