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

# Dependencies among libraries

target_link_libraries(car PUBLIC
    user_input
)
target_link_libraries(car_queue PUBLIC
    car
)
target_link_libraries(parking_lot PUBLIC
    car
)
target_link_libraries(statistics PUBLIC
    simulation
)
target_link_libraries(simulation PUBLIC
    user_input
    car
    parking_lot
    car_queue
    statistics
)

# Unit test executables
add_executable(test_car
    tests/test_car.c
)
target_link_libraries(test_car
    user_input
)

# enable CTest

enable_testing()

add_test(
    NAME CarUnitTests
    COMMAND test_car
)

# Custom Target to execute tests
add_custom_target(run_tests
    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
    DEPENDS test_car
    COMMENT "Running unit tests"
)

# Program

add_executable(parkhaus
    src/main.c
)

target_link_libraries(parkhaus PRIVATE
    user_input
    statistics
    simulation
)

add_dependencies(parkhaus run_tests)
