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
/* Initialization                                                */
/*---------------------------------------------------------------*/
/**
 * @brief Initialize all statistic counters and accumulators
 *
 * This function must be called once before the simulation loop
 * starts. All internal values are reset to zero.
 * @param[in] filename Name der zu erstellenden Log-Datei.
 * @return int 0 bei Erfolg, -1 bei Dateifehler.
 */
int init_statistics(const char *filename);


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
* @param[in] current_step Current index of the timestep.
* @param[in] occupancy current number of parking cars.
* @param[in] queue_len current number of waiting cars.
* @param[in] finished_cars number of cars left the parking garage.
* @param[in] waiting_time_parking_cars total waiting time of all new parked cars
*/

void output_timestep_statistics(int current_step, int occupancy, int queue_len, int finished_cars, int waiting_time_parking_cars, int parking_cars);

/*---------------------------------------------------------------*/
/* End statistics output                                         */
/*---------------------------------------------------------------*/
/**
 * @brief Outputs the summarized statistics at the end of the simulation.
 */

void output_total_statistics(void);

/*---------------------------------------------------------------*/
/* Calculating functions for statistics                          */
/*---------------------------------------------------------------*/
/**
 * @brief Outputs the summarized statistics at the end of the simulation.
 */

#endif