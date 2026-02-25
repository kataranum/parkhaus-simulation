# Die Hauptschleife

Die Hauptschleife nutzt alle anderen Teile des Programms um die Simulation
durchzuführen.

## Pseudocode

### Inputparameter

Das Programm nutzt bestimmte Parameter die in `READ_INPUT_PARAMETERS` definiert
werden. Hier eine kurze beschreibung der Parameter:

- `PARK_NUM_SPACES` Anzahl der Stellplätze
- `PARK_MAX_TIME` Maximale Parkdauer in Zeitschritten (Es ist unmöglich diese zu überschreiten)
- `PARK_CHANCE_ARRIVE` Ankunftswahrscheinlichkeit neuer Fahrzeuge pro Zeitschritt (0 - 1)
- `TOTAL_TIME_STEPS` Anzahl der simulierten Zeitschritte
- `RNG_SEED` Seed für `rand()`

### `Car` struct

Im Pseudocode muss ein struct `Car` verwendet werden, hier die Definition:

```
struct Car {
    unsigned int id;
    int time_arrival;
    int time_park_duration;
};
```

### Hauptschleife

Noch nicht definierte Funktionen:

- `frng()` - Get a random float between 0 (inclusive) and 1 (exclusive)
- `get_unique_id()` - Return a unique integer; shall never return same number twice
- `random_park_duration()` - Get random park duration (calculation model is yet to be defined)
- `room_available()` - Check if there are free spots in the parking lot
- `car_leave()` - Save car leaving in statistics
- `car_arrive()` - Save car arriving in statistics

```
PSEUDOCODE

READ_INPUT_PARAMETERS

srand(RNG_SEED);

ALLOCATE_ARRAY Car[PARK_NUM_SPACES] parking_lot
INIT_QUEUE Car waiting_cars

FOR current_step IN 0 TO TOTAL_TIME_STEPS:
    // Enqueue new cars arriving this timestep
    get_new_cars_arriving(&waiting_cars);

    // Have all cars that are due to leave actually leave the lot
    remove_due_cars(current_step, &parking_lot);

    // Fill as many cars into the parking lot from the queue as possible
    park_waiting_cars(&parking_lot, &waiting_cars);

    output_timestep_statistics();
END FOR

output_total_statistics();

FREE waiting_cars
FREE parking_lot
EXIT

// Have cars over their max park time leave the parking lot
remove_due_cars(current_step, parking_lot):
    FOR j IN 0 TO PARK_NUM_SPACES:
        Car car = parking_lot[j];

        // Skip empty parking spaces
        if is_empty(car):
            CONTINUE
        end if

        int time_park = current_step - car.time_arrival;

        // Skip if car is not due to leave yet
        if time_park < car.time_park_duration:
            CONTINUE
        end if

        // Have the car leave the lot
        car_leave(car);
        parking_lot[j] = NULL
        FREE car;
    END FOR
END

// Dequeue waiting_cars until parking_lot is full (or queue becomes empty)
park_waiting_cars(parking_lot, waiting_cars):
    WHILE room_available(&parking_lot) AND !waiting_cars.is_empty():
        Car new_car = waiting_cars.dequeue();
        new_car.time_arrival = current_step;

        int available_spot = find_empty_space(&parking_lot);
        car_arrive(new_car);
        parking_lot[available_spot] = new_car;
    END WHILE
END

// Randomly enqueue new cars to the queue (also modify statistics)
get_new_cars_arriving(waiting_cars):
    // Random float between 0 and 1
    float random_float = frng();

    IF (random_float >= PARK_CHANCE_ARRIVE):
        RETURN
    END IF

    Car new_car = init_new_car();
    waiting_cars.enqueue(new_car);
END

// Create new car struct to be enqueued
init_new_car():
    Car car;

    car.id = get_unique_id();
    car.time_arrival = 0; // Time arrival will be set when car is parked
    car.time_park_duration = random_park_duration();

    RETURN car;
END
```
