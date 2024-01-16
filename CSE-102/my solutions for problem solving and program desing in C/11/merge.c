#include <stdio.h>

#define FILE_NAME_1         "merge_1.txt"
#define FILE_NAME_2         "merge_2.txt"
#define FILE_NAME_MERGED    "merged.txt"

void merge_file(char *file_name_input_1, char *file_name_input_2, char *file_name_result);

int main(void){
    merge_file(FILE_NAME_2, FILE_NAME_1, FILE_NAME_MERGED);
    return (0);
}

/*  
*   opens file_name_input_1 and file_name_input_2 and merges them in file_name_result.   
*/
void merge_file(char *file_name_input_1, char *file_name_input_2, char *file_name_result){
    FILE *fp_in1, *fp_in2, *fp_result;
    char c;

    fp_in1 = fopen(file_name_input_1, "r");
    fp_in2 = fopen(file_name_input_2, "r");
    fp_result = fopen(file_name_result, "w");

    while((c = getc(fp_in1)) != EOF){
        putc(c, fp_result);
    }

    putc('\n', fp_result);

    while((c = getc(fp_in2)) != EOF){
        putc(c, fp_result);
    }


    fclose(fp_in1);
    fclose(fp_in2);
    fclose(fp_result);
}