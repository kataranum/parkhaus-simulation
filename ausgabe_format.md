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
==================================================
              PARKHAUS-SIMULATION
                Statistikbericht
==================================================

Simulationsdauer:                     3600 Zeitschritte
Gesamtkapazität Parkhaus:             200 Stellplätze

--------------------------------------------------
1. AUSLASTUNG
--------------------------------------------------
Durchschnittliche Auslastung:          87.4 %

--------------------------------------------------
2. WARTESCHLANGE
--------------------------------------------------
Durchschnittliche Warteschlangenlänge: 6.3 Fahrzeuge
Maximale Warteschlangenlänge:          21 Fahrzeuge

--------------------------------------------------
3. WARTEZEIT
--------------------------------------------------
Durchschnittliche Wartezeit:           18.7 Zeitschritte

--------------------------------------------------
4. VOLLBELEGUNG
--------------------------------------------------
Zeitschritte mit Vollbelegung:         742
Anteil an Simulationsdauer:            20.6 %

--------------------------------------------------
5. FAHRZEUG-DURCHSATZ
--------------------------------------------------
Fahrzeuge erfolgreich abgefertigt:    1 128

==================================================
```
