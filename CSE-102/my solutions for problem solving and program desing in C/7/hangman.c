#include <stdio.h>

#define MAX_WRD 20  /*  maximum word length allowed     */
#define GUESS   10  /*  maximum guess amount allowed    */


/*  prototypes  */
int guess(char word[], char guessed[], char letter);
char ask_letter();
void print_carr(char arr[], int n);
int compare_carr(char arr1[], char arr2[], int n);
void clear_input();

int main(void){

    int i, is_found, user_won = 0;
    int word_length = 7;
    char guessed_letter;
    
    char word[MAX_WRD] = {'p', 'r', 'o', 'g', 'r', 'a', 'm'};   /*  word to be guessed          */
    char guessed[MAX_WRD];                                      /*  guessed characters so far   */

    for(i = 0; i < MAX_WRD; i++)
        guessed[i] = '*';           /*  initializing all elements of guessed to '*' */

    for(i = 0; i < GUESS; i++){

        printf("\nWrong guess remaining: %d\n\n", GUESS - i);
        
        print_carr(guessed, word_length);

        guessed_letter = ask_letter();
            
        is_found = guess(word, guessed, guessed_letter);
        if(is_found){
            printf("%c is in the word!\n", guessed_letter);
            i -= 1;
        }
        else
            printf("%c is not in the word :(\n", guessed_letter);
        
        if(compare_carr(guessed, word, word_length)){
            printf("You found the word:");
            print_carr(word, word_length);
            printf("\n");
            user_won = 1;
            break;
        }
    }

    if(user_won)
        printf("You won!\n");
    else
        printf("You lose :(\n");

    printf("Game Over!\n");
    return (0);
}

/*  return whether letter found in the word and update guessed if so.   */
int guess(char word[], char guessed[], char letter){
    int i,      
    found = 0;  /*   is letter in the list   */

    for(i = 0; i < MAX_WRD; i++){
        if(word[i] == letter && found != 1){
            if(guessed[i] != letter){
                guessed[i] = letter;
                found = 1;
            }
        }
    }
    return (found);
}

/*  prompt and get user guess    */
char ask_letter(){
    char guessed_letter, enter_char;
    int false_input;

    do{
        printf("Guess a letter\n>");
        scanf("%c%c", &guessed_letter, &enter_char);
        if(guessed_letter == '\n'){
            continue;
        }
        else if(guessed_letter < 'a' || guessed_letter > 'z'){
            false_input = 1;
            printf("\nPlease enter a lower case.\n");
        }
        else if(enter_char != '\n'){
            clear_input();
            false_input = 1;
            printf("\nPlease enter 'a' lower case.\n");
        }
        else
            false_input = 0;

    }while(false_input);


    
    return guessed_letter;
}

void print_carr(char arr[], int n){
    int i;
    printf("\n\t");
    for(i = 0; i < n; i++){
        printf("%c", arr[i]);
    }
    printf("\n");
}

/*  returns whether arr1 and arr2 is same   */
int compare_carr(char arr1[], char arr2[], int n){
    int result = 1,
        i;
    for(i = 0; i < n; i++)
        if(arr1[i] != arr2[i])
            result = 0;

    return result;
}

void clear_input(){
    char c;
    int status = scanf("%c", &c);
    while(status == 1 && c != '\n')
        status = scanf("%c", &c);
}