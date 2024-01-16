#include <stdio.h>
#include <math.h>

#define TRUE    1
#define FALSE   0

typedef struct{
    double voltage,
            energy_capacity,    /*  joule   */
            energy_current;     /*  joule   */

}battery_t;


int power_device(double current, double time, battery_t *battery);
double max_time(double current, battery_t battery);
void recharge(battery_t *battery);
void display_battery(battery_t battery);

int main(void){
    battery_t auto_battery = {12, 5 * pow(10, 6), 0};
    recharge(&auto_battery);
    display_battery(auto_battery);
    printf("did provided = %d\n", power_device(4, 15*60, &auto_battery));
    display_battery(auto_battery);

    printf("Max time for 8-A device: %.2f minutes\n", max_time(8, auto_battery) / 60.0);
    recharge(&auto_battery);
    printf("Max time for 8-A device after recharge: %.2f minutes\n", max_time(8, auto_battery) / 60.0);

    

    return(0);
}

int power_device(   double current, /*  amps    */
                    double time,    /*  seconds */
                    battery_t *battery)
{
    int provided;

    double power = current * battery->voltage;  /*  watts   */
    double required_energy = power * time;      /*  joule   */

    if(battery->energy_current >= required_energy){
        battery->energy_current -= required_energy;
        provided = TRUE;
    }
    else{
        provided = FALSE;
    }

    return(provided);
}

double max_time(  double current,     /*  amps    */
                battery_t battery)
{
    double power = current * battery.voltage;
    double time = battery.energy_current / power; /*    seconds     */

    return (time);
}

void recharge(battery_t *battery){
    battery->energy_current = battery->energy_capacity;
}

void display_battery(battery_t battery){
    printf("Voltage: %.1f-V, Max Energy: %.1f joule, Current Energy: %.1f joule\n",
    battery.voltage, battery.energy_capacity, battery.energy_current);
}