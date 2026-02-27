# Die Hauptschleife

Die Hauptschleife nutzt alle anderen Teile des Programms um die Simulation
durchzuführen.

## Inputparameter

Für jetzt geht der Pseudocode davon aus, dass die Input-Parameter als struct
`InputParams` übergeben wird. `InputParams` hat folgende Felder:

- `PARK_NUM_SPACES` Anzahl der Stellplätze
- `MAX_PARK_DURATION` Maximale Parkdauer in Zeitschritten (Es ist unmöglich diese zu überschreiten)
- `PARK_CHANCE_ARRIVE` Ankunftswahrscheinlichkeit neuer Fahrzeuge pro Zeitschritt (0 - 1)
- `TOTAL_TIME_STEPS` Anzahl der simulierten Zeitschritte
- `RNG_SEED` Seed für `rand()`

## Statistik

Alle Statistikvariablen werden in einem struct `Stats` gespeichert. Der
Pseudocode markiert folgende Funktionen als Zugriffe auf die Statistiken:

- `statistics_car_leave()` - Save car leaving in statistics
- `statistics_car_arrive()` - Save car arriving in statistics
- `statistics_car_enqueu()` - Save car enqueue in statistics
