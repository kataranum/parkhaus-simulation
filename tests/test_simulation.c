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

void free_simdata(SimulationData data) {
    free(data.p_stats);
    free_parking_lot(&data.parking_lot);
    queue_delete(&data.waiting_cars);
}

void test_remove_due_cars(void) {
    SimulationData data = get_simdata_default();
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
    assert( is_empty(data.parking_lot.p_array[0]) == false );
    assert( is_empty(data.parking_lot.p_array[1]) == false );
    assert( is_empty(data.parking_lot.p_array[2]) == false );
    assert( is_empty(data.parking_lot.p_array[3]) == false );
    assert( is_empty(data.parking_lot.p_array[4]) == false );

    remove_due_cars(data);

    assert( is_empty(data.parking_lot.p_array[0]) == true );
    assert( is_empty(data.parking_lot.p_array[1]) == false );
    assert( is_empty(data.parking_lot.p_array[2]) == false );
    assert( is_empty(data.parking_lot.p_array[3]) == false );
    assert( is_empty(data.parking_lot.p_array[4]) == true );

    free_simdata(data);
}

void test_park_waiting_cars(void) {
    SimulationData data = get_simdata_default();

    const int EXCESS_CARS_AMOUNT = 5;
    
    // make parking lot completely full
    for (int i = 0; i < PARK_NUM_SPACES + EXCESS_CARS_AMOUNT; i++) {
        Car car = init_new_car(data.params);
        car.id = i;
        enqueue(&data.waiting_cars, car);
    }
    park_waiting_cars(data);

    // all spots should be full now
    assert(data.waiting_cars.length == EXCESS_CARS_AMOUNT);
    for (int i = 0; i < PARK_NUM_SPACES; i++) {
        Car car = data.parking_lot.p_array[i];

        assert( ! is_empty(car) );
        assert(car.id < PARK_NUM_SPACES);
    }

    // calling park_waiting_cars() again shouldn't change anything
    park_waiting_cars(data);
    assert(data.waiting_cars.length == EXCESS_CARS_AMOUNT);
    for (int i = 0; i < PARK_NUM_SPACES; i++) {
        Car car = data.parking_lot.p_array[i];

        assert( ! is_empty(car) );
        assert(car.id < PARK_NUM_SPACES);
    }

    free_simdata(data);
}

void test_get_new_cars_arriving(void) {
    SimulationData data = get_simdata_default();

    data.params.park_chance_arrive = 0.5;

    const int TEST_AMOUNT = 10000;
    for (int i = 0; i < TEST_AMOUNT; i++) {
        test_get_new_cars_arriving(data);
    }

    // I'll define loose bounds that you'd need to be really unlucky to exceed
    // by pure chance
    assert(data.waiting_cars.length > TEST_AMOUNT * 0.1);
    assert(data.waiting_cars.length < TEST_AMOUNT * 0.9);

    free_simdata(data);
}

void test_chance_1(void) {
    SimulationData data = get_simdata_default();

    data.params.park_chance_arrive = 1.0;

    const int TEST_AMOUNT = 1000;
    for (int i = 0; i < TEST_AMOUNT; i++) {
        test_get_new_cars_arriving(data);
    }

    assert(data.waiting_cars.length == TEST_AMOUNT);

    free_simdata(data);
}

void test_chance_0(void) {
    SimulationData data = get_simdata_default();

    data.params.park_chance_arrive = 0.0;

    const int TEST_AMOUNT = 1000;
    for (int i = 0; i < TEST_AMOUNT; i++) {
        test_get_new_cars_arriving(data);
    }

    assert(data.waiting_cars.length == 0);

    free_simdata(data);
}

int main(void) {
    printf("All unit tests sind erfolgreich durchgelaufen.\n");
    return 0;
}
