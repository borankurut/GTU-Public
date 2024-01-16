#include <stdio.h>

int main(void){
    int player, status;
    char c;

    status = scanf("%d", &player);
    while(status == 1){
        int bats = 0, hits = 0;
        printf("Player %d's record: ", player);

        scanf("%c", &c);
        while(c != '\n'){
            printf("%c", c);
            scanf("%c", &c);
            if(c == 'H'){
                hits += 1;
                bats += 1;
            }else if(c == 'O')
                bats += 1;
        }
        printf("\n");
        printf("Player %d's batting average: %.3f\n\n", player, (double)hits / (double)bats);
        status = scanf("%d", &player);
    }

    return (0);
}