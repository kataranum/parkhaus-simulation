#include "../inc/simulation.h"

/*
```PSEUDOCODE
ALLOCATE_ARRAY Car[params.num_spaces] parking_lot;
INIT_QUEUE Car waiting_cars;

FOR current_step IN 0 TO params.total_time_steps:
    get_new_cars_arriving(params, waiting_cars, p_stats);
    remove_due_cars(current_step, parking_lot, p_stats);
    park_waiting_cars(parking_lot, waiting_cars, p_stats);

    output_timestep_statistics();
END FOR
``'
*/
void run_simulation(InputParams params, Stats *p_stats) {
    // TODO
}
