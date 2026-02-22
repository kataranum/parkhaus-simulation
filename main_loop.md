# Die Hauptschleife

Die Hauptschleife nutzt alle anderen Teile des Programms um die Simulation
durchzuführen.

## Pseudocode

### Inputparameter

Das Programm nutzt bestimmte Parameter die in `READ_INPUT_PARAMETERS` definiert
werden. Hier eine kurze beschreibung der Parameter:

- `PARK_NUM_SPACES` Anzahl der Stellplätze
- `PARK_MAX_TIME` Maximale Parkdauer (Es ist unmöglich diese zu überschreiten)
- `PARK_CHANCE_ARRIVE` Ankunftswahrscheinlichkeit neuer Fahrzeuge (0 - 1)
- `TOTAL_SIM_TIME` Gesamte Simulationszeit
- `TIME_STEP` Zeitspanne eines einzigen Simulationsschritts
- `RNG_SEED` Seed für `rand()`

### `Car` struct

Im Pseudocode muss ein struct `Car` verwendet werden, hier die Definition:

```
struct Car {
    unsigned int id;
    float time_arrival;
    float time_park_duration;
};
```

### Hauptschleife

```
PSEUDOCODE

READ_INPUT_PARAMETERS

num_time_steps = FLOOR(TOTAL_SIM_TIME / TIME_STEP)

ALLOCATE_ARRAY Car[PARK_NUM_SPACES] parking_lot
INIT_QUEUE Car waiting_cars

FOR i IN 0 TO num_time_steps:
    float current_time = i * TIME_STEP;

    // Enqueue new cars arriving this timestep
    get_new_cars_arriving(&waiting_cars);

    // Have all cars that are due to leave actually leave the lot
    remove_due_cars(current_time, &parking_lot);

    // Fill as many cars into the parking lot from the queue as possible
    park_waiting_cars(&parking_lot, &waiting_cars);
END FOR

output_statistics();

FREE waiting_cars
FREE parking_lot
EXIT

remove_due_cars(current_time, parking_lot):
    FOR j IN 0 TO PARK_NUM_SPACES:
        Car car = parking_lot[j];

        if is_empty(car):
            CONTINUE
        end if

        float time_park = current_time - car.time_arrival;

        if time_park < car.time_park_duration:
            CONTINUE
        end if

        car_leave(car);
        parking_lot[j] = NULL
        FREE car;
    END FOR

park_waiting_cars(parking_lot, waiting_cars):
    WHILE room_available(&parking_lot) AND !waiting_cars.is_empty():
        Car new_car = waiting_cars.dequeue();
        new_car.time_arrival = current_time;

        int available_spot = find_empty_space(&parking_lot);
        parking_lot[available_spot] = new_car;
    END WHILE

```
