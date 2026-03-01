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

/*
```PSEUDOCODE
CarNode *p_new = malloc(sizeof(p_new));
p_new->car = car;
p_new->p_behind = NULL;

CarNode *p_old_backmost = p_queue->p_back;
IF (p_old_backmost != NULL):
    p_old_backmost->p_behind = p_new;
ELSE:
    p_queue->p_front = p_new;
END IF
p_queue->p_back = p_new;
```
*/
void enqueue(CarQueue *p_queue, Car car) {
    // TODO
}

/*
```PSEUDOCODE
Car *p_frontmost = p_queue->p_front;
Car car = p_frontmost->car;
CarNode *p_new_frontmost = p_frontmost->p_behind;

free(p_frontmost);
p_frontmost = NULL;
p_queue->p_front = p_new_frontmost;

RETURN car;
```
*/
Car dequeue(CarQueue *p_queue) {
    // TODO
}

/*
```PSEUDOCODE
RETURN queue.length == 0;
```
*/
int is_empty(CarQueue queue) {
    // TODO
}
