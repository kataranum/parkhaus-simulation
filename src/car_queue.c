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
CarQueue queue_init()
{
    
    CarQueue queue;
    queue.p_front = NULL;
    queue.p_back = NULL;
    queue.length = 0;
    return queue;
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
void queue_delete(CarQueue *p_queue)
{
    
    CarNode *p_node = p_queue->p_front;

    while (p_node != NULL)
    {
        CarNode *p_next = p_node->p_behind;
        free(p_node);
        p_node = p_next;
    }

    p_queue->p_front = NULL;
    p_queue->p_back = NULL;
    p_queue->length = 0;
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
p_queue->length++;
```
*/
void enqueue(CarQueue *p_queue, Car car)
{
    
    CarNode *p_new = malloc(sizeof(CarNode));
    p_new->car = car;
    p_new->p_behind = NULL;

    CarNode *p_old_backmost = p_queue->p_back;

    if (p_old_backmost != NULL)
    {
        p_old_backmost->p_behind = p_new;
    }
    else
    {
        p_queue->p_front = p_new;
    }

    p_queue->p_back = p_new;
    p_queue->length++;
}

/*
```PSEUDOCODE
Car *p_frontmost = p_queue->p_front;

IF p_frontmost == NULL:
    RETURN 0
END IF

*p_car = p_frontmost->car;
CarNode *p_new_frontmost = p_frontmost->p_behind;

free(p_frontmost);
p_frontmost = NULL;
p_queue->p_front = p_new_frontmost;
p_queue->length--;

IF p_queue->length == 0:
    p_queue->p_back = NULL;
END IF

RETURN car;
```
*/
int dequeue(CarQueue *p_queue, Car *p_car) {
    
    CarNode *p_frontmost = p_queue->p_front;

    if (p_frontmost == NULL)
    {
        return 0;
    }

    *p_car = p_frontmost->car;
    CarNode *p_new_frontmost = p_frontmost->p_behind;

    free(p_frontmost);
    p_frontmost = NULL;
    p_queue->p_front = p_new_frontmost;
    p_queue->length--;

    if (p_queue->length == 0)
    {
        p_queue->p_back = NULL;
    }

    return 1;
}

/*
```PSEUDOCODE
RETURN queue.length == 0;
```
*/
int is_empty(CarQueue queue) {
    // TODO
}
