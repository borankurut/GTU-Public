#include <stdio.h>

void display_binary (char *bin_num, int index);

int main(void){
    char binary_num[] = "x1x1x";
    display_binary(binary_num, 0);
    return (0);
}

void display_binary (char *bin_num, int index){
    if(bin_num[index] == 'x'){

        bin_num[index] = '0';
        display_binary(bin_num, index + 1);
        printf("%s\n", bin_num);
        bin_num[index] = '1';
        display_binary(bin_num, index + 1);
        printf("%s\n", bin_num);
    }
    if(index <= strlen(bin_num) - 2){
        display_binary(bin_num, index + 1);
    }

}