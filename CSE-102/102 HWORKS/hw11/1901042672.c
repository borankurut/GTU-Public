#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Movie_Budget{ /*node to hold the budget, year, name.*/
    int budget;
    int year;
    char name[100];
    struct Movie_Budget* next;
}Movie_Budget;

typedef struct Movie_Name{ /*node to hold the genre, name and the score of the movie.*/
    char genre[30];
    char name[100];
    double score;
    struct Movie_Name* next;
}Movie_Name;

void insert_movie_budget(int budget, int year, char name[50], Movie_Budget**root); /* insert new budget.*/
void insert_after_budget(Movie_Budget* after_this, Movie_Budget* new_budget);   /* sort budget */
void insert_movie_name(char genre[30], char name[50], double score, Movie_Name** root); /* insert new movie name struct*/
void instruct();/*instruct the user*/
void list_of_genres(Movie_Name** root);/*list the genres*/
void list_through_year(Movie_Budget** root, int oldest, int latest);/*list the movies between oldest and latest years.*/
void list_through_score(Movie_Name** root, double min, double max);/*list the movies between min and max scores*/

int main(){
    
    Movie_Budget* root_movie_budget = NULL;/*root of the budget node*/
    Movie_Name* root_movie_name = NULL;/*root of the name node*/
    char c;/*check wether the file ended*/
    char budget_string[50], genre[50], name[100], score_string[50], year_string[50]; /*strings to hold the values temporary.*/

    FILE *file = fopen("Movies.txt", "r");
    if (file == NULL)/*check if file does not exist.*/
    {
        printf("Cannot open file \n");
        exit(0);
    }
    while(fgetc(file) != EOF){
        fscanf(file, "%[^,],%[^,],%[^,],%[^,],%[^\n]", budget_string, genre, name, score_string, year_string);
        insert_movie_budget(atoi(budget_string), atoi(year_string), name, &root_movie_budget);
        insert_movie_name(genre, name, atof(score_string), &root_movie_name);
        /*get the values*/
    }
    fclose(file);/*close the file.*/

    instruct();
    while((c=getchar()) != '8'){
        if(c=='1'){
            printf("Entered 1: List of the sorted data:\n");
            Movie_Budget* curr_budget = root_movie_budget;

            while (curr_budget!=NULL)
            {
                Movie_Name* curr_name = root_movie_name; 
                while (curr_name!= NULL)
                {
                    if(strcmp(curr_name->name, curr_budget->name) == 0){ /*compare the names in 2 nodes to recieve related values*/
                        if(curr_budget->budget==0)
                            printf("Budget:unknown\t\t");
                        else
                            printf("Budget:$%-10d\t", curr_budget->budget);

                        printf("Genre:%-15s\t", curr_name->genre);
                        printf("Name: %-65s\t", curr_name->name);
                        printf("Score:%.1f\t", curr_name->score);
                        printf("Year:%d\n", curr_budget->year);
                        /*print the informations of the movie.*/
                    }
                    curr_name = curr_name->next;
                }
                curr_budget = curr_budget->next;
            }
            printf("Please select an operation>\n");
            
        }
        else if(c=='2'){
            printf("Entered 2: List of the genres:\n");
            list_of_genres(&root_movie_name);
            printf("Please select an operation>\n");
        }
        else if(c=='3'){
            printf("Entered 3: List of the movie through the years:\n");
            int old_year, late_year;
            printf("\nPlease enter the old year>");
            scanf("%d", &old_year);
            printf("\nPlease enter the late year>");
            scanf("%d", &late_year);
            list_through_year(&root_movie_budget,old_year,late_year);
            printf("Please select an operation>\n");
        }
        else if(c=='4'){
            printf("Entered 4: List of the movie through the scores:\n");
            double min, max;
            printf("\nPlease enter the min score>");
            scanf("%lf", &min);
            printf("\nPlease enter the max score>");
            scanf("%lf", &max);
            list_through_score(&root_movie_name,min,max);
            printf("Please select an operation>\n");

        }
        else if(c=='5'){
            printf("Entered 5: All information of a single movie:\n");
            char name_of_the_movie[100];
            printf("Please enter the name of the movie >");
            scanf("%s", name_of_the_movie);
            
            Movie_Name* curr_name = root_movie_name; 
            while (curr_name != NULL)
            {
                if(strcmp(name_of_the_movie, curr_name->name) == 0){/*find the asked movie*/
                    Movie_Budget* curr_budget = root_movie_budget;
                    while (curr_budget != NULL)
                    {
                        if(strcmp(curr_budget->name, curr_name->name) == 0){ /*compare the names to recieve related value.*/
                            if(curr_budget->budget==0)
                                printf("Budget: Unknown\t\t");
                            else
                                printf("Budget:$%-10d\t", curr_budget->budget);

                            printf("Genre:%-15s\t", curr_name->genre);
                            printf("Name: %-65s\t", curr_name->name);
                            printf("Score:%.1f\t", curr_name->score);
                            printf("Year:%d\n", curr_budget->year);
                        }
                        curr_budget = curr_budget->next;
                    }
                }
                curr_name = curr_name->next;
            }
            
        }
        else if(c=='6'){
            printf("Entered 6: Average of the IMDB scores:\n");
            double total=0;
            int counter=0;
            Movie_Name* curr_name = root_movie_name;
                while (curr_name != NULL){
                    total+= curr_name->score;
                    counter ++;
                    curr_name = curr_name->next;
                    /*compute the total score, total element and average.*/
                }
                printf("Average score:%.1f\n\n", total/(double)counter);
	            printf("Please select an operation>\n");
        }
        else if(c=='7'){
            printf("Entered 7: Frequence of the genres:\n");
            frequency_of_genres(&root_movie_name);
        }
        else{
            if(c!='8' && c!='\n'){
            printf("Try again\n");
            printf("Please select an operation>\n");
            }
        }
    }
    printf("Exiting.");
    return (0);
}

void insert_movie_budget(int budget, int year, char name[50], Movie_Budget**root){
    /*create new node.*/
    Movie_Budget* new_movie_budget = malloc(sizeof(Movie_Budget));
    new_movie_budget->budget = budget;
    new_movie_budget->year = year;
    strcpy(new_movie_budget->name, name);
    new_movie_budget->next = NULL;

    if(*root==NULL){/*if there is no root make the created node the root.*/
        *root = new_movie_budget;
        return;
    }

    if(year > (*root)->year || (year == (*root)->year && budget > (*root)->budget) ){ /*check root or the new value takes priority*/
        new_movie_budget->next = *root;
        *root = new_movie_budget;
        return;
    }

    Movie_Budget *curr = *root;
    while(curr->next != NULL){/*update if the given movie was in the node before*/
        if(strcmp(name, (curr->next->name)) == 0){
            curr->next->budget = budget;
            curr->next->year = year;
            return;
        }

        if(year > curr->next->year || (year == curr->next->year && budget > curr->next->budget)){/*find the place of the new node*/
            insert_after_budget(curr, new_movie_budget);
            return;
        }
        curr = curr->next;/*if none of the conditions above true then the new node has the last priority.*/
    }
    curr->next = new_movie_budget;
}
void insert_after_budget(Movie_Budget* after_this, Movie_Budget* new_budget){
    new_budget->next = after_this->next;
    after_this->next = new_budget;
}
void insert_movie_name(char genre[30], char name[100], double score, Movie_Name** root){
    /*create node*/
    Movie_Name* new_movie_name = malloc(sizeof(Movie_Name));
    strcpy(new_movie_name->genre, genre);
    strcpy(new_movie_name->name, name);
    new_movie_name->score = score;
    new_movie_name->next = NULL;

    if(*root == NULL){/*if there is no root make the created node the root.*/
        *root = new_movie_name;
        return;
    }
    if(score < (*root)->score){/*compare the priority for the root and new node.*/
        new_movie_name->next = *root;
        *root = new_movie_name;
        return;
    }

    Movie_Name* curr = *root;
    while(curr->next != NULL){/*find place to the new node.*/
        if(score < (curr->next->score)){
            insert_after_name(curr, new_movie_name);
            return;
        }

        if(strcmp(name, (curr->next->name)) == 0){/*update if the given movie was in the node before*/
            strcpy(curr->next->genre, genre);
            curr->next->score = score;
            return;
        }

        curr = curr->next;
    }
    curr->next = new_movie_name;
}
void insert_after_name(Movie_Name* after_this, Movie_Name* new_name){
    new_name->next = after_this->next;
    after_this->next = new_name;
}
void instruct(){
    printf("1. List of the sorted data \n");
    printf("2. List of the genres \n");
    printf("3. List of the movie through the years\n");
    printf("4. List of the movie through the scores\n");
    printf("5. All information of a single movie\n");
    printf("6. Average of the IMDB scores\n");
    printf("7. Frequence of the genres \n");
    printf("8. Exit \n");
    printf("\nPlease select an operation >\n");
}
void list_of_genres(Movie_Name** root){
    Movie_Name* curr = *root;
    int dif = 1;/*if it is a new genre*/
    int last_genre = 1;/*last place of a new genre in the array*/
    char genre[30][15];/*genre array*/
    while (curr != NULL){
        int i;
        for(i=0;i<last_genre;i++){
            if(strcmp(genre[i],curr->genre)==0)/*compare the genre in the node and the uniqe genres until the last uniqe genre*/
                dif = 0; /*if they are same genre in node is not a new genre.*/
        }
        for(i=last_genre;i<20;i++){
            if(dif==1){/*if the genre was a new genre then place it in the array*/
                strcpy(genre[i],curr->genre);
                last_genre++;
                break;
            }
        }
        dif = 1;
        curr = curr->next;
    }
    int i;
    for(i=0; i<20; i++)
        printf("%s\n", genre[i]);/*print the genre array.*/
}
void list_through_year(Movie_Budget** root, int oldest, int latest){
    int counter = 0;
    Movie_Budget* curr = *root;
    while(curr!=NULL){
        if(oldest <= (curr->year) && (curr->year) <= latest){/*check weather a movie in the range.*/
            printf("%-60s\t(%d)\n",curr->name, curr->year);
            counter++;
        }
        curr = curr->next;
    }
    if(counter==0){
        printf("No movies found.\n");
    }
}
void list_through_score(Movie_Name** root, double min, double max){
    int counter = 0;
    Movie_Name* curr = *root;
    while(curr!=NULL){
        if(min <= (curr->score) && (curr->score) <= max){/*check weather a movie in the range.*/
            printf("%-60s\t(%.1f)\n",curr->name, curr->score);
            counter++;
        }
        curr = curr->next;
    }
    if(counter==0){
        printf("No movies found.\n");
    }
}
void frequency_of_genres(Movie_Name** root){
    Movie_Name* curr = *root;
    
    int dif = 1;
    int last_genre = 1;
    char genre[30][15];
    int frequency [30];
    int a;
    for(a=0; a<30; a++){
        frequency[a] = 0;
    }
    while (curr != NULL){
        int i;
        for(i=0;i<last_genre;i++){
            if(strcmp(genre[i],curr->genre)==0)
                dif = 0;
        }
        for(i=last_genre;i<20;i++){
            if(dif==1){
                strcpy(genre[i],curr->genre);
                last_genre++;
                break;
            }
        }
        dif = 1;
        curr = curr->next;
    }/*same things with list_genre*/

    curr = *root;
    while (curr!=NULL){
        int i;
        for(i = 0; i<20; i++){
            if(strcmp(genre[i], curr->genre) == 0)/*compare the genres with the Movie_Name node and save the occurence amount*/
                frequency[i]++;
        }

        curr= curr->next;
    }
    int k;
    for(k = 0; k<20; k++){
        printf("genre:%s, frequency:%d\n", genre[k], frequency[k]);/*Print the genres and frequences*/
    }
}
