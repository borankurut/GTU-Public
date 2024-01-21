#include <stdio.h>
typedef enum { false, true } bool;

#define GRID_ROW 6
#define GRID_COLUMN 7
#define N 3 
#define MAX_GRID 256

char grid[MAX_GRID];
char grid_buffer[MAX_GRID];

char input_grid[MAX_GRID] = {
    "..........O.......O.........OO.....OO....."
};

void fill_bombs();
void save_buffer();
void clear_grid();
void print_grid();
void init_grid();
void set_grid(char to[MAX_GRID] , char from[MAX_GRID]);
bool is_bomb(int row, int column);		// don't implement in mips
bool is_in_grid(int row, int column);
char element_in(int row, int column);	// don't impelemnt in mips
void explode(int row, int column);
void explode_all();
void print_state(int s);
int grid_ix(int row, int column);

int main(){

	//initial state
	init_grid();
	printf("INITIAL: \n");
	print_state(0);
	printf("\n\n\n");

	if(N < 1)
		return 0;
	//after one second do nothing.
	// s = 1
	print_state(1);
	
	if(N < 2)
		return 0;
	//plant bombs everywhere.
	//s = 2.
	save_buffer();
	fill_bombs();
	print_state(2);

	if(N < 3)
		return 0;

	//explode the bombs.
	//s = 3
	explode_all();
	print_state(3);

	//repeats last 2 steps.
	for(int i = 4; i <= N; ++i){
		if(i % 2 == 0){
			save_buffer();
			fill_bombs();
			print_state(i);
		}
		else{
			explode_all();
			print_state(i);
		}
	}

	return 0;
}

void print_grid(){
	printf("Grid: \n");
	for(int i = 0; i < GRID_ROW; ++i){
		for(int j = 0; j < GRID_COLUMN; ++j)
			printf("%c", grid[grid_ix(i, j)]);
		printf("\n");
	}
	printf("\n");
}

void init_grid(){
	set_grid(grid, input_grid);
}

//don't use in mips
bool is_bomb(int row, int column){
	char element = element_in(row, column);
	return element == 'O';
}

bool is_in_grid(int row, int column){
	return !(row < 0 || row >= GRID_ROW || column < 0 || column >= GRID_COLUMN);
}

// don't use in mips
char element_in(int row, int column){
	if(!is_in_grid(row, column)){
		printf("ERROR: trying to reach an element(%d, %d) that is not in grid\n", row, column);
		return 'e';
	}

	return grid[grid_ix(row, column)];
}

void explode(int row, int column){
	grid[grid_ix(row, column)] = '.';

	if(is_in_grid(row - 1, column))
		grid[grid_ix(row - 1, column)] = '.';

	if(is_in_grid(row + 1, column))
		grid[grid_ix(row + 1, column)] = '.';

	if(is_in_grid(row, column - 1))
		grid[grid_ix(row , column - 1)] = '.';

	if(is_in_grid(row, column + 1))
		grid[grid_ix(row, column + 1)] = '.';
}

void set_grid(char to[MAX_GRID] , char from[MAX_GRID]){
	for(int i = 0; i < GRID_ROW; ++i)
		for(int j = 0; j < GRID_COLUMN; ++j)
			to[grid_ix(i,j)] = from[grid_ix(i, j)];
}

void fill_bombs(){
	for(int i = 0; i < GRID_ROW; ++i)
		for(int j = 0; j < GRID_COLUMN; ++j)
			if(!is_bomb(i, j))		//don't check in mips
				grid[grid_ix(i, j)] = 'O';
}

void save_buffer(){
	set_grid(grid_buffer, grid);
}

void explode_all(){
	for(int i = 0; i < GRID_ROW; ++i)
		for(int j = 0; j < GRID_COLUMN; ++j)
			if(grid_buffer[grid_ix(i, j)] == 'O')
				explode(i, j);
}

void print_state(int s){
	printf("seconds passed: %d\n", s);	
	print_grid();
}

int grid_ix(int row, int column){
	return row * GRID_COLUMN + column;
}

