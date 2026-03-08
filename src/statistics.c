/*
 * File: statistics.c
 * Description: Implementation of the statistics module for the
 *              parking garage simulation.
 */

#include "../inc/statistics.h"
#include "../inc/simulation.h"
#include <stdio.h>

/*---------------------------------------------------------------*/
/* static module variables                                       */
/*---------------------------------------------------------------*/


/*---------------------------------------------------------------*/
/* Initialization 
/*---------------------------------------------------------------*/
/*
PSEUDOCODE

FUNKTION init_statistik(dateiname):
    // Sicheres Öffnen der datei gewährleisten
    WENN dateiname IST NULL ODER pointer auf Struct IST NULL:
        GIB -1 ZURÜCK
    stats->log_datei = öffne_datei_zum_schreiben(dateiname)
    WENN stats->log_datei IST NULL:
        GIB -1 ZURÜCK

    // Variablen zurücksetzen
    stats->sum_occupancy        = 0;
    stats->sum_waiting_time     = 0;
    stats->sum_queue_length     = 0;
    stats->max_queue_length     = 0;
    stats->full_occupancy_steps = 0;
    stats->finished_cars        = 0;

    GIB 0 ZURÜCK
*/
/*---------------------------------------------------------------*/

int init_statistics(Statistics *stats, const char *filename)
{
    //Richtige Parameterübergabe sicherstellen 
    if ((stats == NULL) ||(filename == NULL))
    {
        return -1;
    }
    //Datei öffnen
    stats->log_file = fopen(filename, "w");
    //Überprüfen ob öffnen funktioniert hat 
    if (stats->log_file == NULL)
    {
        return -1;
    }
    //VAriablen zurücksetzen 
    stats->sum_occupancy = 0;
    stats->sum_waiting_time = 0;
    stats->sum_queue_length = 0;
    stats->max_queue_length = 0;
    stats->full_occupancy_steps = 0;
    stats->finished_cars = 0;

    return 0; 
}


/*---------------------------------------------------------------*/
/* Output statistic time step
/*---------------------------------------------------------------*/
/*
PSEUDOCODE

FUNKTION void output_timestep_statistics(Statistics *stats,SimulationData simulation_data)


    // Funktions Variablen
    avg_waiting_time_timestep = 0
    

    stats.sum_occupancy +=  simulation_data.occupancy
    stats.sum_waiting_time += simulation_data.waiting_time_parking_cars
    stats.sum_queue_length += simulation_data.queue_len
   
    
    // Aktualisierung der längsten Warteschlange
    WENN queue_len > stats.max_queue_laenge:
        stats.max_queue_laenge = simulation_data.queue_len

    // Hochzählen der static Variable wenn Parkhaus ausgelastet 
    WENN simulation_data.occupancy IST simulation_data.park_num_spaces:
        stats.full_occupancy_steps += 1
    
    //Berechnung durchschnitliche Wartezeit(Gesamtwartezeit aller bisher geparkten Autos(sum_waiting_time) / Anzahl aller geparkten autos (sum_occupancy))
    avg_waiting_time_timestep = stats.sum_waiting_time/stats.sum_occupancy

    // Anzahl an "fertigen" Autos in static Variable <stats.finished_cars>
    
    // Konsolenausgabe der Live-Statistik pro Zeitschritt
    print("Aktuelle Belegung", simulation_data.occupancy | "Warteschlange", simulation_data.queue_len| "Durchschn. Wartezeit", avg_waiting_time_timestep| "Vollbelegungs Ticks", stats.full_occupancy_steps| "Gesamt-Durchsatz",stats.finished_cars)

    //Ausgabe in Textfile
    WRITE TO FILE ... 
    
    //File ordnungsgemäß schließen
    IF p_log_file != NULL THEN
        CLOSE_FILE p_log_file
    END IF

ENDE
*/
/*---------------------------------------------------------------*/

void output_timestep_statistics(Statistics *stats,struct SimulationData simulation_data)
{
    //Funktions Variable
    float avg_waiting_time_timestep = 0.0;
    int current_occupancy = get_occupancy(simulation_data.parking_lot);
    float occupancy_percent = (current_occupancy / simulation_data.params.park_num_spaces) * 100.0;

    //Stats VAriablen mit Werten von Timestep befüllen
    stats->sum_occupancy += current_occupancy;
    stats->sum_waiting_time += ;
    stats->sum_queue_length += simulation_data.queue.length;
    
    // Aktualisierung der längsten Warteschlange
    if (simulation_data.queue.length > stats->max_queue_length)
    {
        stats->max_queue_length = simulation_data.queue.length;
    }
    
    // Hochzählen der static Variable wenn Parkhaus ausgelastet
    if (get_occupancy(simulation_data.parking_lot) == simulation_data.params.park_num_spaces)
    {
        stats->full_occupancy_steps += 1; 
    }
    //Berechnung durchschnitliche Wartezeit(Gesamtwartezeit aller bisher geparkten Autos(sum_waiting_time) / Anzahl aller geparkten autos (sum_occupancy))
    avg_waiting_time_timestep = stats->sum_waiting_time / stats->sum_occupancy;

    //Konsolenausgabe
    printf("------------------------------------------------------------\n");
    printf("SIMULATIONS-SCHRITT: %d / %d\n", simulation_data.current_step, simulation_data.params.total_time_steps);
    printf("------------------------------------------------------------\n");
    printf("Aktuelle Belegung:      %d / %d Plätze (%.1f %%)\n", current_occupancy, simulation_data.params.park_num_spaces, occupancy_percent);
    printf("Warteschlange:          %d Fahrzeuge\n", simulation_data.queue.length);
    printf("Durchschn. Wartezeit:   %.1f Zeitschritte\n", avg_waiting_time_timestep);
    printf("Vollbelegungs-Ticks:    %d\n", stats->full_occupancy_steps);
    printf("Gesamt-Durchsatz:       %d Fahrzeuge\n", stats->finished_cars);
    printf("------------------------------------------------------------\n");
     
    //Datei Ausgabe
    if (stats->log_file != NULL)
    {
        fprintf(stats->log_file, "------------------------------------------------------------\n");
        fprintf(stats->log_file, "SIMULATIONS-SCHRITT: %d / %d\n",simulation_data.current_step,simulation_data.params.total_time_steps);    
        fprintf(stats->log_file, "------------------------------------------------------------\n");
        fprintf(stats->log_file, "Aktuelle Belegung:      %d / %d Plätze (%.1f %%)\n",current_occupancy,simulation_data.params.park_num_spaces,occupancy_percent);
        fprintf(stats->log_file, "Warteschlange:          %d Fahrzeuge\n",simulation_data.queue.length);
        fprintf(stats->log_file, "Durchschn. Wartezeit:   %.1f Zeitschritte\n",avg_waiting_time_timestep);
        fprintf(stats->log_file, "Vollbelegungs-Ticks:    %d\n",stats->full_occupancy_steps);
        fprintf(stats->log_file, "Gesamt-Durchsatz:       %d Fahrzeuge\n",stats->finished_cars);
        fprintf(stats->log_file, "------------------------------------------------------------\n\n");
    }

}



/*---------------------------------------------------------------*/
/* End statistics output                                         */
/*---------------------------------------------------------------*/
/*
PSEUDOCODE

FUNCTION void output_total_statistics(Statistics *stats, InputParams params)

    // Funktionsvariablen
    avg_occupancy_percentage = 0;
    avg_queue_length = 0;
    avg_waiting_time = 0;
    full_occupancy_percentage = 0;


    //Berechnung der gesamten durchschnittlichen Auslastung ( ((Summe der Auslastungen(sum_occupancy) / Anzahl der Timesteps(total_time_steps)) / Anzahl gesamt Parkplätze(park_num_spaces) ) *100)
    avg_occupancy_percentage = ((stats.sum_occupancy / params.total_time_steps)/params.park_num_spaces)*100


    //Berechne durschnittliche Warteschlangenlänge(Länge der gesamten Wartenschlange(sum_queue_length) / Anzahl der gesamten Timesteps(total_time_steps))
    avg_queue_length = stats.sum_queue_length / params.total_time_steps 


    //Berechne durschnittliche Wartezeit (Summe aller Wartezeiten(sum_waiting_time) / Anzahl geparkter Autos (sum_occupancy))
    avg_waiting_time = stats.sum_waiting_time / stats.sum_occupancy


    // Zeit mit Vollbelegung (stats.full_occupancy_steps) und prozentaler Anteil an gesamter Dauer(total_time_steps)
    full_occupancy_percentage = (stats.full_occupancy_steps / params.total_time_steps) *100


    // Anzahl abgefertigter Autos -> stats.finished_cars


    // Ausgabe der Daten über Konsole
    printf("Simulationdauer", params.total_time_steps|"Gesamt Kap.",params.park_num_spaces,"Durchschn. Auslastung", avg_occupancy_percentage| "Durschn. Warteschlangenlänge",avg_queue_length |"Max. Warteschlangenlänge", stats.max_queue_laenge| "Durschschn. Wartezeit", avg_waiting_time| "Zeit mit voller Belegung", stats.full_occupancy_steps| "Prozentualer Anteil", full_occupancy_percentage| "Erfolgreich abgefertigete Autos", stats.finished_cars)
    
    //File öffnen und Schreiben
    WRITE TO FILE ... 
    
    //File ordnungsgemäß schließen
    IF p_log_file != NULL THEN
        CLOSE_FILE p_log_file
    END IF
ENDE
*/
/*---------------------------------------------------------------*/
void output_total_statistics(Statistics *stats, InputParams params)
{
    //Funktionsvariablen 
    float avg_occupancy_percentage = 0.0;
    float avg_queue_length = 0.0;
    float avg_waiting_time = 0.0;
    float full_occupancy_percentage = 0.0;

    //Berechnung der gesamten durchschnittlichen Auslastung ( ((Summe der Auslastungen(sum_occupancy) / Anzahl der Timesteps(total_time_steps)) / Anzahl gesamt Parkplätze(park_num_spaces) ) *100)
    avg_occupancy_percentage = ((stats->sum_occupancy / params.total_time_steps)/params.park_num_spaces)*100;

    //Berechne durschnittliche Warteschlangenlänge(Länge der gesamten Wartenschlange(sum_queue_length) / Anzahl der gesamten Timesteps(total_time_steps))
    avg_queue_length = stats->sum_queue_length / params.total_time_steps;

    //Berechne durschnittliche Wartezeit (Summe aller Wartezeiten(sum_waiting_time) / Anzahl geparkter Autos (sum_occupancy))
    avg_waiting_time = stats->sum_waiting_time / stats->sum_occupancy;

    // Zeit mit Vollbelegung (stats.full_occupancy_steps) und prozentaler Anteil an gesamter Dauer(total_time_steps)
    full_occupancy_percentage = (stats->full_occupancy_steps / params.total_time_steps) *100;

    // Ausgabe der Daten über Konsole
    printf("==================================================\n");
    printf("              PARKHAUS-SIMULATION\n");
    printf("                Statistikbericht\n");
    printf("==================================================\n\n");
    printf("Simulationsdauer:                     %d Zeitschritte\n", params.total_time_steps);
    printf("Gesamtkapazität Parkhaus:             %d Stellplätze\n\n", params.park_num_spaces);
    printf("--------------------------------------------------\n");
    printf("1. AUSLASTUNG\n");
    printf("--------------------------------------------------\n");
    printf("Durchschnittliche Auslastung:          %.1f %%\n\n", avg_occupancy_percentage);
    printf("--------------------------------------------------\n");
    printf("2. WARTESCHLANGE\n");
    printf("--------------------------------------------------\n");
    printf("Durchschnittliche Warteschlangenlänge: %.1f Fahrzeuge\n", avg_queue_length);
    printf("Maximale Warteschlangenlänge:          %d Fahrzeuge\n\n", stats->max_queue_length);
    printf("--------------------------------------------------\n");
    printf("3. WARTEZEIT\n");
    printf("--------------------------------------------------\n");
    printf("Durchschnittliche Wartezeit:           %.1f Zeitschritte\n\n", avg_waiting_time);
    printf("--------------------------------------------------\n");
    printf("4. VOLLBELEGUNG\n");
    printf("--------------------------------------------------\n");
    printf("Zeitschritte mit Vollbelegung:         %d\n", stats->full_occupancy_steps);
    printf("Anteil an Simulationsdauer:            %.1f %%\n\n", full_occupancy_percentage);
    printf("--------------------------------------------------\n");
    printf("5. FAHRZEUG-DURCHSATZ\n");
    printf("--------------------------------------------------\n");
    printf("Fahrzeuge erfolgreich abgefertigt:     %d\n\n", stats->finished_cars);
    printf("==================================================\n");

    //Dateiausgabe 
}


/*---------------------------------------------------------------*/
/* Car leave                                                     */
/*---------------------------------------------------------------*/
/*
PSEUDOCODE

FUNCTION void statistics_car_leave(Statistics *stats);

    stats->finished_cars ++
ENDE

*/
void statistics_car_leave(Statistics *stats)
{
    stats->finished_cars ++;
}   
