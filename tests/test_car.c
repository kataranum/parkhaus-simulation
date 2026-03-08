#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <car.h>

void test_init(void) {
    // InputParams remain unused here, but are required for code to compile
    InputParams params;
    params.max_park_duration = 1;

    Car car = init_new_car(params);

    assert(car.time_arrival_park == 0);
    assert(car.time_arrival_queue == 0);
}

void test_unique_id(void) {
    int ids[1024] = { 0 };
    const int TOTAL_TESTS = sizeof(ids) / sizeof(ids[0]);

    for (int index = 0; index < TOTAL_TESTS; index++) {
        ids[index] = get_unique_id();

        // check against all existing ids that there is no identical value
        for (int check_index = 0; check_index < index; check_index++) {
            assert(ids[index] != ids[check_index]);
            assert(ids[check_index] >= 0);
        }
    }
}

void test_random_park_duration(void) {
    const int MAX_PARK_TIME = 10;

    InputParams params;
    params.rng_seed = time(NULL); // I wonder if doing this randomly is idiomatic for unit tests
    params.park_max_time = MAX_PARK_TIME;

    const int TOTAL_TESTS = 1024;

    for (int i = 0; i < TOTAL_TESTS; i++) {
        int random_duration = random_park_duration(params);

        assert(random_duration <= MAX_PARK_TIME);
        assert(random_duration > 0);
    }
}

void test_invalid_park_duration(void) {
    InputParams params_1, params_2;
    params_1.rng_seed = time(NULL);
    params_1.park_max_time = 0;

    params_2.rng_seed = time(NULL);
    params_2.park_max_time = 1;

    const int TOTAL_TESTS = 1024;

    for (int i = 0; i < TOTAL_TESTS; i++) {
        int random_duration_1 = random_park_duration(params_1);
        int random_duration_2 = random_park_duration(params_2);

        assert(random_duration_1 == 1);
        assert(random_duration_2 == 1);
    }
}

void test_is_empty(void) {
    Car car_1, car_2, car_3, car_4;
    car_1.id = 67; // i am very sorry for choosing this number
    car_2.id = 0;
    car_3.id = -1;
    // negative IDs other than -1 are technically undefined by our means, but
    // I guess it's cleaner to ensure these are also handled in a sensible way
    car_4.id = -5;

    assert( is_empty(car_1) == false );
    assert( is_empty(car_2) == false );
    assert( is_empty(car_3) == true );
    assert( is_empty(car_4) == true );
}

int main(void) {
    test_init();
    test_unique_id();
    test_random_park_duration();
    test_invalid_park_duration
    test_invalid_park_duration();
    test_is_empty();

    printf("Alle unit tests sind erfolgreich durchgelaufen\n");
    return 0;
}
