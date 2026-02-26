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

- `frand()` - Get a random float between 0 (inclusive) and 1 (exclusive)
- `get_unique_id()` - Return a unique integer; shall never return same number twice
- `random_park_duration()` - Get random park duration (calculation model is yet to be defined)
- `room_available()` - Check if there are free spots in the parking lot
- `statistics_car_leave()` - Save car leaving in statistics
- `statistics_car_arrive()` - Save car arriving in statistics
- `statistics_car_enqueu()` - Save car enqueue in statistics
