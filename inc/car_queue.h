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

/**
 * @brief Init a new car queue
 *
 * @return CarQueue New empty CarQueue
 */
CarQueue queue_init();

/**
 * @brief Delete the whole queue from memory
 *
 * Frees all memory allocated by the queue. The struct can be reused without
 * calling `queue_init()` a second time.
 *
 * @param[in/out] p_queue Pointer to queue
 */
void queue_delete(CarQueue *p_queue);

/**
 * @brief Enqueue a new car to the back of the queue
 *
 * @param[in/out] p_queue Pointer to queue
 * @param[in] car Car to enqueue
 */
void enqueue(CarQueue *p_queue, Car car);

/**
 * @brief Pop the frontmost car off the queue and return it.
 * 
 * @param[in/out] p_queue Pointer to queue
 * @param[out] p_car Pointer to where dequeued car should be written
 @ return int 1 if dequeue was successful, 0 if not
 */
int dequeue(CarQueue *p_queue, Car *p_car);

/**
 * @brief Check if the queue is empty
 *
 * @param[in] queue Given queue
 * @return int (bool) whether the queue is empty
 */
int is_empty(CarQueue queue);

#endif
