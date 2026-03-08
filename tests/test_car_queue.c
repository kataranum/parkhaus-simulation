#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <car_queue.h>

void test_queue_init(void) {
    CarQueue q = queue_init();

    assert(q.p_front == NULL);
    assert(q.p_back == NULL);
    assert(q.length == NULL);
}

void test_queue_delete(void) {
    assert(false);
}

void test_enqueue(void) {
    assert(false);
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
    test_enqueue();
    test_dequeue();
    test_is_empty();

    printf("Alle Unit Tests sind erfolgreich durchgelaufen.\n");
}
