#include "../inc/car.h"

/*
```PSEUDOCODE
Car car;

car.id = get_unique_id();
car.time_arrival_park = 0;
car.time_arrival_queue = 0;
car.time_park_duration = random_park_duration(params);

RETURN car
```
*/
Car init_new_car(InputParams params) {
    // TODO
}

/*
```PSEUDOCODE
RETURN (rand() % (params.max_park_duration - 1)) + 1
```
*/
int random_park_duration(InputParams params) {
    // TODO
}

/*
```PSEUDOCODE
RETURN car.id == -1
```
*/
int is_empty(Car car);
