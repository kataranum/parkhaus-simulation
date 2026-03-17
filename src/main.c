#include <user_input.h>
#include <statistics.h>
#include <simulation.h>

#define EXIT_SUCCESS 0
#define EXIT_FAIL_STATS 1
#define EXIT_FAIL_MALLOC -1

int main(void) {
    InputParams params = get_user_input();

    Statistics stats;
    if ( init_statistics(&stats, "output.txt") != 0)
    {
        printf("Could not initialize statistics.\n");
        return EXIT_FAIL_STATS;
    }

    run_simulation(params, &stats);

    output_total_statistics(&stats, params);

    return EXIT_SUCCESS;
}
