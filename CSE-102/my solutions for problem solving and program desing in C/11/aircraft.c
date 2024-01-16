#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NAME_LEN            25
#define DES_LEN             80
#define SENTINEL            'q'
#define TRUE                1
#define FALSE               0
#define INPUT_NAME_T        "aircraft_input.txt"
#define OUTPUT_NAME_B       "aircraft_database.bin"
#define MAX_AIRCRAFT        10

typedef struct{
    char name[NAME_LEN];        /*  name of the aircraft                */

    int max_speed;              /*  maximum cruise speed in km/h        */

    double wingspan,            /*  in m                                */
            lenght;             /*  in m                                */

    char m_or_s,                /*  military or civilian ('M' or 'C')   */
        desc_phase[DES_LEN];    /*  descriptive phase                   */


}aircraft_t;

typedef struct{
    char low_name[NAME_LEN], high_name[NAME_LEN];

    int low_max_speed, high_max_speed;
    double low_wingspan, high_wingspan;
    double low_length, high_length;

    char m_or_c;
}param_t;

void print_menu(param_t param);
char menu_choose(param_t param);
param_t initialize_param();
void update_param(param_t *param, char choice);
param_t get_user_param();
void make_binary(char *output_binary, char *input_text);
int get_aircraft_data(aircraft_t aircraft_data[], int max_data, char *binary_name);
void print_aircraft(aircraft_t aircraft);
void display_match(aircraft_t aircraft_data[], int data_amount, param_t param);
int is_match(aircraft_t aircraft, param_t param);

int main(void){
    aircraft_t aircraft_data[MAX_AIRCRAFT];
    param_t user_param;
    int data_amount;

    make_binary(OUTPUT_NAME_B, INPUT_NAME_T);
    data_amount = get_aircraft_data(aircraft_data, MAX_AIRCRAFT, OUTPUT_NAME_B);

    user_param = get_user_param();

    display_match(aircraft_data, data_amount, user_param);

    return (0);
}

char menu_choose(param_t param){
    char choice;

    printf("[a] Low bound for name: %s\n", param.low_name);
    printf("[b] High bound for name: %s\n", param.high_name);

    printf("[c] Low bound for speed: %d\n", param.low_max_speed);
    printf("[d] High bound for speed: %d\n", param.high_max_speed);

    printf("[e] Low bound for wingspan: %.2f\n", param.low_wingspan);
    printf("[f] High bound for wingspan: %.2f\n", param.high_wingspan);

    printf("[g] Low bound for length: %.2f\n", param.low_length);
    printf("[h] High bound for length: %.2f\n", param.high_length);

    printf("[i] Military or civilian: %c\n", param.m_or_c);

    printf("[q] to exit.\n");

    printf("Choice> ");
    for(scanf("%c", &choice);
        choice == '\n';
        scanf("%c", &choice)){}
    printf("\n");

    return(choice);
}

param_t initialize_param(){
    param_t param;

    strcpy(param.low_name, "AAAA");
    strcpy(param.high_name, "zzzz");
    param.low_max_speed = 0;
    param.high_max_speed = 10000;
    param.low_wingspan = 0.0;
    param.high_wingspan = 1000.0;
    param.low_length = 0.0;
    param.high_length = 1000.0;
    param.m_or_c = 'M';

    return(param);
}

void update_param(param_t *param, char choice){
    switch (choice)
    {
    case 'a':
        printf("Enter the new low bound for name> ");
        scanf("%s", param->low_name);
        break;
    
    case 'b':
        printf("Enter the new high bound for name>");
        scanf("%s", param->high_name);
        break;
    
    case 'c':
        printf("Enter the new low bound for max speed> ");
        scanf("%d", &param->low_max_speed);
        break;
    
    case 'd':
        printf("Enter the new high bound for max speed> ");
        scanf("%d", &param->high_max_speed);
        break;
    
    case 'e':
        printf("Enter the new low bound for wingspan> ");
        scanf("%lf", &param->low_wingspan);
        break;
    
    case 'f':
        printf("Enter the new hight bound for wingspan> ");
        scanf("%lf", &param->high_wingspan);
        break;
    
    case 'g':
        printf("Enter the new low bound for length> ");
        scanf("%lf", &param->low_length);
        break;
    
    case 'h':
        printf("Enter the new high bound for length> ");
        scanf("%lf", &param->high_length);
        break;
    
    case 'i':
        printf("Enter military or civilian ('M' or 'C') > ");
        scanf("\n%c", &param->m_or_c);
        param->m_or_c = toupper(param->m_or_c);
        break;

    case 'q':
        break;
    
    default:
        printf("Error: Invalid choice\n");
        break;
    }
}

param_t get_user_param(){
    param_t param = initialize_param();
    char choice;
    for(choice = menu_choose(param);
        choice != SENTINEL;
        choice = menu_choose(param))
    {
        update_param(&param, choice);
    }
    return (param);
}

/*  
*   takes text(input) contains aircraft_data,
*   and binary(output) file names and opens them,
*   copies text_file into binary_file
*/
void make_binary(char *output_binary, char *input_text){
    int error = FALSE;
    char new_line;
    aircraft_t current;
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
        for(status = fscanf(fp_in_t, "%25[^\n] %d %lf %lf %c %80[^\n]", current.name,
                            &current.max_speed, &current.wingspan, &current.lenght, 
                            &current.m_or_s, current.desc_phase);
            status == 6;

            status = fscanf(fp_in_t, "%25[^\n] %d %lf %lf %c %80[^\n]", current.name,
                            &current.max_speed, &current.wingspan, &current.lenght, 
                            &current.m_or_s, current.desc_phase)
            ){
                fscanf(fp_in_t, "%c", &new_line);
                fscanf(fp_in_t, "%c", &new_line);
                fwrite(&current, sizeof(current), 1, fp_out_b);
        }
    }
    fclose(fp_in_t);
    fclose(fp_out_b);
}

int get_aircraft_data(aircraft_t aircraft_data[], int max_data, char *binary_name){
    int data_amount;
    FILE *fp_in_b = fopen(binary_name, "rb");

    data_amount = fread(aircraft_data, sizeof(aircraft_t), max_data, fp_in_b);

    fclose(fp_in_b);
    return (data_amount);
}

void print_aircraft(aircraft_t aircraft){
    printf("%s\n%d\n%.2f\n%.2f\n%c\n%s\n\n\n", aircraft.name, aircraft.max_speed, aircraft.wingspan,
                                        aircraft.lenght, aircraft.m_or_s, aircraft.desc_phase);
}

void display_match(aircraft_t aircraft_data[], int data_amount, param_t param){
    int ix;
    for(ix = 0; ix < data_amount; ix++){
        if(is_match(aircraft_data[ix], param) == TRUE){
            print_aircraft(aircraft_data[ix]);
        }
    }
}

int is_match(aircraft_t aircraft, param_t param){
    int result =  (strcmp(aircraft.name, param.low_name) == 1   &&
                strcmp(aircraft.name, param.high_name) == -1    &&
                aircraft.max_speed >= param.low_max_speed       &&
                aircraft.max_speed <= param.high_max_speed      &&
                aircraft.wingspan >= param.low_wingspan         &&
                aircraft.wingspan <= param.high_wingspan        &&
                aircraft.lenght >= param.low_length             &&
                aircraft.lenght <= param.high_length            &&
                aircraft.m_or_s == param.m_or_c);
    return (result);
}