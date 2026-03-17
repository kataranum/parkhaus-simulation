# Parkhaus Simulation

[GitHub Repo](https://github.com/kataranum/parkhaus-simulation.git)
[Projekt Canbanboard](https://github.com/users/kataranum/projects/2)

Gruppenprojekt "Parkhaus-Simulation" für Vorlesung Programmieren I von Christian
Braunagel.

Gruppenmitglieder:

- Maxim Mandrossa (Bert-gg)
- Luis Dentler (LuisDentler)
- Kevin Müller (kataranum)

Wir haben alle nötigen Funktionen C-Headerdateien definiert und vollständig
dokumentiert.

Jede definierte Funktion hat ebenfalls im C-File ausführlichen Pseudocode.

Die Flowcharts sind unter `flowcharts/`

Zusätzliche Dokumentation, die nicht spezifisch auf eine Funktion ist, ist unter
`docs/`.

## Build mit CMake

Das Projekt kann mit CMake kompiliert werden. Dafür folgende Befehle ausführen:

```BASH
cmake -S . -B build   # Muss nur ein mal ausgeführt werden
cmake --build build
```

CMake sollte ebenfalls automatisch alle Unit-Tests kompilieren und ausführen.

Die ausführbare Datei ist dann im Build-Ordner als `parkhaus` oder
`parkhaus.exe` zu finden.
