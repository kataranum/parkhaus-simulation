#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <car_queue.h>

void test_queue_init(void) {
    CarQueue q = queue_init();

    assert(q.p_front == NULL);
    assert(q.p_back == NULL);
    assert(q.length == 0);

    queue_delete(&q);
}

void test_queue_delete(void) {
    CarQueue q = queue_init();

    // fields don't matter so don't initialize
    Car car;

    // make long queue to increase chance of SEGFAULT triggering if something
    // wrong is going on
    const int QUEUE_LEN = 100;
    for (int i = 0; QUEUE_LEN; i++) {
        enqueue(&q, car);
    }

    queue_delete(&q);

    assert(q.p_front == NULL);
    assert(q.p_back == NULL);
    assert(q.length == 0);
}

void test_queue_delete_empty(void) {
    CarQueue q = queue_init();

    queue_delete(&q);

    assert(q.p_front == NULL);
    assert(q.p_back == NULL);
    assert(q.length == 0);
}

void test_enqueue(void) {
    CarQueue q = queue_init();

    assert(q.length == 0);

    const int AMOUNT_CARS = 10;
    for (int id = 0; id < AMOUNT_CARS; id++) {
        Car car;
        car.id = id;
        enqueue(&q, car);

        assert(q.length == id + 1),

        assert(q.p_front->id == 0);
        assert(q.p_back->id == id);
    }

    queue_delete(&q);
}

void test_dequeue(void) {
    assert(false);
}

void test_is_empty(void) {
    assert(false);
}

int main(void) {
    test_queue_init();
    test_queue_delete();
    test_queue_delete_empty();
    test_enqueue();
    test_dequeue();
    test_is_empty();

    printf("Alle Unit Tests sind erfolgreich durchgelaufen.\n");
}
