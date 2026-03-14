#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "../inc/simulation.h"
#include "../inc/statistics.h"
#include "../inc/car.h"



//Test for init_statistics()
void test_init_statistics()
{
    Statistics stats;
    int init_result = init_statistics(&stats, "test_log.txt");

    assert(init_result == 0);
    assert(stats.sum_occupancy == 0);
    assert(stats.sum_waiting_time == 0);
    assert(stats.sum_queue_length == 0);
    assert(stats.max_queue_length == 0);
    assert(stats.full_occupancy_steps == 0);
    assert(stats.finished_cars == 0);
    assert(stats.log_file != NULL);

    fclose(stats.log_file);
}

void test_init_statistics_wrong()
{
    //Init without stats
    int result = init_statistics(NULL, "test_log.txt");

    assert(result == -1);
}

void test_statistics_car_leave_once()
{
    Statistics stats = {0};

    statistics_car_leave(&stats);

    assert(stats.finished_cars == 1);
}

void test_statistics_car_leave_multiple()
{
    Statistics stats = {0};

    statistics_car_leave(&stats);
    statistics_car_leave(&stats);
    statistics_car_leave(&stats);
    statistics_car_leave(&stats);

    assert(stats.finished_cars == 4);
}

void test_statistics_car_arrive_once()
{
    Statistics stats = {0};

    Car car;
    car.time_arrival_queue = 5;
    car.time_arrival_park = 10;

    statistics_car_arrive(&stats, car);

    assert(stats.sum_waiting_time == 5);
}

void test_statistics_car_arrive_multiple()
{
    Statistics stats = {0};

    Car car1 = { .time_arrival_queue = 2, .time_arrival_park = 7 };
    Car car2 = { .time_arrival_queue = 4, .time_arrival_park = 9 };

    statistics_car_arrive(&stats, car1);
    statistics_car_arrive(&stats, car2);

    assert(stats.sum_waiting_time == 10);
}

void test_output_timestep_statistics()
{
    Statistics stats;
    init_statistics(&stats, "test_log.txt");

    SimulationData simulation_data = {0};

    simulation_data.params.total_time_steps = 100;
    simulation_data.params.park_num_spaces = 10;
    simulation_data.parking_lot.length = 0;  // Keine Autos geparkt
    simulation_data.parking_lot.p_array = NULL;

    // Test 1 timestep
    simulation_data.current_step = 1;
    simulation_data.waiting_cars.length = 3;

    output_timestep_statistics(&stats, simulation_data);

    assert(stats.sum_queue_length == 3);
    assert(stats.max_queue_length == 3);
    assert(stats.sum_occupancy == 0);  // Da keine Autos geparkt

    // Test 2 timestep 
    simulation_data.current_step = 2;
    simulation_data.waiting_cars.length = 5;

    output_timestep_statistics(&stats, simulation_data);

    assert(stats.sum_queue_length == 8);
    assert(stats.max_queue_length == 5);
    assert(stats.sum_occupancy == 0);  // Immer noch keine

    fclose(stats.log_file);
}
