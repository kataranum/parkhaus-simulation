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
/* Time step based updates                                                */
/*---------------------------------------------------------------*/
/**
 * @brief Update statistics that are evaluated per simulation step
 *
 * This function is called exactly once per simulation time step.
 * It updates values related to occupancy, queue length and
 * full-capacity detection.
 *
 * @param[in] occupied_spaces  Number of currently occupied parking spaces
 * @param[in] queue_length     Current number of vehicles in the waiting queue
 * @param[in] total_capacity   Total number of parking spaces
 */
void statistics_update_timestep(int occupied_spaces, int queue_length, int total_capacity);

#endif /* STATISTICS_H */