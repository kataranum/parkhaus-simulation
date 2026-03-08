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
    assert(false);
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
