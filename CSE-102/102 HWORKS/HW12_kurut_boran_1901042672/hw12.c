#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
typedef struct Vocable{
    char word[100];
    char syn[4][100];
    char ant[4][100];
    struct Vocable* next;
    int id;
    int ask_amount;
}Vocable;

void insert_new_word(Vocable** root);
void insert_end_vocable_syn(char word[100], char syn1[100], char syn2[100],
char syn3[100], char syn4[100], Vocable** root);

void insert_end_vocable_ant(char word[100], char ant1[100], char ant2[100],
char ant3[100], char ant4[100], Vocable** root);

void fill_syn(Vocable** root);
void fill_ant(Vocable** root);
void ask_question(Vocable** root);

void printlist(Vocable** root);
void instruct();
void modify(int id, char s_or_a, Vocable** root, char answer[100]);

int main(){
    srand(time(NULL));
    Vocable* root = NULL;
    char choice;
    int word_amount;
    fill_syn(&root);    /*  fill the list using synonim data.    */
    fill_ant(&root);    /*  fill the list using antonym data.    */

    Vocable* curr = root;
    while(curr->next!=NULL)
        curr= curr->next;
    word_amount = curr->id;
    
    instruct();
    scanf("%c", &choice);

    while(choice!= '3'){
        if(choice=='1'){
            int to_ask = rand()%word_amount;/*word to be asked*/
            curr = root;
            int i;
            for(i=0; i<to_ask; i++){
                curr = curr->next;
            }
            
            while(rand()%((curr->ask_amount)+2) != 1){  /*pass possibility based on ask amount.*/
                to_ask = rand()%word_amount;            /*1/2 for the first time, 2/3 for the second..*/
                curr = root;
                for(i=0; i<to_ask; i++){
                    curr = curr->next;
                }
            }

            if(strcmp(curr->syn[0], "") !=0 && strcmp(curr->ant[0], "") !=0){/*this word has both ant*/
                printf("antonym and syn.\n");                               /*and syn data.*/
            }

            else if(strcmp(curr->ant[0], "") !=0){/*    this word has only antonym data.    */
                char answer[100];
                int unknown = 1;
                printf("\nWhat is the antonym of: %s \n", curr->word);
                printf("Answers:");
                printf("'%s' '%s' '%s' '%s'\n>", curr->ant[0], curr->ant[1], curr->ant[2], curr->ant[3]);
                scanf("%s", answer);

                int k;
                for(k = 0; k<4; k++){
                    if(strcmp(answer, curr->ant[k])==0){
                        printf("True!\n");
                        unknown = 0;
                    }
                }
                if(unknown ==1){
                    char c;
                    printf("Is the answer true?('y' or 'n')\n>");/*if answer is true add to the list.*/
                    getchar();/*    ignore \n on the console.*/
                    scanf("%c", &c);
                    if(c=='y'){
                        modify(curr->id, 'a', &root, answer);
                    }
                }
            }
            else{   /*  this word has only synonym data.*/
                char answer[100];
                int unknown=1;
                printf("\nWhat is the synonym of: %s \n", curr->word);
                printf("Answers:");
                printf("'%s' '%s' '%s' '%s'\n>", curr->syn[0], curr->syn[1], curr->syn[2], curr->syn[3]);
                scanf("%s", answer);

                int k;
                for(k=0; k<4; k++){
                    if(strcmp(answer, curr->syn[k])==0){
                        printf("True!\n");
                        unknown = 0;
                    }
                }
                if(unknown==1){
                    char c;
                    printf("Is the answer true?('y' or 'n')\n>");/*if answer is true add to the list*/
                    getchar();/*    ignore \n on the console.   */
                    scanf("%c", &c);
                    if(c=='y'){
                        modify(curr->id, 's', &root, answer);
                    }
                }
            }
            curr->ask_amount +=1;

        }
        if(choice=='2')
            insert_new_word(&root);
        if(choice!='\n')/*  ignore \n */
            instruct();
        scanf("%c", &choice);
    }
    printf("Updating..\n");
    FILE* fp = fopen("synonims_up.txt","w");
    curr = root;
    while(curr->next!=NULL){
        if(strcmp(curr->syn[0], "")!=0)/*if there is syn data print the file.*/
            fprintf(fp, "%s = %s %s %s %s\n", curr->word, curr->syn[0], curr->syn[1], curr->syn[2], curr->syn[3]);
        curr= curr->next;
    }
    fclose(fp);
    fp = fopen("antonyms_up.txt", "w");
    curr = root;
    while(curr->next!=NULL){
        if(strcmp(curr->ant[0], "")!=0)/* if there is ant data print the file.*/
            fprintf(fp, "%s <> %s %s %s %s\n", curr->word, curr->ant[0], curr->ant[1], curr->ant[2], curr->ant[3]);
        curr= curr->next;
    }
    fclose(fp);
    return (0);
}

void insert_end_vocable_syn(char word[100], char syn1[100], char syn2[100],
char syn3[100], char syn4[100], Vocable** root){
    /*  this function creates new node with synonym data.  */
    Vocable* new_node = malloc(sizeof(Vocable));
    strcpy(new_node->word, word);
    strcpy(new_node->syn[0], syn1); /*  fill the synonims and empty the antonyms.   */
    strcpy(new_node->syn[1], syn2);
    strcpy(new_node->syn[2], syn3);
    strcpy(new_node->syn[3], syn4);
    strcpy(new_node->ant[0], "");
    strcpy(new_node->ant[1], "");
    strcpy(new_node->ant[2], "");
    strcpy(new_node->ant[3], "");
    new_node->ask_amount = 0;
    new_node->next = NULL;  

    if(*root == NULL){  /* if there isn't a root make the created node the root. */
        new_node->id = 0;
        *root = new_node;
        return;
    }

    Vocable* curr = *root;
    while(curr->next != NULL){
        curr = curr->next;
    }
    new_node->id= curr->id +1;
    curr->next = new_node;
}
void insert_end_vocable_ant(char word[100], char ant1[100], char ant2[100],
char ant3[100], char ant4[100], Vocable** root){
    /*  this function create new node with the antonym data.   */
    Vocable* new_node = malloc(sizeof(Vocable));
    strcpy(new_node->word, word);
    strcpy(new_node->ant[0], ant1); /*  fill the antonyms and empty the synonims.   */
    strcpy(new_node->ant[1], ant2);
    strcpy(new_node->ant[2], ant3);
    strcpy(new_node->ant[3], ant4);
    strcpy(new_node->syn[0], "");
    strcpy(new_node->syn[1], "");
    strcpy(new_node->syn[2], "");
    strcpy(new_node->syn[3], "");
    new_node->ask_amount = 0;
    new_node->next = NULL;

    Vocable* curr = *root;
    while(curr->next != NULL){
        curr = curr->next;
    }
    new_node->id= curr->id + 1;
    curr->next = new_node;
}
void printlist(Vocable** root){ /*  print the list  */
    Vocable* curr = *root;
    while(curr != NULL){
        printf("word:%s  syn1:%s  syn2:%s  ", curr->word, curr->syn[0], curr->syn[1]);
        printf("syn3:%s  syn4:%s  ant1:%s  ", curr->syn[2], curr->syn[3], curr->ant[0]);
        printf("ant2:%s  ant3:%s  ant4:%s  ", curr->ant[1], curr->ant[2], curr->ant[3]);
        printf("id:%d  ask_am:%d\n", curr->id, curr->ask_amount);
        curr = curr->next;
    }
}
void fill_syn(Vocable** root){
    /*  this function fills the list with synonims.txt file data.*/
    FILE* fp = fopen("synonims.txt","r");
    char word[100];
    char syn[4][100];
    char ant[4][100];
    char line[500];
    char* piece;

    while(fgets(line, 500, fp) != NULL) 
    {
        int len = strlen(line);
        if (len > 0 && line[len-1] == '\n') /*  remove '\n's in the line. */
            line[len-1] = '\0';
        int k;
        for(k =0; k<4; k++){
            strcpy(syn[k], ""); /*  empty syn array   */
        }
        strcpy(word, strtok(line, " "));    /*  get the word    */
        strtok(NULL, " ");  /*  skip '=' */
        int i;
        for(i=0; i<4; i++){ /*  get synonims of the word into syn array   */
            piece = strtok(NULL, " ");  
            if(piece == NULL) /*    the line ended   */
                break;
            strcpy(syn[i], piece);
        }
        insert_end_vocable_syn(word, syn[0], syn[1], syn[2], syn[3], root);
    }
    fclose(fp);
}
void fill_ant(Vocable** root){
    /*  this function fills the list with antonyms.txt file data.*/
    char word[100];
    char syn[4][100];
    char ant[4][100];
    char line[500];
    char* piece;
    FILE* fp = fopen("antonyms.txt","r");
    while(fgets(line, 500, fp)!= NULL){
        int word_exst = 0;
        int len = strlen(line);
        if (len > 0 && line[len-1] == '\n') /*  remove '\n's in the line. */
            line[len-1] = '\0';
        int k;
        for(k =0; k<4; k++){
            strcpy(ant[k], ""); /*  empty ant array   */
        }
        strcpy(word, strtok(line, " "));    /*  get the word    */
        strtok(NULL, " ");  /*  skip '<>' */
        int i;
        for(i=0; i<4; i++){ /*  get antonyms of the word into ant array   */
            piece = strtok(NULL, " ");  
            if(piece == NULL) /*    the line ended   */
                break;
            strcpy(ant[i], piece);
        }

        Vocable* curr = *root;
        while(curr != NULL){
            if(strcmp(curr->word, word)==0){    /*  word is in the list; don't create new node, */
                strcpy(curr->ant[0], ant[0]);   /*  update the existed one.                     */
                strcpy(curr->ant[1], ant[1]);
                strcpy(curr->ant[2], ant[2]);
                strcpy(curr->ant[3], ant[3]);
                word_exst = 1;
                break;
            }
            curr = curr->next;
        }
        if(word_exst==1)
            continue;
        else
            insert_end_vocable_ant(word, ant[0], ant[1], ant[2], ant[3], root);
    }
    fclose(fp);
}
void instruct(){
    printf("1 -> Ask\n2 -> Add new word\n3 -> Exit\n>");
}
void modify(int id, char s_or_a, Vocable** root, char answer[100]){
    Vocable* curr = *root;
    while(curr->id != id)
        curr = curr->next;
    if(s_or_a == 's'){
        printf("synonym adding...\n");
        int i;
        for(i =0; i<4; i++){
            if(strcmp(curr->syn[i], "") == 0){
                strcpy(curr->syn[i], answer);
                printf("Added.\n");
                return;
            }
        }
        printf("Full of syn!\n");
    }else if(s_or_a == 'a'){
        printf("antonym adding...\n");
        int i;
        for(i =0; i<4; i++){
            if(strcmp(curr->ant[i], "") == 0){
                strcpy(curr->ant[i], answer);
                printf("Added.\n");
                return;
            }
        }
        printf("Full of ant!\n");
    }
}
void insert_new_word(Vocable** root){
    /*  this function inserts new word to the list using given data.    */
    char word[100];
    char syn[4][100];
    char ant[4][100];
    printf("Please enter the word:\n>");
    scanf("%s", word);
    int i;
    for(i=0;i<4;i++){
        printf("syn%d:\n>",i);
        scanf("%s", syn[i]);
    }
    for(i=0;i<4;i++){
        printf("ant%d:\n>",i);
        scanf("%s", syn[i]);
    }
    Vocable* new_node = malloc(sizeof(Vocable));
    strcpy(new_node->word, word);
    for(i = 0; i<4; i++){
        strcpy(new_node->syn[i], syn[i]);
        strcpy(new_node->ant[i], ant[i]);
    }
    new_node->ask_amount = 0;
    new_node->next = NULL;

    Vocable* curr = *root;
    while(curr->next != NULL){
        curr = curr->next;
    }
    new_node->id= curr->id + 1;
    curr->next = new_node;
    printf("Added!\n");
}
