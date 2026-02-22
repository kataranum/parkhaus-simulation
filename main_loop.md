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
