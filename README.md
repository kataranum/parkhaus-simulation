# Parkhaus Simulation

[GitHub Repo](https://github.com/kataranum/parkhaus-simulation.git)
[Projekt Canbanboard](https://github.com/users/kataranum/projects/2)

Gruppenprojekt "Parkhaus-Simulation" für Vorlesung Programmieren I von Christian
Braunagel.

Gruppenmitglieder:

- Maxim Mandrossa (Bert-gg)
- Luis Dentler (LuisDentler)
- Kevin Müller (kataranum)

Wir habe den Pseudocode aus Teil 1 gelöscht, weil der C-Code jetzt vorhanden ist.
Da der C-Code verbessert wurde, macht es keinen Sinn den veralteten Pseudocode zu behalten.

Die Flowcharts sind unter `flowcharts/`

Zusätzliche Dokumentation, die nicht spezifisch auf eine Funktion ist, ist unter
`docs/`.

## Unit tests

So gut wie jede Funktion hat mindestens einen Unit Test. Ausnahmen sind User
Input und Die Hauptsimulationsschleife `run_simulation`.

User Input ist allgemein schwer automatisiert zu testen, aber Unterfunktionen
wie die String-zu-Zahl Parser haben Unit tests. Nur die Nutzereingabe selbst
nicht.

Die Hauptschleife `run_simulation` ist praktisch das gesamte Programm und ruft
nur andere von uns implementiere Funktionen auf. Die aufgerufenen Funktionen
haben dahingegen eigene Unit Tests.

## Build mit CMake

Das Projekt kann mit CMake kompiliert werden. Dafür folgende Befehle ausführen:

```BASH
cmake -S . -B build   # Muss nur ein mal ausgeführt werden
cmake --build build
```

CMake sollte ebenfalls automatisch alle Unit-Tests kompilieren und ausführen.

Die ausführbare Datei ist dann im Build-Ordner als `parkhaus` oder
`parkhaus.exe` zu finden.

## Anmerkung zu Versionierung & Teamverteilung

Gegen Ende des Projekts war kataranum (Kevin Müller) zuständig für Kleinigkeiten
wie Anpassen der Formattierung auf die Conventions der Vorlesung. Daher
erscheint das Bild von `git blame` ein wenig verfälscht, als hätte kataranum
mehr gemacht, als tatsächlich stimmt.

Hier die gedachte Teamverteilung:

**Bert-gg**: Car, CarQueue, ParkingLot, Util, User input

**LuisDentler**: Statistics, Statistics & ParkingLot Unit tests, Ausgabe

**kataranum**: Simulation, Parser, restliche Unit Tests, CMake, Fehlerbehebung
