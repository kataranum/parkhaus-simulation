#include <car.h>
#include <stdlib.h>

Car init_new_car(InputParams params)
{
    Car car;
    car.id = get_unique_id();
    car.time_arrival_park = 0;
    car.time_arrival_queue = 0;
    car.time_park_duration = random_park_duration(params);

    return car;
}

Car init_empty_car()
{
    Car car = { 0 };

    car.id = -1;

    return car;
}

int get_unique_id() {
    static int GLOBAL_ID = 0;

    return GLOBAL_ID++;
}

int random_park_duration(InputParams params)
{
    // return default for invalid values
    if (params.park_max_time <= 1)
    {
        return 1;
    }

    return (rand() % (params.park_max_time - 1)) + 1;
}

bool car_empty(Car car)
{
    return car.id < 0;
}
