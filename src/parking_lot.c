#include <parking_lot.h>
#include <stdlib.h>
#include <stdio.h>

ParkingLot init_parking_lot(unsigned int length)
{
    ParkingLot parking_lot;
    parking_lot.p_array = malloc(length * sizeof(*parking_lot.p_array));
    if (parking_lot.p_array == NULL)
    {
        fprintf(stderr, "Error: Memory allocation failed for parking lot.\n");
        exit(EXIT_FAILURE);
    }

    parking_lot.length = length;

    // initialize with empty cars
    for (unsigned int i = 0; i < length; i++)
    {
        Car *p_car = parking_lot.p_array + i;

        p_car->id = -1; // TODO: Do this per function
        p_car->time_arrival_park = 0;
        p_car->time_arrival_queue = 0;
        p_car->time_park_duration = 0;
    }

    return parking_lot;
}

void free_parking_lot(ParkingLot *p_parking_lot)
{
    free(p_parking_lot->p_array);
    p_parking_lot->p_array = NULL;
    p_parking_lot->length = 0;
}

int get_occupancy(ParkingLot parking_lot)
{
    int occupancy = 0;
    for (unsigned int i = 0; i < parking_lot.length; i++)
    {
        Car car = parking_lot.p_array[i];
        if (!car_empty(car))
        {
            occupancy++;
        }
    }
    return occupancy;
}

int room_available(ParkingLot parking_lot)
{
    for (unsigned int i = 0; i < parking_lot.length; i++)
    {
        Car car = parking_lot.p_array[i];
        if (car_empty(car))
        {
            return true;
        }
    }
    return false;
}

int find_empty_space(ParkingLot parking_lot)
{
    for (unsigned int i = 0; i < parking_lot.length; i++)
    {
        Car car = parking_lot.p_array[i];
        if (car_empty(car))
        {
            return i;
        }
    }
    return -1;
    
}
