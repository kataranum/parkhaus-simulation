#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <simulation.h>
#include <exit_codes.h>

const long RNG_SEEDS[] = {
    123,
    67,
    90,
};
const int RNG_SEED_AMOUNT = sizeof(RNG_SEEDS) / sizeof(RNG_SEEDS[0]);

/*
Die Funktion run_simulation() wird nicht getestet, da diese praktisch alle
anderen Funktionen von hier in einen Prozess bündelt und selber nicht wirklich
was eigenes macht. Außerdem währe es an dem Punkt schon kein Unit Test mehr, da
das eigentlich die gesamt Simulationsschleife ist.

Die anderen Funktionen, die von run_simulation() aufgerufen werden, werden
natürlich getestet.
*/

// default values for most unit tests
#define PARK_NUM_SPACES 10
#define PARK_MAX_TIME 10
#define PARK_CHANCE_ARRIVE 0.5
#define TOTAL_TIME_STEPS 100

// Create SimulationData with default values
SimulationData get_simdata_default(long seed) {
    InputParams params;
    params.park_num_spaces = PARK_NUM_SPACES;
    params.park_max_time = PARK_MAX_TIME;
    params.park_chance_arrive = 0.5;
    params.total_time_steps = TOTAL_TIME_STEPS;
    params.rng_seed = seed;

    Statistics *p_stats = calloc(1, sizeof(*p_stats));

    if (p_stats == NULL)
    {
        exit(EXIT_FAIL_MALLOC);
    }

    SimulationData data;
    data.params = params;
    data.current_step = 0;
    data.p_stats = p_stats;
    data.parking_lot = init_parking_lot(PARK_NUM_SPACES);
    data.waiting_cars = queue_init();

    return data;
}

// Free all memory allocated from get_simdata_default()
void free_simdata(SimulationData *p_data) {
    free(p_data->p_stats);
    free_parking_lot(&p_data->parking_lot);
    queue_delete(&p_data->waiting_cars);
}

void test_remove_due_cars(void) {
    SimulationData data = get_simdata_default(0);
    data.current_step = 8;

    // first car, parking longer than allowed, so should leave
    data.parking_lot.p_array[0].id = 0;
    data.parking_lot.p_array[0].time_arrival_park = 0;
    data.parking_lot.p_array[0].time_arrival_queue = 0;
    data.parking_lot.p_array[0].time_park_duration = 5;

    // second car, parking duration still not exceeded
    data.parking_lot.p_array[1].id = 1;
    data.parking_lot.p_array[1].time_arrival_park = 0;
    data.parking_lot.p_array[1].time_arrival_queue = 0;
    data.parking_lot.p_array[1].time_park_duration = 10;

    // third car, arrived later so parking duration also not exceeded
    data.parking_lot.p_array[2].id = 2;
    data.parking_lot.p_array[2].time_arrival_park = 5;
    data.parking_lot.p_array[2].time_arrival_queue = 0;
    data.parking_lot.p_array[2].time_park_duration = 5;

    // fourth car, parking duration exactly as allowed. Probably shouldn't leave yet.
    data.parking_lot.p_array[3].id = 3;
    data.parking_lot.p_array[3].time_arrival_park = 0;
    data.parking_lot.p_array[3].time_arrival_queue = 0;
    data.parking_lot.p_array[3].time_park_duration = 8;

    // fifth car, parking duration is 0, should leave immediately anyway
    data.parking_lot.p_array[4].id = 4;
    data.parking_lot.p_array[4].time_arrival_park = 0;
    data.parking_lot.p_array[4].time_arrival_queue = 0;
    data.parking_lot.p_array[4].time_park_duration = 0;

    // redundant check to see if data is in an expected state
    assert( car_empty(data.parking_lot.p_array[0]) == false );
    assert( car_empty(data.parking_lot.p_array[1]) == false );
    assert( car_empty(data.parking_lot.p_array[2]) == false );
    assert( car_empty(data.parking_lot.p_array[3]) == false );
    assert( car_empty(data.parking_lot.p_array[4]) == false );

    remove_due_cars(&data);

    assert( car_empty(data.parking_lot.p_array[0]) == true );
    assert( car_empty(data.parking_lot.p_array[1]) == false );
    assert( car_empty(data.parking_lot.p_array[2]) == false );
    assert( car_empty(data.parking_lot.p_array[3]) == false );
    assert( car_empty(data.parking_lot.p_array[4]) == true );

    free_simdata(&data);
}

void test_park_waiting_cars(void) {
    SimulationData data = get_simdata_default(0);

    const unsigned int EXCESS_CARS_AMOUNT = 5;
    
    // make parking lot completely full
    for (unsigned int i = 0; i < PARK_NUM_SPACES + EXCESS_CARS_AMOUNT; i++) {
        Car car = init_new_car(data.params);
        car.id = i;
        enqueue(&data.waiting_cars, car);
    }
    park_waiting_cars(&data);

    // all spots should be full now
    assert(data.waiting_cars.length == EXCESS_CARS_AMOUNT);
    for (int i = 0; i < PARK_NUM_SPACES; i++) {
        Car car = data.parking_lot.p_array[i];

        assert( ! car_empty(car) );
        assert(car.id < PARK_NUM_SPACES);
    }

    // calling park_waiting_cars() again shouldn't change anything
    park_waiting_cars(&data);
    assert(data.waiting_cars.length == EXCESS_CARS_AMOUNT);
    for (int i = 0; i < PARK_NUM_SPACES; i++) {
        Car car = data.parking_lot.p_array[i];

        assert( ! car_empty(car) );
        assert(car.id < PARK_NUM_SPACES);
    }

    free_simdata(&data);
}

// rough check that randomness is somewhat behaving as expected
void test_get_new_cars_arriving(long seed) {
    SimulationData data = get_simdata_default(seed);

    data.params.park_chance_arrive = 0.5;

    const int TEST_AMOUNT = 10000;
    for (int i = 0; i < TEST_AMOUNT; i++) {
        get_new_cars_arriving(&data);
    }

    // I'll define loose bounds that you'd need to be really unlucky to exceed
    // by pure chance
    assert(data.waiting_cars.length > TEST_AMOUNT * 0.1);
    assert(data.waiting_cars.length < TEST_AMOUNT * 0.9);

    free_simdata(&data);
}

// assert that a chance of 1.0 gurantees a new car each timestep
void test_chance_1(long seed) {
    SimulationData data = get_simdata_default(seed);

    data.params.park_chance_arrive = 1.0;

    const unsigned int TEST_AMOUNT = 1000;
    for (unsigned int i = 0; i < TEST_AMOUNT; i++) {
        get_new_cars_arriving(&data);
    }

    assert(data.waiting_cars.length == TEST_AMOUNT);

    free_simdata(&data);
}

// assert that a chance of 0.0 completely prevents cars from arriving
void test_chance_0(long seed) {
    SimulationData data = get_simdata_default(seed);

    data.params.park_chance_arrive = 0.0;

    const int TEST_AMOUNT = 1000;
    for (int i = 0; i < TEST_AMOUNT; i++) {
        get_new_cars_arriving(&data);
    }

    assert(data.waiting_cars.length == 0);

    free_simdata(&data);
}

int main(void) {
    test_remove_due_cars();
    test_park_waiting_cars();

    for (int i = 0; i < RNG_SEED_AMOUNT; i++) {
        long seed = RNG_SEEDS[i];
        test_get_new_cars_arriving(seed);
        test_chance_1(seed);
        test_chance_0(seed);
    }

    printf("All unit tests sind erfolgreich durchgelaufen.\n");
    return 0;
}
