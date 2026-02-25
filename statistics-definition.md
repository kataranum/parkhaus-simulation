# Konzept: Analyse-Statistiken für die Parkhaus-Simulation

Dieses Dokument beschreibt die geplanten Statistiken zur Bewertung der Auslastung des Parkhauses „Rauenegg“ sowie die Begründung ihrer Relevanz für mögliche bauliche Erweiterungen.

## 1. Übersicht der geplanten Statistiken

Gemäß den Anforderungen werden 5 Kennzahlen/Statistiken benötigt.

### 1.1 Durchschnittliche Auslastung (in %)
*   **Begründung:** Diese Kennzahl bietet dem Parkhausleiter einen Überblick über die generelle Kapazitätsausnutzung. Eine dauerhaft hohe Durchschnittsauslastung (z. B. > 90 %) ist das primäre Indiz dafür, dass das Parkhaus zu klein dimensioniert ist und eine Erweiterung wirtschaftlich sinnvoll wäre.

### 1.2 Maximale und durchschnittliche Warteschlangenlänge 
*   **Berechnungslogik:** 
    *   *Durchschnitt:* `Summe der Fahrzeuge in der Schlange pro Zeitschritt / Simulationsdauer`
    *   *Maximum:* Der höchste während der Simulation erreichte Wert der Schlangenlänge.
*   **Begründung:** Da die Warteschlange dynamisch verwaltet wird, zeigt ihre Länge direkt die Überlastung an. Lange Schlangen führen zu Staus im Umfeld des Parkhauses und signalisieren, dass Kunden abgewiesen werden oder unzumutbare Wartezeiten entstehen.Ebenso kann so das Umfeld des Parkhauses strukturiert werden, um gegebene lange Warteschlangen zu kompensieren.


