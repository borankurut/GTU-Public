#include <stdio.h>

#define SENTINEL 0
/*  id numbers of the items */
#define PIELS       1
#define COORS       2
#define BUD         3
#define IRON_CITY   4

int main(void){
    int piels, coors, bud, iron_city; /*    amount of items */
    int id, change; /*  id of the item and change amount(purchased or sold) of the item */
    printf("Please enter the inventory:\n");
    printf("Piels> ");
    scanf("%d", &piels);
    printf("Coors> ");
    scanf("%d", &coors);
    printf("Bud> ");
    scanf("%d", &bud);
    printf("Iron City> ");
    scanf("%d", &iron_city);
    
    printf("Please enter the id(Enter %d to terminate.)> ", SENTINEL);
    scanf("%d", &id);
    while(id != SENTINEL){
        printf("Please enter change of the item(id:%d)> ", id);
        scanf("%d", &change);
        if(id == PIELS)
            piels += change;
        else if(id == COORS)
            coors += change;
        else if(id == BUD)
            bud += change;
        else if(id == IRON_CITY)
            iron_city += change;
        printf("Please enter the id(Enter %d to terminate.)> ", SENTINEL);
        scanf("%d", &id);
    }
    printf("New inventory:\n");
    printf("Piels:%d\nCoors:%d\nBud:%d\nIron City:%d\n", piels, coors, bud, iron_city);

    return (0);
}