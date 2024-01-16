#include <stdio.h>

#define IN_NAME             "examdat.txt"
#define MAX_QUESTION_NUMBER 50
#define MAX_CHOICE          4  
#define Q_POINT             20

int fgetAnswers(FILE *fp_input, int *id, int *nmb_of_qst, char answers[], int is_first);
int compute_score(char answers[], char correct_answers[], int nmb_of_qst);

int main(void){
    FILE *fp_input = fopen(IN_NAME, "r");

    int id, nmb_of_qst, status, score;
    char answers[MAX_QUESTION_NUMBER], correct_answers[MAX_QUESTION_NUMBER];
    int i;

    status = fgetAnswers(fp_input, &id, &nmb_of_qst, correct_answers, 1);

    printf("\t\tExam Report\n");
    printf("Question\t");
    for(i = 0; i < nmb_of_qst; i++){
        printf("%d ", i + 1);
    }
    printf("\nAnswer\t\t");
    for(i = 0; i < nmb_of_qst; i++){
        printf("%c ", correct_answers[i]);
    }
    printf("\n");
    printf("ID\tScore(%%)\n");

    while(status){
        status = fgetAnswers(fp_input, &id, &nmb_of_qst, answers, 0);
        if(status){
            score = compute_score(answers, correct_answers, nmb_of_qst);
            printf("%d\t%d\n", id, score);
        }
    }

    fclose(fp_input);
    return (0);
}

int fgetAnswers(FILE *fp_input, int *id, int *nmb_of_qst, char answers[], int is_first){
    if(is_first){

        int status = fscanf(fp_input, "%d ", nmb_of_qst);

        if(status != 1 || *nmb_of_qst > MAX_QUESTION_NUMBER){
            printf("Error\nStatus: %d\nNumber of questions: %d\nMax number of questions: %d\n", status, nmb_of_qst, MAX_QUESTION_NUMBER);
            return (0);
        }
        int i;
        for(i = 0; i < *nmb_of_qst; i++){
            status = fscanf(fp_input, "%c", &answers[i]);
            if(status == 0){
                printf("Error:\nWrong correct answer input\n");
                return (0);
            }
        }
    }

    else{
        int status = fscanf(fp_input, "%d ", id);
        if(status == EOF)
            return (0);
        else if(status != 1){
            printf("Error\nInvalid id:%d", *id);
            return (0);
        }
        int i;
        for(i = 0; i < *nmb_of_qst; i++){
            status = fscanf(fp_input, "%c", &answers[i]);
            if(status == 0){
                printf("Error:\nWrong answer input\nStudent id:%d", *id);
                return (0);
            }
        }
    }
    return (1);
}

int compute_score(char answers[], char correct_answers[], int nmb_of_qst){
    int i, score = 0;
    for(i = 0; i < nmb_of_qst; i++){
        if(correct_answers[i] == answers[i])
            score += Q_POINT;
    }
    return score;
}