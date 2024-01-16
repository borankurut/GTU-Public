/* schedule system library  */

#include <stdio.h>
#include "schedule_system_library.h"

#define SCHEDULE_SYSTEM_MAX_CREW        5
#define SCHEDULE_SYSTEM_MAX_AIRCRAFT    10

/*  main function to debug. */
int main(void){
    crew_t crew_list[SCHEDULE_SYSTEM_MAX_CREW];
    aircraft_t aircraft_list[SCHEDULE_SYSTEM_MAX_AIRCRAFT];

    FILE *fp_in = fopen("crew_input.txt", "r");
    FILE *fp_in2 = fopen("aircraft_input.txt", "r");


    int data_amount = scan_crew_list(fp_in, crew_list, SCHEDULE_SYSTEM_MAX_CREW);
    int data_amount2 = scan_aircraft_list(fp_in2, aircraft_list, SCHEDULE_SYSTEM_MAX_AIRCRAFT);

    fclose(fp_in);
    fclose(fp_in2);

    return(0);
}

int schedule_system_scan_crew(FILE *fp_in, crew_t *crew){
    char dollar_sign;   /*  dollar sign (garbage)   */

    int status;         /*  status of the scanf     */
    status = fscanf(fp_in, "%d %d %c %d", &crew->crew_number, &crew->skill_level,
                                            &dollar_sign, &crew->cost_per_hr);
    crew->total_hrs_worked = 0;

    if(status == 4)
        status = 1;
    else if(status != EOF)
        status = 0;

    return(status);
}

int schedule_system_scan_aircraft(FILE *fp_in, aircraft_t *aircraft){
    int status;     /*  status of the scanf         */
    status = fscanf(fp_in, "%d %d %d", &aircraft->id,
                            &aircraft->level, &aircraft->hours);
    aircraft->is_done = 0;

    if(status == 3)
        status = 1;
    else if(status != EOF)
        status = 0;

    return(status);
}

int scan_crew_list(FILE *fp_in, crew_t crew_list[], int max_crew){
    crew_t current_crew;

    int list_ix = 0,
        status;

    for(status = schedule_system_scan_crew(fp_in, &current_crew);
        status == 1 && list_ix < max_crew;
        status = schedule_system_scan_crew(fp_in, &current_crew))
    {
        crew_list[list_ix] = current_crew;
        list_ix += 1;
    }

    if(status != 1 && status != EOF)
        schedule_system_print_error_in_file(fp_in);

    return(list_ix);
}
int scan_aircraft_list(FILE *fp_in, aircraft_t aircraft_list[], int max_aircraft){
    aircraft_t current_aircraft;

    int list_ix = 0,
        status;
    
    for(status = schedule_system_scan_aircraft(fp_in, &current_aircraft);
        status == 1 && list_ix < max_aircraft;
        status = schedule_system_scan_aircraft(fp_in, &current_aircraft))
    {
        aircraft_list[list_ix] = current_aircraft;
        list_ix += 1;

    }

    if(status != 1 & status != EOF)
        schedule_system_print_error_in_file(fp_in);
    
    return(list_ix);
}



void schedule_system_print_crew(crew_t crew){
    printf("%d\t%d\t$%d", crew.crew_number, crew.skill_level, crew.cost_per_hr);
}

void schedule_system_print_aircraft(aircraft_t aircraft){
    printf("%d\t%d\t%d", aircraft.id, aircraft.level, aircraft.hours);
}

void schedule_system_print_error_in_file(FILE *fp_in){
    char error;
    fscanf(fp_in, "%c", &error);
    printf("\n******* Error scanning data here: >>>>%c<<<<  *******\n", error);
}

/*
*   A function that checks maintenance level required against the crew abilities
*   and returns the number of the lowest-cost crew that can perform
*   the maintenance.
*
*   if no crew member satisfy the requirements, it returns crew_list[0].
*/
crew_t schedule_system_low_cost(crew_t crew_list[], int crew_amount, int maint_level){
    int ix;
    crew_t result_crew;

    for(ix = 0; ix < crew_amount; ix++){
        if(crew_list[ix].skill_level >= maint_level){
            result_crew = crew_list[ix];
            break;
        }
    }

    for(ix = 0; ix < crew_amount; ix++){
        if( crew_list[ix].skill_level >= maint_level && 
            crew_list[ix].cost_per_hr <= result_crew.cost_per_hr)
        {
            result_crew = crew_list[ix];
        }
    }   

    return (result_crew);
}