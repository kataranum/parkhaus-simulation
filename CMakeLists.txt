cmake_minimum_required(VERSION 3.10)

project(parkhaus_simulation C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED on)

include_directories(inc)

add_executable(parkhaus
    src/main.c
)
