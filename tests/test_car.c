#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <car.h>

void test_init(void) {
    Car car = init_new_car();

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
        }
    }
}

void test_random_park_duration(void) {
    assert(false);
}

void test_is_empty(void) {
    assert(false);
}

int main(void) {
    test_init();
    test_unique_id();
    test_random_park_duration();
    test_is_empty();

    printf("Alle unit tests sind erfolgreich durchgelaufen\n");
    return 0;
}
