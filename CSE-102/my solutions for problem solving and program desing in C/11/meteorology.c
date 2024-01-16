#include <stdio.h>

#define INPUT_FILE      "meteorology_input.txt"
#define OUTPUT_DATABASE "meteorology_database.bin"
#define TRUE            1
#define FALSE           0
#define MAX_SITE        10
#define MAX_DAY         7

typedef struct{
    int site_id_num,    /*  4-digit integer     */
        wind_speed,     /*  knots               */
        day_of_month,   /*  day                 */
        temperature;    /*  degree C            */
}measured_data_t;

/*  prototypes  */
void make_binary(char *output_binary, char *input_text);
int get_data(char *output, measured_data_t data_arr[]);
void print_measured(measured_data_t to_print);
int maxima_temp_of(int id, measured_data_t data_arr[], int data_amount);
int greatest_maxima_id(measured_data_t data_arr[], int data_amount);
double av_wind_speed_of(int id, measured_data_t data_arr[], int data_amount);
int greatest_av_wind_speed_id(measured_data_t data_arr[], int data_amount);

int main(void){
    measured_data_t data_arr[MAX_SITE * MAX_DAY];
    int data_amount,
        id_greatest_maxima,
        id_greatest_av;


    make_binary(OUTPUT_DATABASE, INPUT_FILE);

    data_amount = get_data(OUTPUT_DATABASE, data_arr);

    id_greatest_maxima = greatest_maxima_id(data_arr, data_amount);
    id_greatest_av = greatest_av_wind_speed_id(data_arr, data_amount);

    printf("Id of greatest maxima: %d with %d\nId of greatest average wind speed: %d with %.2f", 
            id_greatest_maxima, maxima_temp_of(id_greatest_maxima, data_arr, data_amount),
             id_greatest_av, av_wind_speed_of(id_greatest_av, data_arr, data_amount));

    return(0);
}

/*  
*   takes text(input) contains measured_data,
*   and binary(output) file names and opens them,
*   copies text_file into binary_file
*/
void make_binary(char *output_binary, char *input_text){
    int error = FALSE;
    measured_data_t current;
    int status;
    FILE *fp_in_t, *fp_out_b;

    if((fp_in_t = fopen(input_text, "r")) == NULL){
        printf("Error: can't open %s.", input_text);
        error = TRUE;   
    }

    if((fp_out_b = fopen(output_binary, "wb")) == NULL){
        printf("Error: can't open %s.", output_binary);
        error = TRUE;
    }

    if(error == FALSE){
        for(status = fscanf(fp_in_t, "%d %d %d %d", &current.site_id_num,
                            &current.day_of_month, &current.wind_speed, &current.temperature);
            status == 4;

            status = fscanf(fp_in_t, "%d %d %d %d", &current.site_id_num,
                            &current.day_of_month, &current.wind_speed, &current.temperature)
            ){
                fwrite(&current, sizeof(current), 1, fp_out_b);
        }
    }
    fclose(fp_in_t);
    fclose(fp_out_b);
}

int get_data(char *output, measured_data_t data_arr[]){
    int data_amount;
    FILE *output_bp = fopen(output, "rb");

    data_amount = fread(data_arr, sizeof(measured_data_t), MAX_SITE*MAX_DAY, output_bp);

    fclose(output_bp);
    return data_amount;
}

void print_measured(measured_data_t to_print){
    printf("ID\tDay\tWind Speed (knots)\tTemperature (deg C)\n");
    printf("%d\t%d\t%d\t%d\n", to_print.site_id_num, to_print.day_of_month,
            to_print.wind_speed, to_print.temperature);
}

int maxima_temp_of(int id, measured_data_t data_arr[], int data_amount){
    int temp_min = 1000,
        temp_max = -1000,   /* initilazing first values of temp min and temp max.   */
        maxima;

    int ix;

    for(ix = 0; ix < data_amount; ix++){
        if(data_arr[ix].site_id_num == id){
            if(data_arr[ix].temperature < temp_min)
                temp_min = data_arr[ix].temperature;
            if(data_arr[ix].temperature > temp_max)
                temp_max = data_arr[ix].temperature;
        }
    }

    maxima = temp_max - temp_min;

    return(maxima);
}

int greatest_maxima_id(measured_data_t data_arr[], int data_amount){
    int max_id,
        greatest_maxima,
        ix;

    max_id = data_arr[0].site_id_num;
    greatest_maxima = maxima_temp_of(max_id, data_arr, data_amount);

    for(ix = 0; ix < data_amount; ix++){
        if(data_arr[ix].site_id_num != max_id){
            if(maxima_temp_of(data_arr[ix].site_id_num, data_arr, data_amount) > greatest_maxima){
                greatest_maxima = maxima_temp_of(data_arr[ix].site_id_num, data_arr, data_amount);
                max_id = data_arr[ix].site_id_num;
            }
        }
    }

    return(max_id);
}

double av_wind_speed_of(int id, measured_data_t data_arr[], int data_amount){
    int wind_speed_sum = 0,
        wind_speed_record = 0;

    double wind_speed_av;

    int ix;


    for(ix = 0; ix < data_amount; ix++){
        if(data_arr[ix].site_id_num == id){
            wind_speed_sum += data_arr[ix].wind_speed;
            wind_speed_record += 1;
        }
    }
    
    wind_speed_av = (double)wind_speed_sum / (double)wind_speed_record;

    return (wind_speed_av);
}

int greatest_av_wind_speed_id(measured_data_t data_arr[], int data_amount){
    int max_id,
        max_average,
        ix;
    max_id = data_arr[0].site_id_num;
    max_average = av_wind_speed_of(max_id, data_arr, data_amount);

    for(ix = 0; ix < data_amount; ix++){
        if(data_arr[ix].site_id_num != max_id){
            if(av_wind_speed_of(data_arr[ix].site_id_num, data_arr, data_amount) > max_average){
                max_average = av_wind_speed_of(data_arr[ix].site_id_num, data_arr, data_amount);
                max_id = data_arr[ix].site_id_num;
            }
        }
    }
    return(max_id);
}