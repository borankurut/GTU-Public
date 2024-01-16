#include <stdio.h>

typedef struct{
    int voltage1,voltage2,
        n1,n2,
        current1,current2;
}transformer_t;

int scan_transformer(transformer_t *transformer);
void print_transformer(transformer_t transformer);

int main(void){
    transformer_t my_transformer;
    scan_transformer(&my_transformer);
    print_transformer(my_transformer);
    return (0);
}

int scan_transformer(transformer_t *transformer){
    int status;
    printf("Enter voltage1, voltage2, n1, n2, current1, current2\n>");
    status = scanf("%d %d %d %d %d %d", &transformer->voltage1, &transformer->voltage2, &transformer->n1,
            &transformer->n2, &transformer->current1, &transformer->current2);

    if(status == 6)
        status = 1;

    else if(status != EOF)
        status = 0;

    return (status);
}

void print_transformer(transformer_t transformer){
    printf("V1: %d, V2: %d\nN1: %d, N2: %d\nI1: %d, I2: %d\n\n\n",transformer.voltage1,
            transformer.voltage2, transformer.n1, transformer.n2, transformer.current1,
            transformer.current2);
}

void set_n1_for_v2(transformer_t *transformer, int voltage2){
    transformer->voltage2 = voltage2;
    transformer->n1 = (transformer->n2 * transformer->voltage1) / transformer->voltage2;
}

void set_v1_for_v2(transformer_t *transformer, int voltage2){
    transformer->voltage2 = voltage2;
    transformer->voltage1 = (transformer->n1 * transformer->voltage2) / transformer->n2;
}

void set_n2_for_v2(transformer_t *transformer, int voltage2){
    transformer->voltage2 = voltage2;
    transformer->n2 = (transformer->n1 * transformer->voltage2) / transformer->voltage1;
}


void set_n2_for_i2(transformer_t *transformer, int current2){
    transformer->current2 = current2;
    transformer->n2 = (transformer->n1 * transformer->current2) / transformer->current1;
}