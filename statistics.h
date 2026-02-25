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
* @param[in] finished_cars_timestep number of cars left the parking garage in the current timestep
* @param[in] waiting_time_parking_cars total waiting time of all new parked cars
* @param[in] PARK_NUM_SPACES number of total parking slots
*/

void output_timestep_statistics(int current_step, int occupancy, int queue_len, int finished_cars_timestep, int waiting_time_parking_cars, int PARK_NUM_SPACES);

/*---------------------------------------------------------------*/
/* End statistics output                                         */
/*---------------------------------------------------------------*/
/**
 * @brief Outputs the summarized statistics at the end of the simulation.
 * @param[in] PARK_NUM_SPACES number of total parking slots
**/

void output_total_statistics(int PARK_NUM_SPACES);

#endif