#ifndef CAR_QUEUE_H
#define CAR_QUEUE_H

#include "car.h"

typedef struct CarNode {
    Car car;
    struct CarNode *p_next;
} CarNode;

typedef struct {
    CarNode *p_last;
    unsigned int length;
} CarQueue;

#endif
