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

### 1.3 Durchschnittliche Wartezeit der Fahrzeuge
*   **Berechnungslogik:** `Summe aller Wartezeiten (Zeitpunkt Einparken - Zeitpunkt Ankunft in Schlange) / Anzahl der Fahrzeuge, die die Schlange verlassen haben`
*   **Begründung:** Die Wartezeit ist ein kritischer Faktor für die Kundenzufriedenheit. Hohe Wartezeiten rechtfertigen bauliche Maßnahmen, um den Durchfluss zu erhöhen oder mehr Stellplätze zu schaffen, um die Servicequalität zu sichern.

### 1.4 Anzahl der Zeitschritte mit Vollbelegung
*   **Berechnungslogik:** Zähler, der in jedem Zeitschritt inkrementiert wird, in dem `belegte_plaetze == gesamt_kapazitaet` gilt.
*   **Begründung:** Diese Statistik hilft dabei, Lastspitzen zu identifizieren. Wenn das Parkhaus in einem großen Prozentsatz der Simulationszeit vollständig belegt ist, deutet dies auf verloren gegangenes Umsatzpotenzial hin.

### 1.5 Fahrzeug-Durchsatz
*   **Berechnungslogik:** Gesamtzahl der Fahrzeuge, die während der Simulationsdauer erfolgreich einen Stellplatz belegt und wieder verlassen haben.
*   **Begründung:** Der Durchsatz ermöglicht es dem Leiter, das Gesamtvolumen des Verkehrs zu beurteilen. Er dient als Basis für die Kalkulation von Verschleiß und Betriebskosten im Falle einer Erweiterung. Diese Kennzahl gibt eine Basis um beurteilen zu können, wie rellevant das Parkhaus ist.

## 2. Ausgabeformat
Die oben genannten Statistiken werden in jedem Zeitschritt sowie als finales Resümee wie folgt ausgegeben:
1.  **Konsole:** In einem tabellarischen, lesbaren Format zur Live-Überwachung.
2.  **Text-Datei:** Als persistentes Log zur späteren detaillierten Analyse durch die Geschäftsleitung.

