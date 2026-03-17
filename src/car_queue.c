#include <car_queue.h>
#include <stdlib.h>
#include <exit_codes.h>

CarQueue queue_init()
{
    CarQueue queue;
    queue.p_front = NULL;
    queue.p_back = NULL;
    queue.length = 0;
    return queue;
}

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

void enqueue(CarQueue *p_queue, Car car)
{
    CarNode *p_new = malloc(sizeof(CarNode));

    if (p_new == NULL)
    {
        exit(EXIT_FAIL_MALLOC);
    }

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

bool dequeue(CarQueue *p_queue, Car *p_car)
{
    CarNode *p_frontmost = p_queue->p_front;

    if (p_frontmost == NULL)
    {
        return false;
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

    return true;
}

bool queue_empty(CarQueue queue)
{
    return queue.length == 0;
}
