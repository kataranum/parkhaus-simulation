#include <user_input.h>
#include <statistics.h>
#include <simulation.h>

int main(void) {
    InputParams params = get_user_input();

    Statistics stats;
    if ( init_statistics(&stats, "output.txt") != 0)
    {
        printf("Could not initialize statistics.\n");
        return 1;
    }

    run_simulation(params, &stats);

    output_total_statistics(&stats, params);

    return 0;
}
