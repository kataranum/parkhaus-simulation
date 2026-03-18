/*
 * File: statistics.c
 * Description: Implementation of the statistics module for the
 *              parking garage simulation.
 */

#include <statistics.h>

int init_statistics(Statistics *stats, const char *filename)
{
    // Richtige Parameterübergabe sicherstellen 
    if ( (stats == NULL) || (filename == NULL) )
    {
        return -1;
    }

    // Datei öffnen
    stats->log_file = fopen(filename, "w");

    // Überprüfen ob öffnen funktioniert hat 
    if (stats->log_file == NULL)
    {
        return -1;
    }

    // Variablen zurücksetzen 
    stats->sum_occupancy = 0;
    stats->sum_waiting_time = 0;
    stats->sum_queue_length = 0;
    stats->max_queue_length = 0;
    stats->full_occupancy_steps = 0;
    stats->finished_cars = 0;

    return 0; 
}

void output_timestep_statistics(Statistics *stats, SimulationData simulation_data)
{
    // Funktions Variable
    float avg_waiting_time_timestep = 0.0;
    int current_occupancy = get_occupancy(simulation_data.parking_lot);
    float occupancy_percent = ((float)current_occupancy / (float)simulation_data.params.park_num_spaces) * 100.0;

    // Stats Variablen mit Werten von Timestep befüllen
    stats->sum_occupancy += current_occupancy;
    stats->sum_queue_length += simulation_data.waiting_cars.length;
    
    // Aktualisierung der längsten Warteschlange
    if (simulation_data.waiting_cars.length > stats->max_queue_length)
    {
        stats->max_queue_length = simulation_data.waiting_cars.length;
    }
    
    // Hochzählen der static Variable wenn Parkhaus ausgelastet
    if (get_occupancy(simulation_data.parking_lot) == simulation_data.params.park_num_spaces)
    {
        stats->full_occupancy_steps += 1; 
    }
    // Berechnung durchschnitliche Wartezeit
    // ( Gesamtwartezeit aller bisher geparkten Autos / Anzahl aller geparkten autos )
    if (stats->sum_occupancy == 0)
    {
        avg_waiting_time_timestep = 0.0;
    }
    else
    {
        avg_waiting_time_timestep = (float)stats->sum_waiting_time / (float)stats->sum_occupancy;
    }

    // Erstelle Ausgabe-String
    char buffer[1024];
    snprintf(buffer, sizeof(buffer),
        "------------------------------------------------------------\n"
        "SIMULATIONS-SCHRITT: %d / %d\n"
        "------------------------------------------------------------\n"
        "%-35s %10d / %d Plätze (%6.1f %%)\n"
        "%-35s %10d Fahrzeuge\n"
        "%-35s %10.1f Zeitschritte\n"
        "%-35s %10d\n"
        "%-35s %10d Fahrzeuge\n"
        "------------------------------------------------------------\n\n",
        simulation_data.current_step,
        simulation_data.params.total_time_steps,

        "Aktuelle Belegung:",
        current_occupancy,
        simulation_data.params.park_num_spaces,
        occupancy_percent,

        "Warteschlange:",
        simulation_data.waiting_cars.length,

        "Durchschn. Wartezeit:",
        avg_waiting_time_timestep,  

        "Vollbelegungs-Ticks:",
        stats->full_occupancy_steps,

        "Gesamt-Durchsatz:",
        stats->finished_cars
    );

    // Konselenausgabe
    printf("%s", buffer);

    // File Ausgabe
    if (stats->log_file != NULL)
    {
        fprintf(stats->log_file, "%s", buffer);
    }
}

void output_total_statistics(Statistics *stats, InputParams params)
{
    // Funktionsvariablen 
    float avg_occupancy_percentage = 0.0;
    float avg_queue_length = 0.0;
    float avg_waiting_time = 0.0;
    float full_occupancy_percentage = 0.0;

    // Berechnung der gesamten durchschnittlichen Auslastung
    // ( (Summe der Auslastungen / Anzahl der Timesteps) / Anzahl gesamt Parkplätze ) * 100
    avg_occupancy_percentage = (((float)stats->sum_occupancy / (float)params.total_time_steps) / (float)params.park_num_spaces) * 100.0;

    // Berechne durschnittliche Warteschlangenlänge
    // Länge der gesamten Wartenschlange / Anzahl der gesamten Timesteps
    avg_queue_length = (float)stats->sum_queue_length / (float)params.total_time_steps;

    // Berechne durschnittliche Wartezeit
    // Summe aller Wartezeiten / Anzahl geparkter Autos
    if (stats->sum_occupancy == 0)
    {
        avg_waiting_time = 0.0;
    }
    else 
    {
        avg_waiting_time = (float)stats->sum_waiting_time / (float)stats->sum_occupancy;
    }

    // Zeit mit Vollbelegung (stats.full_occupancy_steps) und prozentaler Anteil an gesamter Dauer(total_time_steps)
    full_occupancy_percentage = ((float)stats->full_occupancy_steps / (float)params.total_time_steps) * 100.0;

    // Ausgabe der Daten über Konsole      
    char buffer[2048];
    snprintf(buffer, sizeof(buffer),
    "==================================================\n"
    "              PARKHAUS-SIMULATION\n"
    "                Statistikbericht\n"
    "==================================================\n\n"
    "%-40s %10d Zeitschritte\n"
    "%-40s %10d Stellplätze\n\n"
    "--------------------------------------------------\n"
    "1. AUSLASTUNG\n"
    "--------------------------------------------------\n"
    "%-40s %10.1f %%\n\n"
    "--------------------------------------------------\n"
    "2. WARTESCHLANGE\n"
    "--------------------------------------------------\n"
    "%-40s %10.1f Fahrzeuge\n"
    "%-40s %10d Fahrzeuge\n\n"
    "--------------------------------------------------\n"
    "3. WARTEZEIT\n"
    "--------------------------------------------------\n"
    "%-40s %10.1f Zeitschritte\n\n"
    "--------------------------------------------------\n"
    "4. VOLLBELEGUNG\n"
    "--------------------------------------------------\n"
    "%-40s %10d\n"
    "%-40s %10.1f %%\n\n"
    "--------------------------------------------------\n"
    "5. FAHRZEUG-DURCHSATZ\n"
    "--------------------------------------------------\n"
    "%-40s %10d\n\n"
    "==================================================\n",

    "Simulationsdauer:",
    params.total_time_steps,

    "Gesamtkapazität Parkhaus:",
    params.park_num_spaces,

    "Durchschnittliche Auslastung:",
    avg_occupancy_percentage,

    "Durchschnittliche Warteschlangenlänge:",
    avg_queue_length,

    "Maximale Warteschlangenlänge:",
    stats->max_queue_length,

    "Durchschnittliche Wartezeit:",
    avg_waiting_time,

    "Zeitschritte mit Vollbelegung:",
    stats->full_occupancy_steps,

    "Anteil an Simulationsdauer:",
    full_occupancy_percentage,

    "Fahrzeuge erfolgreich abgefertigt:",
    stats->finished_cars
    );

    // Konsolenausgabe
    printf("%s", buffer);

    // Dateiausgabe
    if (stats->log_file != NULL)
    {
        fprintf(stats->log_file, "%s", buffer);
    }

    // File ordnungsgemäß schließen
    if (stats->log_file != NULL)
    {
        fclose(stats->log_file);
        stats->log_file = NULL;
    }
}

void statistics_car_leave(Statistics *stats)
{
    stats->finished_cars++;
}

void statistics_car_arrive(Statistics *stats, Car new_car)
{
    stats->sum_waiting_time += new_car.time_arrival_park - new_car.time_arrival_queue;
}
