/*
 * File: statistics.c
 * Description: Implementation of the statistics module for the
 *              parking garage simulation.
 */

#include "statistics.h"
#include <stdio.h>

/*---------------------------------------------------------------*/
/* static module variables                                       */
/*---------------------------------------------------------------*/

static FILE *p_log_file = NULL;

/* Time tracking */
static int total_time_steps = 0;

/* Occupancy */
static int sum_occupancy = 0;
static int *occupancy_timestep = NULL;

/*Waiting time*/
static int sum_waiting_time = 0;

/* Queue statistics */
static int sum_queue_length = 0;
static int max_queue_length = 0;

/* Full occupancy */
static int full_occupancy_steps = 0;



/*---------------------------------------------------------------*/
/* Initialization 
/*---------------------------------------------------------------*/
/*
PSEUDOCODE
FUNKTION init_statistik(dateiname):
    WENN dateiname IST NULL:
        GIB -1 ZURÜCK
    log_datei = öffne_datei_zum_schreiben(dateiname)
    WENN log_datei IST NULL:
        GIB -1 ZURÜCK

    // Variablen zurücksetzen
    total_time_steps        = 0
    sum_occupancy           = 0
    sum_waiting_time        = 0
    sum_queue_length        = 0
    max_queue_laenge        = 0
    full_occupancy_steps    = 0
    occupancy_timestep[]    = 0

    schreibe_log("==== PARKHAUS-SIMULATION LOG ====")
    GIB 0 ZURÜCK
*/
/*---------------------------------------------------------------*/

int init_statistics(const char *filename)
{
 /*spätere implementierung*/   
}


/*---------------------------------------------------------------*/
/* Output statistic time step
/*---------------------------------------------------------------*/
/*
PSEUDOCODE
FUNKTION void output_timestep_statistics(current_step, occupancy, queue_len, finished_cars, waiting_time_parking_cars, PARK_NUM_SPACES);
    /* Hochzählen der Variablen für jeden Timestep
    total_time_steps += 1
    sum_occupancy += occupancy
    sum_waiting_time += waiting_time_parking_cars
    sum_queue_length += queue_len
    
    /*Berechnung der Auslastung pro Timestep in Prozent 
    auslastung_timestep[current_step] = (occupancy/PARK_NUM_SPACES)*100

    WENN queue_len > max_queue_laenge:
        max_queue_laenge = queue_len

    WENN occupancy IST PARK_NUM_SPACES:
        full_occupancy_steps += 1
    
    /*Berechnung durchschnitliche Wartezeit(Gesamtwartezeit aller bisher geparkten autos/ Anzahl aller geparkten autos (gesamt_belegung))
    durchschnitt_wartezeit = sum_waiting_time/sum_occupancy

    gesamt_durchlauf += finished_cars
    
    print("Aktuelle Belegung", occupancy | "Warteschlange", queue_len| "Durchschn. Wartezeit", durchschnitt_wartezeit| "Vollbelegungs Ticks", full_occupancy_steps| "Gesamt-Durchsatz",gesamt_durchlauf)

*/
/*---------------------------------------------------------------*/

void output_timestep_statistics(int current_step, int occupancy, int queue_len, int finished_cars, int waiting_time_parking_cars, int PARK_NUM_SPACES);{
    /*spätere Implementierung*/
}

/*---------------------------------------------------------------*/
/* End statistics output                                         */
/*---------------------------------------------------------------*/
/*
PSEUDOCODE
FUNCTION void output_total_statistics()
    /* Funktionsvariablen
    gesamt_zeit = sim_dauer
    sum_auslastung = 0


    /*Durchlauf aller timesteps und abspeichern der prozentualen Auslastungen
    FÜR i=0 bis sim_dauer-1
        sum_auslastung += auslastung_timestep[i]

    /*Berechnung der gesamten durchschnittlichen Auslastung(Summe der timestep_Auslastungen / Anzahl der Timesteps)
    durchschnitt_auslastung = sum_auslastung / sim_dauer

    /*Berechne durschnittliche Warteschlangenlänge
    duchschnitt_wartequeue = gesamt_wartequeue / sim_dauer 

    /*Berechne durschnittliche Wartezeit (SUmme aller Wartezeiten / )
    durschnitt_wartezeit = gesamt_wartezeit / gesamt_belegung

    /* Zeit mit vollbelegung (volle_belegung) und prozentaler Anteil an gesamt Dauer
    prozent_volle_belegung = (volle_belegung / sim_dauer) *100

    /* Anzahl abgefertigter Autos -> gesamt_durchlauf

    /* Ausgabe der Daten über Konsole und text file
    printf("Simulationdauer", gesamt_zeit|"Gesamt Kap.",anz_parkplätze,"Durchschn. Auslastung", durchschnitt_auslastung| "Durschn. Warteschlangenlänge",duchschnitt_wartequeue |"Max. Warteschlangenlänge", max_queue_laenge| "Durschschn. Wartezeit", durschnitt_wartezeit| "Zeit mit voller Belegung", volle_belegung| "Prozentualer Anteil", prozent_volle_belegung)
    WRITE TO FILE ... 
    IF p_log_file != NULL THEN
        CLOSE_FILE p_log_file
    END IF
*/
/*---------------------------------------------------------------*/
void output_total_statistics(int TOTAL_TIME_STEPS, int PARK_NUM_SPACES,int occupancy_timestep_percent[])
{
    /*spätere Implementierung*/
}
