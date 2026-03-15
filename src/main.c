#include <user_input.h>
#include <statistics.h>
#include <simulation.h>

/*
```PSEUDOCODE
intput_params = get_user_input()

Statistics stats;
success = init_statistics(&stats, "output.txt")
IF success != 0 THEN
    PRINT "Error initializing statistics"
    EXIT
END IF

run_simulation(input_params, &stats)

output_total_statistics(&stats)
RETURN 0
```
*/
int main(void) {
    InputParams params = get_user_input();

    Statistics stats;
    if ( init_statistics(&stats, "output.txt") != 0) {
        printf("Could not initialize statistics.\n");
        return 1;
    }

    run_simulation(params, &stats);

    output_total_statistics(&stats, params);

    return 0;
}
