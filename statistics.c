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
    gesamt_zeit        = 0
    gesamt_belegung    = 0
    gesamt_wartezeit   = 0
    gesamt_wartequeue  = 0
    max_queue_laenge   = 0
    volle_belegung     = 0
    auslastung_timestep[] = 0

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
FUNKTION void output_timestep_statistics(aktueller_schritt, belegung, länge_warteschlange, anz_autos_verlassen_parkhaus, wartezeit_geparkter_autos);
    gesamt_zeit += 1
    gesamt_belegung += belegung
    gesamt_wartezeit += wartezeit_geparkter_autos
    gesamt_wartequeue += warteschlange
    
    auslastung_timestep[aktueller_schritt] = (belegung/anz_parkplätze)*100

    WENN warteschlange > max_queue_laenge:
        max_queue_laenge = warteschlange

    WENN belegung IST VOLLE_KAPAZITÄT:
        volle_belegung += 1
    
    /*Berechnung durchschnitliche Wartezeit(Gesamtwartezeit aller bisher geparkten autos/ Anzahl aller geparkten autos (gesamt_belegung))
    durchschnitt_wartezeit = gesamt_wartezeit/anz_autos_parken

    gesamt_durchlauf += anz_autos_verlassen_parkhaus
    
    print("Aktuelle Belegung", belegung | "Warteschlange", länge_warteschlange| "Durchschn. Wartezeit", durchschnitt_wartezeit| "Vollbelegungs Ticks", volle_belegung| "Gesamt-Durchsatz",gesamt_durchlauf)

*/
/*---------------------------------------------------------------*/

void output_timestep_statistics(int current_step, int occupancy, int queue_len, int finished_cars, int waiting_time_parking_cars, int parking_cars)
{
    /*spätere Implementierung*/
}

/*---------------------------------------------------------------*/
/* End statistics output                                         */
/*---------------------------------------------------------------*/
/*
PSEUDOCODE
FUNCTION void output_total_statistics(sim_dauer, anz_parkplätze,)
    gesamt_zeit = sim_dauer
    sum_auslastung = 0
    /*Durchlauf aller timesteps und abspeichern der prozentualen Auslastungen
    FÜR i=0 bis sim_dauer-1
        sum_auslastung += auslastung_timestep[i]

    /*Berechnung der gesamten durchschnittlichen Auslastung(Summe der timestep_Auslastungen / Anzahl der Timesteps)
    durchschnitt_auslastung = sum_auslastung / sim_dauer

    /* Ausgabe der Daten über text file
    printf("Simulationdauer", gesamt_zeit|"Gesamt Kap.",anz_parkplätze,"Durchschn. Auslastung", durchschnitt_auslastung)

*/
/*---------------------------------------------------------------*/
void output_total_statistics(int TOTAL_TIME_STEPS, int PARK_NUM_SPACES,int occupancy_timestep_percent[])
{
    /*spätere Implementierung*/
}
