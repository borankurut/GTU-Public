#include <stdio.h>

#define NO_DAY      -1
#define DAY         1
#define NAME_SIZ    20
#define MONTH_LEN   10

typedef struct{
    int year,
        day,    /*  if there is not a day data day equals NO_DAY    */
        month;
}date_t;

typedef struct{
    char meat_type;     /*  'R' for red meat, 'P' for poultry, 'F' for fish        */
    date_t date_packaging,
            date_expiration;
}meats_t;

typedef struct{
    char produce_type;  /*  'F' for fruit or 'V' for vegetable                      */
    date_t date_received;
}produce_t;

typedef struct {
    date_t date_expiration;
}dairy_t;

typedef struct{
    date_t date_expiration; /*  month and year only.    */
    int aisle_num,
        aisle_side;         /*  letter 'A' or 'B'       */
}canned_goods_t;

typedef struct{
    char category; /*   'C' for cleaning product, 'P' for pharmacy, 'O' for other       */
    int aisle_num,
        aisle_side;
}nonfoods_t;

typedef union{
    meats_t meat;
    produce_t produce;
    dairy_t dairy;
    canned_goods_t canned_good;
    nonfoods_t nonfood;
}item_data_t;

typedef struct{
    char name[NAME_SIZ];
    int cost;   /*  unit cost in cents.     */

    char category;  /*
                    *   'M' for meat,
                    *   'P' for produce,
                    *   'D' for dairy,
                    *   'C' for canned goods
                    *   and 'N' for nonfoods
                    */

    item_data_t item_data;  /*  based on category.  */
}item_t;

/*  prototypes  */
date_t scan_date(int is_there_day);
item_data_t scan_meat_data();
item_data_t scan_produce_data();
item_data_t scan_dairy_data();
item_data_t scan_canned_good_data();
item_data_t scan_nonfood_data();
int scan_item(item_t *item);

void display_item(item_t item, char months[][MONTH_LEN]);
void display_meat_data(item_data_t meat_data, char months[][MONTH_LEN]);
void display_produce_data(item_data_t produce_data, char months[][MONTH_LEN]);
void display_dairy_data(item_data_t dairy_data, char months[][MONTH_LEN]);
void display_canned_good_data(item_data_t canned_good_data, char months[][MONTH_LEN]);
void display_nonfood_data(item_data_t nonfood_data, char months[][MONTH_LEN]);
void display_date(date_t date, char months[][MONTH_LEN]);

int main(void){
    char months[][MONTH_LEN] = {"January", "February", "March", "April", "May","Jun", "July",
    "August", "September", "October", "November", "December"};

    item_t my_item;

    scan_item(&my_item);
    display_item(my_item, months);

    return (0);
}

date_t scan_date(int is_there_day){
    char line[100];
    date_t date;

    if(is_there_day == NO_DAY){
        scanf("%d %d", &date.month, &date.year);
        date.day = NO_DAY;
    }
    else{
        scanf("%d %d %d", &date.month, &date.day, &date.year);
    }

    return date;
}

int scan_item(item_t *item){
    item_data_t item_data;

    int status = scanf("%s %d%c ", item->name, &item->cost, &item->category);
    if(status == 3){

        status = 1;

        switch (item->category)
        {
        case 'M':
            item_data = scan_meat_data();
            break;

        case 'P':
            item_data = scan_produce_data();
            break;

        case 'D':
            item_data = scan_dairy_data();
            break;

        case 'C':
            item_data = scan_canned_good_data();
            break;

        case 'N':
            item_data = scan_nonfood_data();
            break;

        default:
            printf("\nInvalid item category.\n");
            status = 0;
            break;
        }
        
        item->item_data = item_data;
    }
    else
        status = 0;

    return (status);
}

item_data_t scan_meat_data(){
    item_data_t item_data;

    scanf("%c", &item_data.meat.meat_type);
    item_data.meat.date_packaging = scan_date(DAY);
    item_data.meat.date_expiration = scan_date(DAY);

    return(item_data);
}

item_data_t scan_produce_data(){
    item_data_t item_data;

    scanf("%c", &item_data.produce.produce_type);
    item_data.produce.date_received = scan_date(DAY);

    return(item_data);
}

item_data_t scan_dairy_data(){
    item_data_t item_data;

    item_data.dairy.date_expiration = scan_date(DAY);

    return(item_data);
}

item_data_t scan_canned_good_data(){
    item_data_t item_data;

    item_data.canned_good.date_expiration = scan_date(NO_DAY);
    scanf("%d", &item_data.canned_good.aisle_num);
    scanf("%c", &item_data.canned_good.aisle_side);

    return(item_data);
}

item_data_t scan_nonfood_data(){
    item_data_t item_data;

    scanf("%c", &item_data.nonfood.category);
    scanf("%d", &item_data.nonfood.aisle_num);
    scanf("%c", &item_data.nonfood.aisle_side);

    return(item_data);

}

void display_date(date_t date, char months[][MONTH_LEN]){
    
    if(date.day == NO_DAY)
        printf("%s of %d", months[date.month - 1], date.year);
    else
        printf("%d %s %d", date.day, months[date.month - 1], date.year);
}

void display_meat_data(item_data_t meat_data, char months[][MONTH_LEN]){
    printf("meat type: %c, packaged in ", meat_data.meat.meat_type);
    display_date(meat_data.meat.date_packaging, months);
    printf(" expires in ");
    display_date(meat_data.meat.date_expiration, months);
    printf("\n");
}

void display_produce_data(item_data_t produce_data, char months[][MONTH_LEN]){
    printf("produce type: %c, received in ", produce_data.produce.produce_type);
    display_date(produce_data.produce.date_received, months);
    printf("\n");
}

void display_dairy_data(item_data_t dairy_data, char months[][MONTH_LEN]){
    printf("expires in ");
    display_date(dairy_data.dairy.date_expiration, months);
    printf("\n");
}

void display_canned_good_data(item_data_t canned_good_data, char months[][MONTH_LEN]){
    printf("expires in ");
    display_date(canned_good_data.canned_good.date_expiration, months);
    printf(", and is displayed in aisle %d%c\n", canned_good_data.canned_good.aisle_num,
    canned_good_data.canned_good.aisle_side);
}

void display_nonfood_data(item_data_t nonfood_data, char months[][MONTH_LEN]){
    printf("category: ");
    switch (nonfood_data.nonfood.category)
    {
    case 'C':
        printf("cleaning product");
        break;

    case 'P':
        printf("pharmacy");
        break;

    case 'O':
        printf("other");
        break;

    default:    
        printf("Error: Invalid category");
        break;
    }
    printf(" and is displayed in aisle %d%c\n", nonfood_data.nonfood.aisle_num,
    nonfood_data.nonfood.aisle_side);

}

void display_item(item_t item, char months[][MONTH_LEN]){
    printf("The %s costs %d cents, ", item.name, item.cost);
    switch (item.category)
    {
    case 'M':
        display_meat_data(item.item_data, months);
        break;
    
    case 'P':
        display_produce_data(item.item_data, months);
        break;

    case 'D':    
        display_dairy_data(item.item_data, months);
        break;

    case 'C':    
        display_canned_good_data(item.item_data, months);
        break;

    case 'N':    
        display_nonfood_data(item.item_data, months);
        break;

    default:
        printf("Error: Invalid category.");
        break;
    }
}