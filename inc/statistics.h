/*
* File: statistics.h
* Description: Interface for collecting, calculating and exporting
*              statistical data of the parking garage simulation.
* The statistics module is responsible only for data aggregation
* and evaluation. It does not influence the simulation logic.
*/
#ifndef STATISTICS_H
#define STATISTICS_H

/*---------------------------------------------------------------*/
/* Statistics state                                              */
/*---------------------------------------------------------------*/
typedef struct {
    FILE *log_file;

    /* Occupancy */
    int sum_occupancy;

    /* Waiting time */
    int sum_waiting_time;

    /* Queue statistics */
    int sum_queue_length;
    int max_queue_length;

    /* Full occupancy */
    int full_occupancy_steps;

    /* Finished cars */
    int finished_cars;

} Statistics;


/*---------------------------------------------------------------*/
/* Initialization                                                */
/*---------------------------------------------------------------*/
/**
 * @brief Initialize all statistic counters and accumulators
 *
 * This function must be called once before the simulation loop
 * starts. All internal values are reset to zero.
 * @param[in] filename Name der zu erstellenden Log-Datei.
 * @param[in] stats pointer auf Statistiks struct
 * @return int 0 bei Erfolg, -1 bei Dateifehler.
 */
int init_statistics(Statistics *stats, const char *filename);


/*---------------------------------------------------------------*/
/* Time step based updates                                       */
/*---------------------------------------------------------------*/
/**
* @brief Calculates and outputs the statistics for the current time step.
*
* This function is called exactly once per simulation time step.
* It updates values related to occupancy, queue length and
* full-capacity detection and outputs the statistic in the console.
* 
* @param simulation_data[in] simulation_data  
*/

void output_timestep_statistics(SimulationData simulation_data);

/*---------------------------------------------------------------*/
/* End statistics output                                         */
/*---------------------------------------------------------------*/
/**
 * @brief Outputs the summarized statistics at the end of the simulation.
 * @param simulation_data[in] simulation_data
 * @param[in] stats pointer auf Statistiks struct  
**/

void output_total_statistics(Statistics *stats, SimulationData simulation_data);

/*---------------------------------------------------------------*/
/* Car leave                                                     */
/*---------------------------------------------------------------*/
/**
* @brief Counts the finished_cars.
* @param[in] stats pointer auf Statistiks struct
**/
void statistics_car_leave(Statistics *stats);

#endif
