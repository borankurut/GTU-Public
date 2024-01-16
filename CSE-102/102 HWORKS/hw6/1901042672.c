#include <stdio.h>
#include <stdlib.h>
#define N 3


void shuffle(int board[N][N]);/*function to shuffle the board.*/
void print_board(int board[N][N]);/*function to print the board.*/
void fill_board(int board[N][N]);/*fill the board with randomly placed numbers.*/
void move(int direction, int i, int j, int board[N][N]);/*move the board (starting with given location) in the given direction*/
int is_solved(int board[N][N]);/*returns 1 if the board is solved, otherwise returns 0. */


int main(){

	enum{left, right, up, down};

	int board[N][N];
	
	fill_board(board);

	print_board(board);
	
	printf("Please enter the direction and then the location. Like: 'left 0 1'\nTo end the game type 'give up'\n");
	
	char direction[10];
	int i,j;
	int k;
	while(is_solved(board)!=1){
		scanf("%s %d %d",direction,&i,&j);
		
		if(direction[0]=='l')	
			move(left,i,j,board);
		else if(direction[0]=='r')
			move(right,i,j,board);
		else if(direction[0]=='u')	
			move(up,i,j,board);
		else if(direction[0]=='d')	
			move(down,i,j,board);/*string comparison by the first letter.*/
		else if(direction[0]=='g'){
			printf("Game Over!\n");
			break;
			}
		print_board(board);
	}
	
	if(is_solved(board)==1)
		printf("You solved the puzzle!\n");
	
}
void fill_board(int board[N][N]){

	int x=0;
	int i;
	for(i=0;i<N;i++){
		int j;
		for(j=0;j<N;j++){
			board[i][j]=x;
			x++;
		}
	}/*fill the board.*/
	
	while(is_solved(board)==1)/*shuffle the board until it becomes unsolved.*/
		shuffle(board);
		

}

void shuffle(int board[N][N]){

	int number_of_shuffle = N*N*N*N;/*this number of move function will be executed..*/
	int i;
	for(i=0;i<number_of_shuffle;i++)
	{
		move(rand()%4,rand()%N,rand()%N,board);/*puzzle shuffled using move function so all outputs should be solvable. */
	}
	system("clear");/*clear the move function feedbacks.*/
}

void print_board(int board[N][N]){

	printf("\n");
	int k;
	for(k=0;k<=N*8;k++) /*print row lines.*/
		printf("_");
	printf("\n");
	int i;
	for(i=0;i<N;i++){
		int j;
		for(j=0;j<N;j++){
			if(board[i][j] == 0)
				printf("  \t|");/*0 is blank.*/
			else
				printf("%-2d\t|",board[i][j]);/*print numbers and column lines.*/
		}
		printf("\n");
		for(k=0;k<=N*8;k++)/*print row lines.*/
			printf("_");
		printf("\n");
	}	
}
void move(int direction, int i, int j, int board[N][N]){


	int board_moved[N][N];
	int a;
	for(a=0;a<N;a++){
		int b;
		for(b=0;b<N;b++){
			board_moved[a][b] = board[a][b];
		}	
	}/*declaring the changed version of the board.*/

	if( ((i>=0 && i<N)&&(j>=0 && j<N)) != 1){/*location is out of the board.*/
		printf("Invalid location.\n");
		return;
	}
	if(board[i][j] == 0){
		printf("Blank can't be moved.\n"); /*location is blank.*/
		return;
	}
	
	int is_there_0 = 0; /*check if there is a blank left side.*/
	int blank_i,blank_j;/*location of the blank.*/
	
	switch(direction){
		case 0:/*left*/
		
			if(j==0){/*already on the left side of the board.*/
				printf("Invalid move left from %d\n",board[i][j]);
				break;
			}
			int k;
			for(k=j; k!=-1;k--)/*find the blank*/
				if(board_moved[i][k]==0){
					is_there_0 = 1;
					blank_i = i;
					blank_j = k;
					}
			
			if(is_there_0 == 0){/*there isn't any blank.*/
				printf("There isn't any blank to move left from %d\n",board[i][j]);
				break;
				}
				
			printf("Moving left from number %d\n",board[i][j]);
			for(k=blank_j;k<j;k++){/*move the elements to the left.*/
				board_moved[i][k] = board_moved[i][k+1];
			}
			
			board_moved[i][j] = 0;/*blank transfered to its new location.*/
			
			for(a=0;a<N;a++){
				int b;
				for(b=0;b<N;b++){
					board[a][b] = board_moved[a][b];
				}	
			}/*board_moved returned.*/
			
			break;
		case 1:/*right*/
			if(j==N-1){/*already on the right side of the board.*/
				printf("Invalid move left from %d\n",board[i][j]);
				break;
			}
			for(k=j; k!=N; k++)/*find the blank*/
				if(board_moved[i][k]==0){
					is_there_0 = 1;
					blank_i = i;
					blank_j = k;
					}
			if(is_there_0 == 0){/*there isn't any blank.*/
				printf("There isn't any blank to move right from %d\n",board[i][j]);
				break;
				}
			printf("Moving right from number %d\n",board[i][j]);
			
			for(k=blank_j;k>j;k--){/*move the elements to the right.*/
				board_moved[i][k] = board_moved[i][k-1];
			}
			
			board_moved[i][j] = 0;/*blank transfered to its new location.*/
			for(a=0;a<N;a++){
				int b;
				for(b=0;b<N;b++){
					board[a][b] = board_moved[a][b];
				}	
			}/*board_moved returned.*/

			break;
		case 2:/*up*/
			if(i==0){/*already on the top of the board.*/
				printf("Invalid move up from %d\n",board[i][j]);
				break;
			}
			for(k=i; k!=-1; k--)/*find the blank*/
				if(board_moved[k][j]==0){
					is_there_0 = 1;
					blank_i = k;
					blank_j = j;
					}
			if(is_there_0 == 0){/*there isn't any blank.*/
				printf("There isn't any blank to move up from %d\n",board[i][j]);
				break;
				}
			printf("Moving up from number %d\n",board[i][j]);
			for(k=blank_i;k<i;k++){/*move the elements to the up.*/
				board_moved[k][j] = board_moved[k+1][j];
			}
			
			board_moved[i][j] = 0;/*blank transfered to its new location.*/
			for(a=0;a<N;a++){
				int b;
				for(b=0;b<N;b++){
					board[a][b] = board_moved[a][b];
				}	
			}/*board_moved returned.*/

			break;
		case 3:/*down*/
			if(i==N-1){/*already on the bottom of the board.*/
				printf("Invalid move down from %d\n",board[i][j]);
				break;
			}
			for(k=i; k!=N; k++)/*find the blank*/
				if(board_moved[k][j]==0){
					is_there_0 = 1;
					blank_i = k;
					blank_j = j;
					}
			if(is_there_0 == 0){/*there isn't any blank.*/
				printf("There isn't any blank to move down from %d\n",board[i][j]);
				break;
				}
			printf("Moving down from number %d\n",board[i][j]);
			for(k=blank_i;k>i;k--){/*move the elements to the up.*/
				board_moved[k][j] = board_moved[k-1][j];
			}
			
			board_moved[i][j] = 0;/*blank transfered to its new location.*/
			for(a=0;a<N;a++){
				int b;
				for(b=0;b<N;b++){
					board[a][b] = board_moved[a][b];
				}	
			}/*board_moved returned.*/

			break;
		default:
			printf("Direction error.\n");
			break;
	}
}
int is_solved(int board[N][N]){
	int correct_place_counter = 0;
	int current;
	int previous = board[0][0];
	int i;
	for(i=0;i<N;i++){
		int j;
		for(j=0;j<N;j++){
		
			if(i==0&&j==0)/*first term.*/
				continue;
				
			current = board[i][j];
			
			if(current==0)/*current element is the blank*/
				continue;
			
			if(current>previous)
				correct_place_counter +=1;
				
			previous = current;
		}
	}
	if(board[0][0]==0)
		correct_place_counter -= 1;/*previous was equal to 0.*/
		
	if(correct_place_counter >= N*N-2)
		return 1;
	else 
		return 0;
}
