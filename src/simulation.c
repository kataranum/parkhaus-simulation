#include "../inc/simulation.h"

/*
```PSEUDOCODE
ALLOCATE_ARRAY Car[params.num_spaces] parking_lot;
INIT_QUEUE Car waiting_cars;

FOR current_step IN 0 TO params.total_time_steps:
    get_new_cars_arriving(params, waiting_cars, p_stats);
    remove_due_cars(current_step, parking_lot, p_stats);
    park_waiting_cars(parking_lot, waiting_cars, p_stats);

    output_timestep_statistics();
END FOR
``'
*/
void run_simulation(InputParams params, Stats *p_stats) {
    // TODO
}

/*
```PSEUDOCODE
FOR i IN 0 TO parking_lot.length:
    car = parking_lot.array[i];

    IF is_empty(car):
        CONTINUE
    END IF

    park_duration = current_step - car.time_arrival;

    IF park_duration < car.time_park_duration:
        CONTINUE
    END IF

    statistics_car_leave(car);
    parking_lot.array[i] = EMPTY_CAR;
    FREE car; // only in case car is allocated in heap
END FOR
```
*/
void remove_due_cars(unsigned int current_step, ParkingLot *p_parking_lot, Stats *p_stats) {
    // TODO
}

/*
```PSEUDOCODE
WHILE room_available(parking_lot) AND NOT waiting_cars.is_empty():
    new_car = waiting_cars.dequeue();
    new_car.arrival_time = current_step;

    available_spot = find_empty_space(parking_lot);
    statistics_car_arrive(new_car);
    parking_lot.array[available_spot] = new_car;
END WHILE
```
*/
void park_waiting_cars(unsigned int current_step, ParkingLot *p_parking_lot, QueueCars *p_waiting_cars, Stats *p_stats) {
    // TODO
}

/*
```PSEUDOCODE
// Random float between 0 and 1
random_float = frand();

IF (random_float >= PARK_CHANCE_ARRIVE):
    RETURN
END IF

new_car = init_new_car();
waiting_cars.enqueue(new_car);

statistics_car_enqueue(new_car);
```
*/
void get_new_cars_arriving(InputParams params, QueueCars *p_waiting_cars, Stats *p_stats) {
    // TODO
}

/*
```PSEUDOCODE
FOR i IN 0 TO parking_lot.length:
    car = parking_lot.array[i];

    IF is_empty(car):
        RETURN True;
    END IF
END FOR

RETURN False;
```
*/
int room_available(const ParkingLot *p_parking_lot) {
    // TODO
}

/*
```PSEUDOCODE
FOR i IN 0 TO parking_lot.length:
    car = parking_lot.array[i];

    IF is_empty(car):
        RETURN i;
    END IF
END FOR

RETURN -1
```
*/
int find_empty_space(const ParkingLot *p_parking_lot) {
    // TODO
}
