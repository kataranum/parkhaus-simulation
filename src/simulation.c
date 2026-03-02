#include "../inc/simulation.h"

/*
```PSEUDOCODE
parking_lot = init_parking_lot(params.num_parking_spaces);
INIT_QUEUE Car waiting_cars;

srand(params.rng_seed);

SimulationData simulation_data;
simulation_data.params = params;
simulation_data.current_step = 0;
simulation_data.p_stats = p_stats;
simulation_data.parking_lot = parking_lot;
simulation_data.waiting_cars = waiting_cars;

FOR current_step IN 0 TO params.total_time_steps:
    simulation_data.current_step = current_step;

    get_new_cars_arriving(simulation_data);
    remove_due_cars(simulation_data);
    park_waiting_cars(simulation_data);

    output_timestep_statistics(
        simulation_data.current_step,
        get_occupancy(simulation_data.parking_lot),
        simulation_data.waiting_cars.length,
        TODO, // Sollte bei statistics_car_leave() berechnet werden
        simulation_data.waiting_cars.length, // Gesamtwartezeit der Schlange ist 1 Timestep pro Auto, also einfach die Länge der Schlange
        simulation_data.parking_lot.length,
    );
END FOR
``'
*/
void run_simulation(InputParams params, Statistics *p_stats) {
    // TODO
}

/*
```PSEUDOCODE
parking_lot = simulation_data.parking_lot;
FOR i IN 0 TO parking_lot.length:
    car = parking_lot.array[i];

    IF is_empty(car):
        CONTINUE
    END IF

    park_duration = simulation_data.current_step - car.time_arrival;

    IF park_duration < car.time_park_duration:
        CONTINUE
    END IF

    statistics_car_leave(car);
    parking_lot.array[i] = EMPTY_CAR;
    FREE car; // only in case car is allocated in heap
END FOR
```
*/
void remove_due_cars(SimulationData simulation_data) {
    // TODO
}

/*
```PSEUDOCODE
parking_lot = simulation_data.parking_lot;
waiting_cars = simulation_data.waiting_cars;

WHILE room_available(parking_lot) AND NOT waiting_cars.is_empty():
    new_car = waiting_cars.dequeue();
    new_car.arrival_time_park = simulation_data.current_step;

    available_spot = find_empty_space(parking_lot);
    statistics_car_arrive(new_car);
    parking_lot.array[available_spot] = new_car;
END WHILE
```
*/
void park_waiting_cars(SimulationData simulation_data) {
    // TODO
}

/*
```PSEUDOCODE
// Random float between 0 and 1
random_float = frand();

IF (random_float >= simulation_data.params.park_chance_arrive):
    RETURN
END IF

new_car = init_new_car();
new_car.time_arrival_queue = simulation_data.current_step;
simulation_data.waiting_cars.enqueue(new_car);

statistics_car_enqueue(new_car);
```
*/
void get_new_cars_arriving(SimulationData simulation_data) {
    // TODO
}
