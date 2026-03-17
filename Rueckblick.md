# Projektrückblick

## Wie haben Sie die Aufgabenstellung gelöst?

Teil 1
- Mündlich besprochen
- Ungefähre Aufgabenaufteilung
- Allgemeine Funktionen definiert
- Pseudocode geschrieben mit Vorlesungswissen
- Gegenseitige Kontrolle mit github
- Funktionen auf einander angepasst

Teil 2
- Funktionen von Fseudocode in C umschreiben
- Fehlerbehebung
- Paralell Unit-Tests geschrieben
- C-Make konfiguriert
- Fertigstellung und Kompilierfehlerbehebung
- Unit-Tests
- Final Tests

## Welche anderen Optionen hatten Sie im Team hinsichtlich der Struktur oder Umsetzung diskutiert?

Um einen erfolgreichen Durchlauf bei bestimmten Funktionen anzuzeigen, haben wir
für die Vorlesungsübungen normalerweise immer Integer benutzt. Damit lassen sich
mehrere mögliche Fehler anzeigen.

In unserem Fall hatten wir aber eher nur einen Wert für Erfolg (z.B. 0) und
einen anderen um einen Fehler anzuzeigen (1 oder -1).

Als Alternative haben wir uns entschieden, die Bibliothek `stdbool.h`
einzubinden sodass wir boolsche Werte benutzen konnten. Die betroffenen
Funktionen haben dann z.B. `true` bei Erfolg und `false` bei Fehlern
zurückgegeben.
 
## Warum haben Sie sich gegen die anderen Optionen entschieden bzw. für die gewählte Variante gemeinsam entschieden?

Bools sind intuitiver um Erfolg zu repräsentieren. Zudem sind diese auch
intuitiver in If-Statements.

Hier die Variante mit Integer:

```C
int success = failible_function(Param my_param);

if (success != 0)
{
    // Handle failure
}
```

Hier wird explizit geprüft, ob der Rückgabewert Null ist. Ist das nicht der
Fall, wird eine Ausnahmebehandlung gestartet. Man kann aber auch auf das `!= 0`
verzichten:

```C
int success = failible_function(Param my_param);

if (success)
{
    // Handle failure
}
```

Was jetzt aber komisch ist, ist dass der Code so aussieht, als würde die
Ausnahmebehandlung bei Erfolg ablaufen, nicht andersherum. Man sollte hier also
`success` in `failure` oder ähnliches umbenennen. Das ist aber nicht garantiert.
Sowas vergisst man leicht, was einen Bug verursacht, der schwer zu entdecken
ist.

Mit bools sieht das ganze so aus:

```C
bool success = failible_function(Param my_param);

if (!success)
{
    // Handle failure
}
```

Jetzt, solange man den Rückgabewert als Erfolgswert und nicht als Fehlerwert
sieht, passt es auch intuitiv mit If-Statements zusammen.

Der einzige Nachteile dieser Variante ist, dass bei einem Fehler man nicht sehen
kann, welcher Fehler genau passiert ist. Bei Integer Return Codes kann man
beliebig viele Fehlercodes definieren. Da wir aus Zeitgründen aber so wie so
keine Fehlercodes definiert haben, haben wir uns für Bools entschieden.

## Gab es Schwierigkeiten, Herausforderungen bei der Zusammenarbeit?

Eine der größten Herausforderungen im Projekt war der Zeitdruck, da nicht alle Teammitglieder jeden Tag am Projekt arbeiten konnten. Dadurch haben sich manche Aufgaben etwas nach hinten verschoben, vor allem gegen Ende der Bearbeitungszeit.
Außerdem haben Pull Requests teilweise länger gedauert, weil Änderungen nicht immer sofort geprüft und gemergt werden konnten. Das hat stellenweise den Arbeitsfluss gebremst, besonders wenn Aufgaben voneinander abhängig waren.

## Was ist Ihnen im Team einfach gefallen bzw. sehr gut gelungen?

Sehr gut funktioniert haben die regelmäßigen Team‑Besprechungen, in denen wir den aktuellen Stand, offene Aufgaben und Probleme besprochen haben. Dadurch waren alle immer auf dem gleichen Stand.
Auch die gegenseitige Unterstützung im Team war sehr hilfreich. Bei Schwierigkeiten konnte man jederzeit nachfragen und bekam Unterstützung, egal ob es um Code, Tests oder Verständnisfragen ging. Ideen konnten offen eingebracht und gemeinsam diskutiert werden.
Ebenfalls positiv war die Projektplanung, da die Aufgaben klar verteilt waren und jeder wusste, wofür jeder verantwortlich ist. Dadurch lief die Zusammenarbeit insgesamt sehr angenehm und strukturiert.
