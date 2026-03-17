#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <car_queue.h>

// check that fields are set correctly
void test_queue_init(void) {
    CarQueue q = queue_init();

    assert(q.p_front == NULL);
    assert(q.p_back == NULL);
    assert(q.length == 0);

    queue_delete(&q);
}

// check that fields are set properly after deletion and no SEGFAULT happens
void test_queue_delete(void) {
    CarQueue q = queue_init();

    // fields don't matter so don't initialize
    Car car;

    // make long queue to increase chance of SEGFAULT triggering if something
    // wrong is going on
    const int QUEUE_LEN = 100;
    for (int i = 0; i < QUEUE_LEN; i++) {
        enqueue(&q, car);
    }

    queue_delete(&q);

    assert(q.p_front == NULL);
    assert(q.p_back == NULL);
    assert(q.length == 0);
}

// deleting an empty queue shouldn't do anything
void test_queue_delete_empty(void) {
    CarQueue q = queue_init();

    queue_delete(&q);

    assert(q.p_front == NULL);
    assert(q.p_back == NULL);
    assert(q.length == 0);
}

// check that enqueueing works and also is ordered correctly
void test_enqueue(void) {
    CarQueue q = queue_init();

    assert(q.length == 0);

    // check enqueueing step by step
    const int AMOUNT_CARS = 10;
    for (int id = 0; id < AMOUNT_CARS; id++) {
        Car car;
        car.id = id;
        enqueue(&q, car);

        assert(q.length == id + 1),

        assert(q.p_front->car.id == 0);
        assert(q.p_back->car.id == id);

        assert(q.p_back->p_behind == NULL);
    }

    // check queue in final form
    int id = 0;
    CarNode *p_node = q.p_front;
    while (p_node != NULL) {
        assert(p_node->car.id == id);

        if (id < AMOUNT_CARS - 1) {
            assert(p_node->p_behind != NULL);
        }
        else {
            assert(p_node->p_behind == NULL);
        }

        p_node = p_node->p_behind;
        id++;
    }

    assert(id == AMOUNT_CARS);

    queue_delete(&q);
}

// check that dequeueing works and also in correct order
// check "dequeueing" and empty queue as well
void test_dequeue(void) {
    CarQueue q = queue_init();

    const int AMOUNT_CARS = 10;
    for (int i = 0; i < AMOUNT_CARS; i++) {
        Car car;
        car.id = i;
        enqueue(&q, car);
    }

    for (int i = 0; i < AMOUNT_CARS; i++) {
        Car dequeued;
        bool result = dequeue(&q, &dequeued);

        assert(result);
        assert(dequeued.id == i);
        assert(q.length == AMOUNT_CARS - i - 1);
    }

    const int SOME_ID = 123;
    Car dequeued;
    dequeued.id = SOME_ID;
    bool result = dequeue(&q, &dequeued);

    assert(result == false);
    assert(dequeued.id == SOME_ID); // dequeued shall not be touched on error
    assert(q.length == 0);

    queue_delete(&q);
}

void test_is_empty(void) {
    CarQueue q = queue_init();

    assert(queue_empty(q) == true);

    // fields don't matter so don't initialize
    Car some_car;
    enqueue(&q, some_car);

    assert(queue_empty(q) == false);

    dequeue(&q, &some_car);

    assert(queue_empty(q) == true);

    queue_delete(&q);

    assert(queue_empty(q) == true);
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
