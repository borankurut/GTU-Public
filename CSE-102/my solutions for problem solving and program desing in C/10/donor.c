#include <stdio.h>
#include <string.h>

#define INPUT_NAME  "donors.txt"
#define OUTPUT_NAME "thanks.txt"
#define STR_SIZE    50
#define MAX_DONORS  100
#define TRUE        1
#define FALSE       0

typedef struct{
    char    first_name[STR_SIZE],   /*  first name of the donor                                         */
            last_name[STR_SIZE],    /*  last name of the donor                                          */
            str_adr_1[STR_SIZE],    /*  line 1 of street address                                        */
            str_adr_2[STR_SIZE],    /*  line 2 of street address or a zero if there is no second line   */
            city[STR_SIZE],         /*  city                                                            */
            state_abbr[3];          /*  two-character state abbreviation                                */

    int zip_code;                   /*  five digit zip code                                             */

    double total_donations;         /*  total donations of the donor so far this year.                  */
}donor_t;

/*  prototypes  */
int get_donor_list(donor_t donors[], int max_data, char *organization_name, char *file_name);
int get_donor(donor_t *donor, FILE *fp_in);
void print_donor(donor_t donor);
void prompt_get_donation(char *last_name, char *first_name, double *donation_p);
int end_donation(char *last_name);
int have_donor(char *last_name, char *first_name, donor_t donors[], int data_amount);
void update_donor(int ix, double donation, donor_t donors[]);
void add_donor(donor_t donors[], int *data_amount_p, char *last_name, char *first_name, double donation);
void thank_letters(char *output_name, donor_t donors[], int data_amount);
int prior_in_range(int min, int max, donor_t donors[]);
donor_t prior(donor_t donor0, donor_t donor1);
void sort_list(donor_t donors[], int data_amount);
int same_donor(donor_t donor0, donor_t donor1);
void print_list(donor_t donors[], int data_amount);
void update_list(donor_t donors[], int data_amount, char *file_name, char *organization_name);

int main(void){
    donor_t donors[MAX_DONORS];
    char    organization_name[STR_SIZE],
            first_name[STR_SIZE],
            last_name[STR_SIZE];

    double donation;

    int ix,
        data_amount;

    data_amount = get_donor_list(donors, MAX_DONORS, organization_name, INPUT_NAME);

    prompt_get_donation(last_name, first_name, &donation);

    while (end_donation(last_name) == FALSE){
        printf("values: %s, %s, %.2f\n", first_name, last_name, donation);

        if((ix = have_donor(last_name, first_name, donors, data_amount)) != -1)
        {
            update_donor(ix, donation, donors);
        }
        else{
            add_donor(donors, &data_amount, last_name, first_name, donation);
        }
        prompt_get_donation(last_name, first_name, &donation);
    }

    sort_list(donors, data_amount);
    thank_letters(OUTPUT_NAME, donors, data_amount);
    update_list(donors, data_amount, INPUT_NAME, organization_name);

    return (0);
}

/*  gets donor list.    */
int get_donor_list( donor_t donors[],           /*  input-output donors array   */
                    int max_data,               /*  input donors array size     */
                    char *organization_name,    /*  name of the organization    */
                    char *file_name)            /*  input file name             */
{
    int ix = 0,
        status = 1;

    FILE *fp_in = fopen(file_name, "r");

    fgets(organization_name, STR_SIZE, fp_in);
    strtok(organization_name, "\n");
    while (status == 1)
    {
        if(ix >= max_data){
            printf("Maximum data amount reached.\n");
            break;
        }
        status = get_donor(&donors[ix], fp_in);
        ix += 1;
    }

    fclose(fp_in);

    return (ix - 1);
}


/*  fills the donor if not EOF, returns 1 or 0        */
int get_donor(  donor_t *donor,     /*  donor to be filled  input-out   */
                FILE *fp_in)        /*  file to get donor   input       */
{
    char last_name_l[STR_SIZE]; /*  local last name     */

    int status = 0;

    if(fgets(last_name_l, STR_SIZE, fp_in) != NULL){
        strcpy(donor->last_name, last_name_l);
        strtok(donor->last_name, "\n");
        fgets(donor->first_name, STR_SIZE, fp_in);
        strtok(donor->first_name, "\n");
        fgets(donor->str_adr_1, STR_SIZE, fp_in);
        strtok(donor->str_adr_1, "\n");
        fgets(donor->str_adr_2, STR_SIZE, fp_in);
        strtok(donor->str_adr_2, "\n");
        fgets(donor->city, STR_SIZE, fp_in);
        strtok(donor->city, "\n");
        fgets(donor->state_abbr, STR_SIZE, fp_in);
        strtok(donor->state_abbr, "\n");
        fscanf(fp_in, "%d", &donor->zip_code);
        fscanf(fp_in, "%lf", &donor->total_donations);
        fgetc(fp_in);
        status = 1;
    }
    return (status);
}

/*  shitty. */
void print_donor(donor_t donor){
    printf("lastname: %s, name: %s, city: %s\nabbr: %s, zip: %d, donation: %.2f\n\n\n",
    donor.last_name, donor.first_name, donor.city, donor.state_abbr, donor.zip_code, donor.total_donations);
}

/*  prompts and gets the donation input.    */
void prompt_get_donation(char *last_name, char *first_name, double *donation_p){
    int progress = TRUE;

    printf("Last name> ");
    scanf("%s", last_name);

    if(end_donation(last_name) == TRUE)
        progress = FALSE;

    if(progress){
        printf("First name> ");
        scanf("%s", first_name);
        printf("Donation> ");
        scanf("%lf", donation_p);
    }
}

/*  cheks whether the donation input ended. */
int end_donation(char *last_name){
    if(last_name[0] == 'q' && last_name[1] == '\0')
        return TRUE;
    else    
        return FALSE;
}


/*  returns the index of given donor if it is in the list, else returns -1. */
int have_donor(char *last_name, char *first_name, donor_t donors[], int data_amount){
    int have = FALSE,
        ix;

    for(ix = 0; ix < data_amount; ix++){
        if( strcmp(donors[ix].last_name, last_name) == 0 &&
            strcmp(donors[ix].first_name, first_name) == 0)
        {
            have = TRUE;
            break;
        }
    }

    if(have)
        return(ix);
    else
        return(-1);
}

/*  update the donor    */
void update_donor(int ix, double donation, donor_t donors[]){
    donors[ix].total_donations += donation;
}

void add_donor(donor_t donors[], int *data_amount_p, char *last_name, char *first_name, double donation){
    donor_t new_donor;
    strcpy(new_donor.last_name, last_name);
    strcpy(new_donor.first_name, first_name);

    new_donor.total_donations = donation;

    printf("Enter the city of %s %s > ", new_donor.first_name, new_donor.last_name);
    scanf("%s", new_donor.city);
    printf("Enter the 1. adress of %s %s > ", new_donor.first_name, new_donor.last_name);
    scanf("%s", new_donor.str_adr_1);
    printf("Enter the 2. adress of %s %s > ", new_donor.first_name, new_donor.last_name);
    scanf("%s", new_donor.str_adr_2);
    printf("Enter two-character state abbreviation of %s %s > ", new_donor.first_name, new_donor.last_name);
    scanf("%s", new_donor.state_abbr);
    printf("Enter the zip code of %s %s > ", new_donor.first_name, new_donor.last_name);
    scanf("%d", &new_donor.zip_code);

    donors[*data_amount_p] = new_donor;
    *data_amount_p += 1;
}

/*  write output file thanks    */
void thank_letters(char *output_name, donor_t donors[], int data_amount){
    FILE *fp_out = fopen(output_name, "w");
    int ix;

    for(ix = 0; ix < data_amount; ix++){

        fprintf(fp_out, "\n\n\n\n\n\n\n\n\n\nThank you %s %s for donating %.2f this year!", 
        donors[ix].last_name, donors[ix].first_name,
        donors[ix].total_donations);
    }

    fclose(fp_out);
}

/*  sort the list   */
void sort_list(donor_t donors[], int data_amount){
    donor_t temp;
    int ix,
        prior_ix;
    
    for(ix = 0; ix < data_amount; ix++){
        prior_ix = prior_in_range(ix, data_amount, donors);
        if(ix != prior_ix){
            temp = donors[ix];
            donors[ix] = donors[prior_ix];
            donors[prior_ix] = temp;
        }
    }
}

/*  return the donor which has priority.    */
donor_t prior(donor_t donor0, donor_t donor1){
    if(strcmp(donor0.last_name, donor1.last_name) == -1)
        return(donor0);
    else
        return(donor1);
}


/*  return the index of the donor which has priority.     */
int prior_in_range(int min, int max, donor_t donors[]){
    int prior_ix = min,
        ix;

    for(ix = min; ix < max; ix++){
        if(same_donor(prior(donors[ix], donors[prior_ix]), donors[ix]) == TRUE)
            prior_ix = ix;
    }
    return prior_ix;
}

/*  return 1 if the donors are same.    */
int same_donor(donor_t donor0, donor_t donor1){
    return( strcmp(donor0.first_name, donor1.first_name) == 0 &&
            strcmp(donor0.last_name, donor1.last_name) == 0);
}

/*  print the list (shitty.)    */
void print_list(donor_t donors[], int data_amount){
    int ix;
    for(ix = 0; ix < data_amount; ix++){
        print_donor(donors[ix]);
        printf("\n\n\n");
    }
}

/*  update the list */
void update_list(donor_t donors[], int data_amount, char *file_name, char *organization_name){
    FILE *fp_out = fopen(file_name, "w");
    int ix;

    fprintf(fp_out, "%s", organization_name);

    for(ix = 0; ix < data_amount; ix++){
        fprintf(fp_out, "\n%s\n%s\n%s\n%s\n%s\n%s\n%d\n%.2f", 
        donors[ix].last_name, donors[ix].first_name, donors[ix].str_adr_1,
        donors[ix].str_adr_2, donors[ix].city, donors[ix].state_abbr,
        donors[ix].zip_code, donors[ix].total_donations);
    }
    fclose(fp_out);
}