#include "../inc/car_queue.h"

/*
```PSEUDOCODE
CarQueue queue;
queue.p_front = NULL;
queue.p_back = NULL;
length = 0;
RETURN queue;
```
*/
CarQueue queue_init() {
    // TODO
}

/*
```PSEUDOCODE
CarNode *p_node = p_queue->p_front;

WHILE (p_node != NULL):
    CarNode *p_next = p_node->p_behind;
    free(p_node);
    p_node = p_next;
END WHILE

p_queue->p_front = NULL;
p_queue->p_back = NULL;
length = 0;
```
*/
void queue_delete(CarQueue *p_queue) {
    // TODO
}

void enqueue(CarQueue *p_queue, Car car) {
    // TODO
}

Car dequeue(CarQueue *p_queue) {
    // TODO
}

int is_empty(CarQueue queue) {
    // TODO
}
