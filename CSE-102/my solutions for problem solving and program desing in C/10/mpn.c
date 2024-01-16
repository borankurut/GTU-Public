#include <stdio.h>
#include <string.h>

#define TRIPLET_LEN 6
#define IN_FILE     "mpn_input.txt"
#define MAX_DATA    20
#define SENTINEL    'q'

typedef struct{
    char cop_triplet[TRIPLET_LEN];  /*  combination of positives triplet    */
    int mp_number,                  /*  most probable number                */
        lower_bound,                /*  %95 confidence lower bound          */
        upper_bound;                /*  %95 confidence upper bound          */
}mpn_t;


/*  prototypes      */
int scan_mpn(FILE *fp_in, mpn_t *mpn);
int fill_table(char *in_file_name, mpn_t mpn_table[]);
void print_mpn(mpn_t mpn);                              /*  shitty.       */
void print_table(mpn_t mpn_table[], int data_amount);   /*  shitty.       */
int search(mpn_t mpn_table[], int data_amount, char *target_triplet);
void get_triplet_and_prompt(mpn_t mpn_table[], int data_amount);
void message(mpn_t mpn_table[], int ix);



int main(void){

    mpn_t mpn_table[MAX_DATA];

    int data_amount = fill_table(IN_FILE, mpn_table);

    get_triplet_and_prompt(mpn_table, data_amount);

    return (0);
}

int scan_mpn(FILE *fp_in, mpn_t *mpn){
    /*  local variables */
    char cop_triplet_l[TRIPLET_LEN];
    int mp_number_l,
        lower_bound_l,
        upper_bound_l;

    int status = fscanf(fp_in, "%s %d %d %d", cop_triplet_l, &mp_number_l, &lower_bound_l, &upper_bound_l);
    
    if(status == 4){
        strcpy(mpn->cop_triplet, cop_triplet_l);       
        mpn->mp_number = mp_number_l;
        mpn->lower_bound = lower_bound_l;
        mpn->upper_bound = upper_bound_l;
        status = 1;
    }
    else if(status != EOF)
        status = 0;
    
    return (status);
}


/*  shitty. */
void print_mpn(mpn_t mpn){
    printf("cop_triplet:%s mp_number:%d lower_bound:%d upper_bound:%d\n",mpn.cop_triplet,
            mpn.mp_number, mpn.lower_bound, mpn.upper_bound);
}

/*  shity.    */
void print_table(mpn_t mpn_table[], int data_amount){
    int ix;
    for(ix = 0; ix < data_amount; ix++){
        print_mpn(mpn_table[ix]);
    }
}

int fill_table(char *in_file_name, mpn_t mpn_table[]){
    FILE *fp_in = fopen(in_file_name, "r");
    mpn_t mpn_l; /* local mpn   */
    int status;
    int ix = 0;

    for(status = scan_mpn(fp_in, &mpn_l);
        status == 1;
        status = scan_mpn(fp_in, &mpn_l))
    {
        if(ix == MAX_DATA - 1){
            printf("MAX DATA AMOUNT REACHED.\n");
            break;
        }
        else{
            mpn_table[ix] = mpn_l;
        }
        ix += 1;
    }

    fclose(fp_in);

    return(ix);
}

int search(mpn_t mpn_table[], int data_amount, char *target_triplet){
    int where = -1,
        ix;
    
    for(ix = 0; ix < data_amount; ix++){
        if(strcmp(mpn_table[ix].cop_triplet, target_triplet) == 0){
            where = ix;
            break;
        }
    }

    return where;
}

void get_triplet_and_prompt(mpn_t mpn_table[], int data_amount){
    char entered_triplet[TRIPLET_LEN];
    int ix;

    printf("Enter the combination-of-positives triplet (or %c to quit) > ", SENTINEL);
    scanf("%s", entered_triplet);

    while(entered_triplet[0] != SENTINEL){
        ix = search(mpn_table, data_amount, entered_triplet);

        if(ix != -1){
            message(mpn_table, ix);
            printf("\n");
        }
        else{
            printf("Given combination not found in the data.\n");
            printf("\n");
        }

        printf("Enter the combination-of-positives triplet (or %c to quit) > ", SENTINEL);
        scanf("%s", entered_triplet);
    }
}

void message(mpn_t mpn_table[], int ix){
    printf("For %s, MPN = %d; %%95 of samples contain between %d and %d bacteria/ml.\n", 
            mpn_table[ix].cop_triplet, mpn_table[ix].mp_number,
            mpn_table[ix].lower_bound, mpn_table[ix].upper_bound);
}