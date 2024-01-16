#include <stdio.h>
void print_content(char color);
int main(){
    char color;
    printf("Please enter the first letter of the cylinder's color\n>");
    scanf("%c", &color);
    print_content(color);
    return(0);
}

void print_content(char color){
    /*
    *   prints the contents of a cpmpressed-gas cylinder
    *   based on the first letter of the cylinder's color
    */
   switch (color)
   {
   case 'O':/*  orange  */
   case 'o':
       printf("ammonia\n");
       break;
   case 'B':/*  brown  */
   case 'b':
        printf("carbon monoxide\n");
        break;
    case 'Y':/*  yellow  */
    case 'y':
        printf("hydrogen\n");
        break;
    case 'G':/*  green  */
    case 'g':
        printf("oxygen\n");
        break;
   default:
        printf("Contents unknown.\n");
        break;
   }
}