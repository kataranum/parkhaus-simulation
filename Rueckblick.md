# Projektrückblick

## Wie haben Sie die Aufgabenstellung gelöst?

teil 1
- Mündlich besprochen
- ungefähre aufgaben aufteilung
- allgemeine funktionen definiert
- pseudocode geschrieben mit vorlesungswissen
- gegenseitige kontrolle mit github
- funktionen auf einander angepasst

teil 2
- funktionen von pseudocode in C um schreiben
- fehlerbehebung
- paralell unit tests geschrieben
- c-make konfiguriert
- fertigstellung und kompilierfehlerbehebung
- unit tests
- final test

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

- zeitdruck
- pull request haben lange gebraucht, weil nicht jeden tag gearbeitet

## Was ist Ihnen im Team einfach gefallen bzw. sehr gut gelungen?

- regelmäßigen besprechungen
- untereinander geholfen bei schwierigkeiten
- am konnte ideen besprechen und einbringen
- gute projektplanung
