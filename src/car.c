#include "../inc/car.h"

Car init_new_car(InputParams params)
{
    Car car;
    car.id = get_unique_id();
    car.time_arrival_park = 0;
    car.time_arrival_queue = 0;
    car.time_park_duration = random_park_duration(params);

    return car;
}

int random_park_duration(InputParams params)
{
    return (rand() % (params.park_max_time - 1)) + 1;
}

bool is_empty(Car car)
{
    return car.id == -1;
}
