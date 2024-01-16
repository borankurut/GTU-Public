#include <stdio.h>

void one_ele_subs(char *subset);
void two_ele_subs(char *subset);
void three_ele_subs(char *subset);

int main(void){
    char subset[] = "ACEG";

    three_ele_subs(subset);


    return (0);
}

void one_ele_subs(char *subset){
    if(subset[0] != '\0'){
        printf("{%c}\n", subset[0]);
        one_ele_subs(&subset[1]);
    }
}

void two_ele_subs(char *subset){
    if(subset[0] != '\0'){
        int i = 1;
        while(subset[i] != '\0'){
            printf("{%c, %c}\n", subset[0], subset[i]);
            i += 1;
        }
        two_ele_subs(&subset[1]);
    }
}

void three_ele_subs(char *subset){
    if(subset[0] != '\0'){
        int i = 1;
        while(subset[i] != '\0'){
            int j = i + 1;
            while(subset[j] != '\0'){
                printf("{%c, %c, %c}\n", subset[0], subset[i], subset[j]);
                j+=1;
            }
            i+=1;
        }
        three_ele_subs(&subset[1]);
    }
}