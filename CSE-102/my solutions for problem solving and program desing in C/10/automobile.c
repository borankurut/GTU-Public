#include <stdio.h>

#define MAKE_LEN    20
#define MODEL_LEN   20
#define INPUT_NAME  "automobile_input.txt"

typedef struct{
    int month,
        day,
        year;
}date_t;

typedef struct{
    double tank_capacity,   /*  gallons     */
            current_fuel;   /*  gallons     */
}tank_t;

typedef struct{
    char make[MAKE_LEN],
        model[MODEL_LEN];

    int odometer;

    date_t manufacture_date,
            purchase_date;
            
    tank_t gas_tank;
}auto_t;


/*  Prototypes  */
int scan_date(date_t *date, FILE *fp_in);
int scan_tank(tank_t *tank, FILE *fp_in);
int scan_automobile(auto_t *automobile, FILE *fp_in);
void print_date(date_t date);
void print_tank(tank_t tank);
void print_automobile(auto_t automobile);

int main(void){

    FILE *fp_in = fopen(INPUT_NAME, "r");
    auto_t my_auto;

    int status;
    
    for(status = scan_automobile(&my_auto, fp_in);
        status == 1;
        status = scan_automobile(&my_auto, fp_in))
    {
        print_automobile(my_auto);
        printf("\n\n");
    }

    fclose(fp_in);
    return(0);
}

int scan_date(date_t *date, FILE *fp_in){
    int status = fscanf(fp_in, "%d %d %d", &date->month, &date->day, &date->year);

    if(status == 3)
        status = 1;
    else if(status != EOF)
        status = 0;

    return (status);
}

int scan_tank(tank_t *tank, FILE *fp_in){
    int status = fscanf(fp_in, "%lf %lf", &tank->tank_capacity, &tank->current_fuel);

    if(status == 2)
        status = 1;
    else if(status != EOF)
        status = 0;
    
    return(status);
}

int scan_automobile(auto_t *automobile, FILE *fp_in){
    tank_t tank;
    date_t manufacture_date,
            purchase_date;

    int status = fscanf(fp_in, "%s %s %d", automobile->make, automobile->model, &automobile->odometer),
        status_purchase = scan_date(&purchase_date, fp_in),
        status_manufacture = scan_date(&manufacture_date, fp_in),
        status_tank = scan_tank(&tank, fp_in);

    if(status == 3 && status_purchase == 1 && status_manufacture == 1 && status_tank == 1){
        status = 1;
        automobile->manufacture_date = manufacture_date;
        automobile->purchase_date = purchase_date;
        automobile->gas_tank = tank;
    }
    else if(status != EOF)
        status = 0;

    return status;
}

void print_date(date_t date){
    printf("%d/%d/%d", date.month, date.day, date.year);
}

void print_tank(tank_t tank){
    printf("Current fuel: %.2f gallons\nTank capacity: %.2f gallons", tank.current_fuel, tank.tank_capacity);
}

void print_automobile(auto_t automobile){
    printf("Make: %s\nModel: %s\nOdometer: %d\n", automobile.make, automobile.model, automobile.odometer);
    printf("Manufacture date: ");
    print_date(automobile.manufacture_date);
    printf("\nPurchase date: ");
    print_date(automobile.purchase_date);
    printf("\n");
    print_tank(automobile.gas_tank);
    printf("\n");
}