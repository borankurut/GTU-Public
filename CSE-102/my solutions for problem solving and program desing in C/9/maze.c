#include <stdio.h>

#define OUT         'O'
#define MAZE_ROW    8
#define MAZE_COLUMN 8

typedef enum{
    left, right, up, down
}   
direction_t;

void display_maze(char maze[][MAZE_COLUMN]);
void print_direction(direction_t direction);
char what_is_in(char maze[][MAZE_COLUMN], int cur_row, int cur_column, direction_t direction);
void find_new_location(int cur_row, int cur_column, int *res_rowp, int *res_columnp, direction_t direction);
void find_path(char maze[][MAZE_COLUMN], int cur_row, int cur_column, direction_t direction_before);
int is_valid(char maze[][MAZE_COLUMN], int cur_row, int cur_column);
int move(char maze[][MAZE_COLUMN], int *cur_rowp, int *cur_columnp, direction_t direction);

int main(void){

    char maze[8][8] = 
    {
        {' ', 'C', ' ', ' ', ' ', 'X', ' ', ' ' },
        {' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ' },
        {' ', ' ', ' ', ' ', 'X', 'X', ' ', ' ' },
        {'X', 'X', 'X', ' ', 'X', ' ', ' ', ' ' },
        {' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ' },
        {' ', ' ', 'X', 'X', 'X', 'X', ' ', ' ' },
        {' ', ' ', 'X', ' ', ' ', ' ', ' ', ' ' },
        {' ', ' ', ' ', ' ', ' ', 'X', ' ', 'E' },
    };
    int cur_row = 0,
        cur_column = 1;

    display_maze(maze);
    find_path(maze, cur_row, cur_column, left); /* the direction of the last find_path's move parameter.
                                                    first value doesn't matter.
                                                    */

    return (0);
}

int move(char maze[][MAZE_COLUMN], int *cur_rowp, int *cur_columnp, direction_t direction){
    int new_row,
        new_column,
        moved;
    find_new_location(*cur_rowp, *cur_columnp, &new_row, &new_column, direction);
    if(what_is_in(maze, *cur_rowp, *cur_columnp, direction) == ' '){
        maze[*cur_rowp][*cur_columnp] = ' ';
        *cur_rowp = new_row;
        *cur_columnp = new_column;
        maze[*cur_rowp][*cur_columnp] = 'C';
        moved = 1;
    }
    else
        moved = 0;

    return moved;
}

int is_valid(char maze[][MAZE_COLUMN], int cur_row, int cur_column){
    int valid = 1;

    if(cur_row < 0 || cur_column < 0)
        valid = 0;
    else if(cur_row >= MAZE_ROW || cur_column >= MAZE_COLUMN)
        valid = 0;

    return valid;
}

void find_path(char maze[][MAZE_COLUMN], int cur_row, int cur_column, direction_t direction_before){
    direction_t direction;

    if(what_is_in(maze, cur_row, cur_column, right) == 'E' ||
        what_is_in(maze, cur_row, cur_column, down) == 'E')
    {
            printf("Found!\n");
    }
    else if(what_is_in(maze, cur_row, cur_column, right) == ' ' && direction_before != left){
        move(maze, &cur_row, &cur_column, right);
        print_direction(right);
        //display_maze(maze);
        //getchar();
        printf("\n");
        find_path(maze, cur_row, cur_column, right);
    }
    else if(what_is_in(maze, cur_row, cur_column, down) == ' ' && direction_before != up){
        move(maze, &cur_row, &cur_column, down);
        print_direction(down);
        //display_maze(maze);
        //getchar();
        printf("\n");
        find_path(maze, cur_row, cur_column, down);
    }
    else if(what_is_in(maze, cur_row, cur_column, left) == ' ' && direction_before != right){
        move(maze, &cur_row, &cur_column, left);
        print_direction(left);
        //display_maze(maze);
        //getchar();
        printf("\n");
        find_path(maze, cur_row, cur_column, left);
    }
    else if(what_is_in(maze, cur_row, cur_column, up) == ' ', direction_before != down){
        move(maze, &cur_row, &cur_column, up);
        maze[cur_row + 1][cur_column] = '*';
        print_direction(up);
        //display_maze(maze);
        //getchar();
        printf("\n");
        find_path(maze, cur_row, cur_column, up);
    }
}

void find_new_location(int cur_row, int cur_column, int *res_rowp, int *res_columnp, direction_t direction){
    
    *res_rowp = cur_row;
    *res_columnp = cur_column;

    switch (direction)
    {
    case left:
        *res_columnp -= 1;
        break;

    case right:
        *res_columnp += 1;
        break;

    case up:
        *res_rowp -= 1;
        break;

    case down:
        *res_rowp += 1;
        break;
    
    default:
        printf("Error: Invalid direction\n");
        break;
    }
}

char what_is_in(char maze[][MAZE_COLUMN], int cur_row, int cur_column, direction_t direction){
    char result;

    int to_see_row,
        to_see_column;
    
    find_new_location(cur_row, cur_column, &to_see_row, &to_see_column, direction);

    if(is_valid(maze, to_see_row, to_see_column))
        result = maze[to_see_row][to_see_column];
    else
        result = OUT;

    return(result);
}

void print_direction(direction_t direction){
    switch (direction)
    {
    case left:
        printf("left");
        break;

    case right:
        printf("right");
        break;

    case up:
        printf("up");
        break;

    case down:
        printf("down");
        break;
    
    default:
        break;
    }
}

void display_maze(char maze[][MAZE_COLUMN]){
    int i,
        j;
    for(i = 0; i < MAZE_ROW; i++){
        printf("-----------------\n");
        printf("|");
        for(j = 0; j < MAZE_COLUMN; j++){
            printf("%c|", maze[i][j]);
        }
        printf("\n");
    }
    printf("-----------------\n");
    printf("\n\n\n");
}