#include <stdio.h>
#include <string.h>

#define NICK_LEN        10
#define MAX_DATA        100
#define SENTINEL_NICK   "none"
#define IN_FILE_NAME    "numeric_adress_input.txt"

typedef struct{
    int x,
        y,
        z,
        m;

    char nick[NICK_LEN];
}adress_t;

/*  Prototypes      */
int is_sentinel(adress_t adress);
int scan_adress(FILE *fp_in ,adress_t *adress);
void display_local_of(adress_t curr_adress, adress_t adress_array[], int ix);
int local_adress(adress_t adress0, adress_t adress1);

int main(void){
    FILE *fp_in = fopen(IN_FILE_NAME, "r");
    adress_t adress_array[MAX_DATA];
    int ix = 0,
        status;

    for(status = scan_adress(fp_in, &adress_array[ix]);
        status == 1;
        status = scan_adress(fp_in, &adress_array[ix]))
    {
        if(is_sentinel(adress_array[ix])){
            break;
        }
        else if(ix > MAX_DATA - 1){
            printf("Max data amount reached.\n");
            break;
        }
        display_local_of(adress_array[ix], adress_array, ix);
        ix += 1;
    }

    fclose(fp_in);
    return (0);
}

int is_sentinel(adress_t adress){
    return (adress.x == 0 && adress.y == 0 &&
            adress.z == 0 && adress.m == 0 &&
            strcmp(adress.nick, SENTINEL_NICK) == 0);
}

int scan_adress(FILE *fp_in ,adress_t *adress){
    /*  local variables */
    int x_l, y_l, z_l, m_l,
        status;
    char nick_l[NICK_LEN];

    status = fscanf(fp_in, "%d.%d.%d.%d %s", &x_l, &y_l, &z_l, &m_l, nick_l);

    if(status == 5){
        adress->x = x_l;
        adress->y = y_l;
        adress->z = z_l;
        adress->m = m_l;
        strcpy(adress->nick, nick_l);
        status = 1;
    }
    else if(status != EOF)
        status = 0;

    return (status);
}

int local_adress(adress_t adress0, adress_t adress1){
    return (adress0.x == adress1.x && adress0.y == adress1.y);
}

/*  displays if there is a local of current_adress before it in the adress array.  */
void display_local_of(adress_t curr_adress, adress_t adress_array[], int ix){
    int i;
    for(i = 0; i < ix; i++){
        if(local_adress(curr_adress, adress_array[i])){
            printf("Machines %s and %s are on the same local network.\n",
            curr_adress.nick, adress_array[i].nick);
        }
    }
}