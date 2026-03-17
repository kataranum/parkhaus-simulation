#include <simulation.h>
#include <stdlib.h>
#include <statistics.h>
#include <util.h>

void run_simulation(InputParams params, Statistics *p_stats)
{
    ParkingLot parking_lot = init_parking_lot(params.park_num_spaces);
    CarQueue waiting_cars = queue_init();

    srand(params.rng_seed);

    SimulationData simulation_data;
    simulation_data.params = params;
    simulation_data.current_step = 0;
    simulation_data.p_stats = p_stats;
    simulation_data.parking_lot = parking_lot;
    simulation_data.waiting_cars = waiting_cars;

    for (unsigned int i = 0; i < params.total_time_steps; i++)
    {
        simulation_data.current_step = i;

        get_new_cars_arriving(&simulation_data);
        remove_due_cars(&simulation_data);
        park_waiting_cars(&simulation_data);

        output_timestep_statistics(simulation_data.p_stats, simulation_data);
    }

    free_parking_lot(&simulation_data.parking_lot);
    queue_delete(&simulation_data.waiting_cars);
}

void remove_due_cars(SimulationData *p_simulation_data)
{
    ParkingLot *p_parking_lot = &p_simulation_data->parking_lot;

    for (unsigned int i = 0; i < p_parking_lot->length; i++)
    {
        Car car = p_parking_lot->p_array[i];

        if (car_empty(car))
        {
            continue;
        }

        int park_duration = p_simulation_data->current_step - car.time_arrival_park;

        if (park_duration <= car.time_park_duration)
        {
            continue;
        }

        statistics_car_leave(p_simulation_data->p_stats);
        p_parking_lot->p_array[i] = init_empty_car();
    }
}

void park_waiting_cars(SimulationData *p_simulation_data)
{
    ParkingLot *p_parking_lot = &p_simulation_data->parking_lot;
    CarQueue *p_waiting_cars = &p_simulation_data->waiting_cars;

    while (room_available(*p_parking_lot))
    {
        Car new_car;

        if (!dequeue(p_waiting_cars, &new_car))
        {
            // No more cars waiting in queue
            return;
        }

        new_car.time_arrival_park = p_simulation_data->current_step;

        int available_spot = find_empty_space(*p_parking_lot);
        p_parking_lot->p_array[available_spot] = new_car;
    }
}

void get_new_cars_arriving(SimulationData *p_simulation_data)
{
    float random_float = frand();

    if (random_float >= p_simulation_data->params.park_chance_arrive)
    {
        return;
    }

    Car new_car = init_new_car(p_simulation_data->params);
    new_car.time_arrival_queue = p_simulation_data->current_step;
    enqueue(&p_simulation_data->waiting_cars, new_car);
}
