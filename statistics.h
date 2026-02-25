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



#endif /* STATISTICS_H */