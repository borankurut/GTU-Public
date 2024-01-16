#include <stdio.h>

#define GRID_SIZE_X     5
#define GRID_SIZE_Y     5
#define FULL            1
#define EMPTY           0
#define TRUE            1
#define FALSE           0

void print_grid(int grid[][GRID_SIZE_Y]);
char mark(int cell_num);
int valid_cell(int cell_x, int cell_y, int grid[][GRID_SIZE_Y]);
int search_near(int cell_x, int cell_y, int grid[][GRID_SIZE_Y], int *found_xp, int *found_yp);
void search_near_driver(int grid[][GRID_SIZE_Y]);
int count_objects(int grid[][GRID_SIZE_Y]);
void copy_grid(int copy[][GRID_SIZE_Y], int grid[][GRID_SIZE_Y]);
void find_object(int grid_copy[][GRID_SIZE_Y], int i, int j);
int blob_check(int grid_copy[][GRID_SIZE_Y], int i, int j);


int main(void){

    int grid[GRID_SIZE_X][GRID_SIZE_Y] =  
    {{1, 1, 0, 0, 1},
    { 0, 1, 1, 0, 0},
    { 0, 0, 1, 0, 1},
    { 1, 0, 0, 0, 1},
    { 0, 1, 0, 1, 1}};

    print_grid(grid);
    printf("\n%d objects found\n",count_objects(grid));
    return (0);
}

void print_grid(int grid[][GRID_SIZE_Y]){
    int i, j;
    for(i = 0; i < GRID_SIZE_X; i++){
        for (j = 0; j < GRID_SIZE_Y; j++)
            printf("%c", mark(grid[i][j]));
        printf("\n");
    }
}

char mark(int cell_num){
    char result;
    if(cell_num == 1)
        result = 254;   /*  filled square   */
    else if(cell_num == 0)
        result = 'O';
    else
        result = '?';

    return result;
}

/*  returns whether the given cell is valid.    */
int valid_cell(int cell_x, int cell_y, int grid[][GRID_SIZE_Y]){  
    int result = 1;

    if( cell_x < 0 ||
        cell_y < 0 || 
        cell_x >= GRID_SIZE_X || 
        cell_y >= GRID_SIZE_Y)
    {
        result = 0;
    }
    
    return result;
}


/*  returns whether a full cell found near given cell and returns that cell by output parameters */
int search_near(int cell_x, int cell_y, int grid[][GRID_SIZE_Y], int *found_xp, int *found_yp){
    int i, j, found = 0;
    *found_xp = -1;
    *found_yp = -1;

    if(valid_cell(cell_x, cell_y, grid) == FALSE){
        printf("Error: invalid search_near parameters.\n");
    }

    for(i = -1; i < 2; i ++){       /*  search for different x's    */
        for(j = -1; j < 2; j++){    /*  search for different y's    */
                if(valid_cell(cell_x + i, cell_y + j, grid) && grid[cell_x + i][cell_y + j] == FULL){
                /*  a full valid cell has been found.   */

                    if(i != 0 || j != 0){   /*  if cell isn't the same. */{
                        found = 1;
                        *found_xp = cell_x + i;
                        *found_yp = cell_y + j;
                    }
                }
            }
        }
        if(found)
            break;
    }
    return (found);
}

/*  driver function for function search_near    */
void search_near_driver(int grid[][GRID_SIZE_Y]){
    int foundx, foundy, is_found;

    is_found = search_near(0, 0, grid, &foundx, &foundy);
    printf("is found:%d\tfound x:%d\tfound y:%d\n", is_found, foundx, foundy);

    while(is_found != 0){
        grid[foundx][foundy] = EMPTY;
        int new_foundx, new_foundy;
        is_found = search_near(foundx, foundy, grid, &new_foundx, &new_foundy);
        printf("is found:%d\tfound x:%d\tfound y:%d\n", is_found, new_foundx, new_foundy);
        foundx = new_foundx;
        foundy = new_foundy;
    }
}

/*  count the objects in the given grid.    */
int count_objects(int grid[][GRID_SIZE_Y]){
    int objects = 0;
    int found;
    int i, j;
    int grid_copy[GRID_SIZE_X][GRID_SIZE_Y];
    copy_grid(grid_copy, grid);

    for(i = 0; i < GRID_SIZE_X; i++)
        for(j = 0; j < GRID_SIZE_Y; j++)
            if(grid_copy[i][j] == FULL){
                objects += 1;
                find_object(grid_copy, i, j);
            }   
    return (objects);

}

/*  copies grid into copy    */
void copy_grid(int copy[][GRID_SIZE_Y], int grid[][GRID_SIZE_Y]){
    int i, j;
    for(i = 0; i < GRID_SIZE_X; i++)
        for(j = 0; j < GRID_SIZE_Y; j++)
            copy[i][j] = grid[i][j];
}

/*  
*   find the related object with grid[i][j]
*   using blob_check function.
*/
void find_object(int grid_copy[][GRID_SIZE_Y], int i, int j){
    int blobs;
    blobs = blob_check(grid_copy, i, j);
    printf("Object with %d amount of blobs found. \n", blobs);
}

/*
*   returns the related full squares.
*   this function makes counted places 0 to prevent
*   counting again.
*/
int blob_check(int grid_copy[][GRID_SIZE_Y], int i, int j){
        int found = TRUE,
        new_found_x,
        new_found_y,
        found_x,
        found_y,
        blobs = 0,
        result;

    found_x = i;
    found_y = j;

    if(grid_copy[i][j] == FULL && valid_cell(i, j, grid_copy) == TRUE){
        grid_copy[i][j] = EMPTY;

        while(found){
            blobs += 1;
            found = search_near(found_x, found_y, grid_copy, &new_found_x, &new_found_y);
            grid_copy[found_x][found_y] = EMPTY;
            found_x = new_found_x;
            found_y = new_found_y;
        }
    }
    return (blobs);
}