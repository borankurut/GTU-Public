#include <stdio.h>

int f(int x);

int main(void){
    printf("%d", f(6));
    return(0);
}

int f(int x){
    int y;

    if(x <= 0)
        y = 0;
    else
        y = f(x - 1) + 2;

    return y;
}