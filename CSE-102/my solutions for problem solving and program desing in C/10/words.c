#include <stdio.h>
#include <string.h>

#define LANG_LEN    20
#define WORD_LEN    20
#define MAX_WORDS   20
#define MAX_DATA    10
#define INPUT_NAME  "words_input.txt"

typedef struct{
    char language[LANG_LEN],
        words[MAX_WORDS][WORD_LEN];
    int word_amount;
}wordlist_t;

/*  Prototypes  */
void add_word(wordlist_t *wordlist, char *word);
int contains(wordlist_t wordlist, char *word);
void display_word_list(wordlist_t wordlist);
int load_word_list(char *input_name, wordlist_t wordlist_array[]);

int main(void){

    wordlist_t wordlist_array[MAX_DATA];

    int data_amount = load_word_list(INPUT_NAME, wordlist_array);
    int i;

    for(i = 0; i < data_amount; i++)
        display_word_list(wordlist_array[i]);

    
    return (0);
}

void add_word(wordlist_t *wordlist, char *word){

    if(wordlist->word_amount == MAX_WORDS){
        printf("List full, word not added.\n");
    }
    else if(contains(*wordlist, word) == 0){
        strcpy(wordlist->words[wordlist->word_amount], word);
        wordlist->word_amount += 1;
    }
}

int contains(wordlist_t wordlist, char *word){
    int is_in = 0,
        ix;

    for(ix = 0; ix < wordlist.word_amount; ix++){
        if(strcmp(wordlist.words[ix], word) == 0)
            is_in = 1;
    }

    return (is_in);
}

void display_word_list(wordlist_t wordlist){
    int i;
    printf("Language: %s\nWords: ", wordlist.language);
    for(i = 0; i < wordlist.word_amount; i++){
        printf("%s ", wordlist.words[i]);
    }
    printf("\n");
}

int load_word_list(char *input_name, wordlist_t wordlist_array[]){
    FILE *fp_in = fopen(input_name, "r");

    char buff[200];
    char *line = &buff[0];

    char word[WORD_LEN];

    int status;
    int i;

    for(i = 0; i < MAX_DATA; i++){
        fgets(line, 100, fp_in);
        status = sscanf(line, "%s", wordlist_array[i].language);
        line = &line[strlen(wordlist_array[i].language)];
        wordlist_array[i].word_amount = 0;

        if(status != 1){
            i -= 1;
            break;
        }

        while(status == 1){
            status = sscanf(line, "%s", word);
            add_word(&wordlist_array[i], word);
            line = &line[strlen(word) + 1];
        }
    }
    return (i);

    fclose(fp_in);
}