#include <assert.h>
#include <stdio.h>
#include "../inc/statistics.h"
#include "../inc/car.h"

//Test for init_statistics()
void test_init_statistics()
{
    Statistics stats;
    int init_result = init_statistics(&stats, "test_log.txt");

    assert(init_result == 0);
    assert(stats.sum_occupancy == 0);
    assert(stats.sum_waiting_time == 0);
    assert(stats.sum_queue_length == 0);
    assert(stats.max_queue_length == 0);
    assert(stats.full_occupancy_steps == 0);
    assert(stats.finished_cars == 0);
    assert(stats.log_file != NULL);

    fclose(stats.log_file);
}


