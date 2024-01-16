/*failed.*/
#include <stdio.h>
#include <math.h>

double find_root(double f(double x), double f_p(double x), double x0);

double cube_root(double x);
double cube_root_prime(double x);
double square_root(double x);
double square_root_prime(double x);

int is_root(double f(double x), double root);

int main(void){
    double root;
    root = find_root(cube_root, cube_root_prime, -1.0);
    return (0);
}

double find_root(double f(double x), double f_p(double x), double root){

    int count = 0;
    double h = 0.0000000001;
    while(count <= 100 && (is_root(f, root) == 0)){
        printf("root:%f\n", root);
        count ++;
        root = root - f(root) / f_p(root);
    }
    if(count != 100){
        printf("root found: %.2f\ncount:%d", root, count);
    }
    return root;
}

double cube_root(double x){
    double y = (cbrt(x));
    return y;
}

double cube_root_prime(double x){
    double y =1.0/(3.0 * cbrt(x*x));
    return y;
}

int is_root(double f(double x), double root){
    return(f(root) <= 0.01 && f(root) >= -0.01);
}

double square_root(double x){
    double y = sqrt(x);
    return y;
}

double square_root_prime(double x){
    double y = 1.0 / (2.0*sqrt(x));
    return y;
}