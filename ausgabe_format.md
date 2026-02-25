# Design des Ausgabeformats

Dieses Dokument beschreibt das geplante Format für die Konsolenausgabe und die Protokollierung in der Text-Datei.

## 1. Konsolenausgabe (Live-Statistiken)
Die Ausgabe erfolgt tabellarisch pro Zeitschritt, um eine gute Lesbarkeit während der Simulation zu gewährleisten.

```text
------------------------------------------------------------
SIMULATIONS-SCHRITT: 15 / 100
------------------------------------------------------------
Aktuelle Belegung:      42 / 50 Plätze (84.0 %)
Warteschlange:          5 Fahrzeuge
Durchschn. Wartezeit:   3.2 Zeitschritte
Vollbelegungs-Ticks:    4
Gesamt-Durchsatz:       28 Fahrzeuge
------------------------------------------------------------
```
## 2. Datei Ausgabe (End-Statistik)
Die Ausgabe der Gesamtstatistik erfolgt am Ende der Simulation in einer Textdatei `statistics.txt`.

```text
========================================
PARKHAUS-SIMULATION
Statistikbericht

Gesamtsimulationsdauer: 3600 s

Fahrzeuge gesamt: 250
Erfolgreich geparkt: 198
Abgewiesen (voll): 52

Durchschnittliche Wartezeit: 14.3 s
Maximale Wartezeit: 87 s

========================================
```
