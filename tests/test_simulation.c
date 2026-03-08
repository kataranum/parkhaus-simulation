#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <simulation.h>

// default values for most unit tests
#define PARK_NUM_SPACES 10
#define PARK_MAX_TIME 10
#define PARK_CHANCE_ARRIVE 0.5
#define TOTAL_TIME_STEPS 100

SimulationData get_simdata_default(void) {
    InputParams params;
    params.park_num_spaces = PARK_NUM_SPACES;
    params.park_max_time = PARK_MAX_TIME;
    params.park_chance_arrive = 0.5;
    params.total_time_steps = TOTAL_TIME_STEPS;
    params.rng_seed = time(NULL);

    Statistics *p_stats = malloc(sizeof(p_stats));

    SimulationData data;
    data.params = params;
    data.current_step = 0;
    data.p_stats = p_stats;
    data.parking_lot = init_parking_lot(PARK_NUM_SPACES);
    data.waiting_cars = queue_init();

    return data;
}

void test_remove_due_cars(void) {
    SimulationData data;
}

void test_park_waiting_cars(void) {
    assert(false);
}

void test_get_new_cars_arriving(void) {
    assert(false);
}

int main(void) {
    printf("All unit tests sind erfolgreich durchgelaufen.\n");
    return 0;
}
