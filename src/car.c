#include <car.h>
#include <stdlib.h>

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
Car init_new_car(InputParams params)
{
    Car car;
    car.id = get_unique_id();
    car.time_arrival_park = 0;
    car.time_arrival_queue = 0;
    car.time_park_duration = random_park_duration(params);

    return car;
}

int get_unique_id() {
    // TODO
}

/*
```PSEUDOCODE
RETURN (rand() % (params.max_park_duration - 1)) + 1
```
*/
int random_park_duration(InputParams params)
{
    return (rand() % (params.park_max_time - 1)) + 1;
}

/*
```PSEUDOCODE
RETURN car.id == -1
```
*/
bool car_empty(Car car) {
    return car.id == -1;
}
