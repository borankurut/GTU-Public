/*  schedule system library header  */

#if !defined SCHEDULE_LIBRARY_HEADER
#define SCHEDULE_LIBRARY_HEADER
typedef struct 
{
    int crew_number,        /*  number of the crew                          */
        skill_level,        /*  skill level of the crew                     */
        cost_per_hr,        /*  cost of the crew per hour                   */
        total_hrs_worked;   /*  total hours worked in current task list.    */
}crew_t;

typedef struct{
    int id,             /*  id of the aircraft              */
        level,          /*  required maintenance level      */
        hours,          /*  required hours                  */
        is_done;        /*  is it done                      */

}aircraft_t;

extern int schedule_system_scan_crew(FILE *fp_in, crew_t *crew);
extern void schedule_system_print_crew(crew_t crew);
extern int scan_crew_list(FILE *fp_in, crew_t crew_list[], int max_crew);
extern int schedule_system_scan_aircraft(FILE *fp_in, aircraft_t *aircraft);
extern int scan_aircraft_list(FILE *fp_in, aircraft_t aircraft_list[], int max_aircraft);
extern void schedule_system_print_error_in_file(FILE *fp_in);
extern void schedule_system_print_aircraft(aircraft_t aircraft);
extern crew_t schedule_system_low_cost(crew_t crew_list[], int crew_amount, int maint_level);

#endif