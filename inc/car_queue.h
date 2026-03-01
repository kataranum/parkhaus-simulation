/**
 * File: car_queue.h
 * Description: A Queue representing a literal queue of cars waiting until they
 *              can park in the parking lot. Implemented as a reverse linked
                list.
 */

#ifndef CAR_QUEUE_H
#define CAR_QUEUE_H

#include "car.h"

/**
 * @brief A node in CarQueue containing a single car
 * 
 * The queue is a linked list ordered from front to back, so the "next" car is
 * one car more in back of the queue. The backmost car has NULL for p_next.
 */
typedef struct CarNode {
    /** The car */
    Car car;
    /** Pointer to the car in back, NULL if backmost car */
    struct CarNode *p_behind;
} CarNode;

/**
 * @brief A queue of cars
 *
 * The queue is a linked list where each node will point to the node in back.
 *
 * p_front points to the front of the queue, where dequeueing will pop cars
 * from.
 *
 * p_back points to the back of the queue, where enqueueing will add cars to.
 */
typedef struct {
    /** Pointer to frontmost car node */
    CarNode *p_front;
    /** Pointer to backmost car node */
    CarNode *p_back;
    /** Length of the queue */
    unsigned int length;
} CarQueue;

CarQueue queue_init();

void queue_delete(CarQueue *p_queue);

void enqueue(CarQueue *p_queue, Car car);

Car dequeue(CarQueue *p_queue);

int is_empty(CarQueue queue);

#endif
