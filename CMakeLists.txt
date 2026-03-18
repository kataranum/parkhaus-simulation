cmake_minimum_required(VERSION 3.10)

project(parkhaus_simulation C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED on)

add_compile_options(-Wall -Wextra -Wpedantic)

include_directories(inc)

# Libraries

add_library(util
    src/util.c
)

add_library(test_utils
    src/test_utils.c
)

add_library(parse_num
    src/parse_num.c
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

target_link_libraries(user_input PRIVATE
    parse_num
)
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
    util
)

# Unit test executables
add_executable(test_util
    tests/test_util.c
)
target_link_libraries(test_util
    util
)

add_executable(test_parse_num
    tests/test_parse_num.c
)
target_link_libraries(test_parse_num
    test_utils
    parse_num
)

add_executable(test_car
    tests/test_car.c
)
target_link_libraries(test_car
    car
)

add_executable(test_car_queue
    tests/test_car_queue.c
)
target_link_libraries(test_car_queue
    car_queue
)

add_executable(test_parking_lot
    tests/test_parking_lot.c
)
target_link_libraries(test_parking_lot
    parking_lot
)

add_executable(test_statistics
    tests/test_statistics.c
)
target_link_libraries(test_statistics
    statistics
)

add_executable(test_simulation
    tests/test_simulation.c
)
target_link_libraries(test_simulation
    simulation
)

# enable CTest

enable_testing()

add_test(
    NAME UtilTests
    COMMAND test_util
)
add_test(
    NAME ParseTests
    COMMAND test_parse_num
)
add_test(
    NAME CarUnitTests
    COMMAND test_car
)
add_test(
    NAME CarQueueUnitTests
    COMMAND test_car_queue
)
add_test(
    NAME ParkingLotTests
    COMMAND test_parking_lot
)
add_test(
    NAME StatisticsTests
    COMMAND test_statistics
)
add_test(
    NAME SimulationUnitTests
    COMMAND test_simulation
)

# Custom Target to execute tests
add_custom_target(run_tests
    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
    DEPENDS
        test_util
        test_parse_num
        test_car
        test_car_queue
        test_parking_lot
        test_statistics
        test_simulation
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
