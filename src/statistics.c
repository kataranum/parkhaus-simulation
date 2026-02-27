/*
 * File: statistics.c
 * Description: Implementation of the statistics module for the
 *              parking garage simulation.
 */

#include "../inc/statistics.h"
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
    /* Sicheres Öffnen der datei gewährleisten
    WENN dateiname IST NULL ODER pointer auf Struct IST NULL:
        GIB -1 ZURÜCK
    stats->log_datei = öffne_datei_zum_schreiben(dateiname)
    WENN stats->log_datei IST NULL:
        GIB -1 ZURÜCK

    /* Variablen zurücksetzen
    stats->total_time_steps     = 0;
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
 /*spätere implementierung*/   
}


/*---------------------------------------------------------------*/
/* Output statistic time step
/*---------------------------------------------------------------*/
/*
PSEUDOCODE

FUNKTION void output_timestep_statistics(current_step, occupancy, queue_len, finished_cars_timestep, waiting_time_parking_cars, PARK_NUM_SPACES);

    /* Funktions Variablen
    avg_waiting_time_timestep = 0
    

    /* Hochzählen der static Variablen für jeden Timestep
    total_time_steps += 1
    sum_occupancy += occupancy
    sum_waiting_time += waiting_time_parking_cars
    sum_queue_length += queue_len
    finished_cars += finished_cars_timestep
    
    /* Aktualisierung der längsten Warteschlange
    WENN queue_len > max_queue_laenge:
        max_queue_laenge = queue_len

    /* Hochzählen der static Variable wenn Parkhaus ausgelastet 
    WENN occupancy IST PARK_NUM_SPACES:
        full_occupancy_steps += 1
    
    /*Berechnung durchschnitliche Wartezeit(Gesamtwartezeit aller bisher geparkten Autos(sum_waiting_time) / Anzahl aller geparkten autos (sum_occupancy))
    avg_waiting_time_timestep = sum_waiting_time/sum_occupancy

    /* Anzahl an "fertigen" Autos in static Variable <finished_cars>
    
    /* Konsolenausgabe der Live-Statistik pro Zeitschritt
    print("Aktuelle Belegung", occupancy | "Warteschlange", queue_len| "Durchschn. Wartezeit", avg_waiting_time_timestep| "Vollbelegungs Ticks", full_occupancy_steps| "Gesamt-Durchsatz",finished_cars)

ENDE
*/
/*---------------------------------------------------------------*/

void output_timestep_statistics(int current_step, int occupancy, int queue_len, int finished_cars_timestep, int waiting_time_parking_cars, int PARK_NUM_SPACES)
{
    /*spätere Implementierung*/
}



/*---------------------------------------------------------------*/
/* End statistics output                                         */
/*---------------------------------------------------------------*/
/*
PSEUDOCODE

FUNCTION void output_total_statistics(PARK_NUM_SPACES)

    /* Funktionsvariablen
    avg_occupancy_percentage = 0;
    avg_queue_length = 0;
    avg_waiting_time = 0;
    full_occupancy_percentage = 0;


    /*Berechnung der gesamten durchschnittlichen Auslastung ( ((Summe der Auslastungen(sum_occupancy) / Anzahl der Timesteps(total_time_steps)) / Anzahl gesamt Parkplätze(PARK_NUM_SPACES) ) *100)
    avg_occupancy_percentage = ((sum_occupancy / total_time_steps)/PARK_NUM_SPACES)*100


    /*Berechne durschnittliche Warteschlangenlänge(Länge der gesamten Wartenschlange(sum_queue_length) / Anzahl der gesamten Timesteps(total_time_steps))
    avg_queue_length = sum_queue_length / total_time_steps 


    /*Berechne durschnittliche Wartezeit (Summe aller Wartezeiten(sum_waiting_time) / Anzahl geparkter Autos (sum_occupancy))
    avg_waiting_time = sum_waiting_time / sum_occupancy


    /* Zeit mit Vollbelegung (full_occupancy_steps) und prozentaler Anteil an gesamter Dauer(total_time_steps)
    full_occupancy_percentage = (full_occupancy_steps / total_time_steps) *100


    /* Anzahl abgefertigter Autos -> finished_cars


    /* Ausgabe der Daten über Konsole
    printf("Simulationdauer", total_time_steps|"Gesamt Kap.",PARK_NUM_SPACES,"Durchschn. Auslastung", avg_occupancy_percentage| "Durschn. Warteschlangenlänge",avg_queue_length |"Max. Warteschlangenlänge", max_queue_laenge| "Durschschn. Wartezeit", avg_waiting_time| "Zeit mit voller Belegung", full_occupancy_steps| "Prozentualer Anteil", full_occupancy_percentage| "Erfolgreich abgefertigete Autos", finished_cars)
    
    /*File öffnen und Schreiben
    WRITE TO FILE ... 
    
    /*File ordnungsgemäß schließen
    IF p_log_file != NULL THEN
        CLOSE_FILE p_log_file
    END IF
ENDE
*/
/*---------------------------------------------------------------*/
void output_total_statistics(int PARK_NUM_SPACES)
{
    /*spätere Implementierung*/
}
