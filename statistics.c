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
    gesamt_wartequeue  = 0
    max_queue_laenge   = 0
    volle_belegung     = 0

    schreibe_log("==== PARKHAUS-SIMULATION LOG ====")
    GIB 0 ZURÜCK
*/
/*---------------------------------------------------------------*/

int init_statistics(const char *filename)
{
 /*spätere implementierung*/   
}