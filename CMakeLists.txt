cmake_minimum_required(VERSION 3.10)

project(parkhaus_simulation C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED on)

include_directories(inc)

# Libraries

add_library(util
    src/util.c
)

add_library(car
    src/car.c
)

add_library(car_queue
    src/car_queue.c
)

add_library(parking_lot
    src/parking_lot.c
)

add_library(user_input
    src/user_input.c
)

add_library(statistics
    src/statistics.c
)

add_library(simulation
    src/simulation.c
)

# Program

add_executable(parkhaus
    src/main.c
)
