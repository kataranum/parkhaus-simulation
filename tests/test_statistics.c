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

    struct SimulationData data = {0};

    data.params.total_time_steps = 100;
    data.params.park_num_spaces = 10;

    // Test 1 timestep
    data.current_step = 1;
    data.waiting_cars.length = 3;

    output_timestep_statistics(&stats, data);

    assert(stats.sum_queue_length == 3);
    assert(stats.max_queue_length == 3); 

    // Test 2 timestep 
    data.current_step = 2;
    data.waiting_cars.length = 5;

    output_timestep_statistics(&stats, data);

    assert(stats.sum_queue_length == 8);
    assert(stats.max_queue_length == 5); 

    //Test 3 timestep
    data.current_step = 3;
    data.waiting_cars.length = 2;

    output_timestep_statistics(&stats, data);

    assert(stats.sum_queue_length == 10);
    assert(stats.max_queue_length == 5);


    fclose(stats.log_file);

    FILE *file = fopen("test_log.txt", "r");
    assert(file != NULL);

    char buffer[2048];
    fread(buffer, 1, sizeof(buffer), file);

    fclose(file);

    assert(strstr(buffer, "SIMULATIONS-SCHRITT") != NULL);
    assert(strstr(buffer, "Warteschlange") != NULL);
}

void test_output_total_statistics()
{
    Statistics stats;
    init_statistics(&stats, "test_log_total.txt");

    InputParams params;

    params.total_time_steps = 10;
    params.park_num_spaces = 100;

    //Verbereitete Daten
    stats.sum_occupancy = 500;
    stats.sum_queue_length = 20;
    stats.sum_waiting_time = 100;
    stats.full_occupancy_steps = 2;
    stats.max_queue_length = 7;
    stats.finished_cars = 15;

    output_total_statistics(&stats, params);

    //Werte sind geblieben 
    assert(stats.sum_occupancy == 500);
    assert(stats.sum_queue_length == 20);
    assert(stats.finished_cars == 15);

    //File existiert 
    FILE *file = fopen("test_log_total.txt", "r");
    assert(file != NULL);

    char buffer[4096];
    fread(buffer, 1, sizeof(buffer), file);


    fclose(file);

    assert(strstr(buffer, "PARKHAUS-SIMULATION") != NULL);
    assert(strstr(buffer, "AUSLASTUNG") != NULL);
    assert(strstr(buffer, "WARTESCHLANGE") != NULL);
    assert(strstr(buffer, "WARTEZEIT") != NULL);
    assert(strstr(buffer, "FAHRZEUG-DURCHSATZ") != NULL);
}
int main()
{
    test_init_statistics();
    test_init_statistics_wrong();
    test_statistics_car_leave_once();
    test_statistics_car_leave_multiple();
    test_statistics_car_arrive_once();
    test_statistics_car_arrive_multiple();
    test_output_timestep_statistics();
    test_output_total_statistics();

    printf("Alle Tests erfolgreich bestanden!\n");

    return 0;
}
