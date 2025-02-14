#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	// seeding the random thingy
	srand(time(NULL));
	// declaration for function that looks for wins
	int test_win(char board[]);

	void make_move(int turn, char board[], int move[]);

	void dumb_ai(char board[]);

	void rand_ai(char board[]);
	
	// This is the game board. Will have x's and o's instead of spaces as time goes on
	char board[] = " | | \n_____\n | | \n_____\n | | ";

	// This is just a set of indices for each 'square' on the board for easier indexing. 
	int top_left = 0;
	int top_mid = 2;
	int top_right = 4;
	int mid_left = 12;
	int mid_mid = 14;
	int mid_right = 16;
	int bot_left = 24;
	int bot_mid = 26;
	int bot_right = 28;
	
	int move[2];
	int turn = 0;
	// Game Loop...
	while (test_win(board) == 1){
	printf("%s\n", board);
	if (turn == 0){
	printf("It is x's turn.\nWhere would you like to play?\n(e.g. 0 0 = top left, 1 2 = middle right)\nMake sure its number space number\nYour Move:");
	scanf("%d %d", &move[0], &move[1]);
	make_move(turn, board, move);
	} else {
	printf("AI moving...\n");
	dumb_ai(board);
	}
	
	/*else {
	printf("It is o's turn.\nWhere would you like to play?\n(e.g. 0 0 = top left, 1 2 = middle right)\nMake sure its number space number\nYour Move:");
	}*/
	
	turn = (turn + 1) % 2;
	}
	
	// Text will be printed if you won.
	printf("%s\n", board);
	if(test_win(board) == 0){
	printf("Yay, you won!");
	};
	

	// End of main function.
	return 0;
}

void dumb_ai(char board[]){
	int move[2];
	//look for first open position
	for (int r = 2; r>-1; r--){
		for (int c = 0; c<3; c++){
			if (board[r*12 + c*2] == ' '){
				move[0] = r;
				move[1] = c;
				break;
			}
		}
	}
	printf("%d %d\n", move[0], move[1]);
	//make the move
	int index = move[0] * 12 + move[1] * 2;
	board[index] = 'o';
}

void rand_ai(char board[]){
	int move[2];
	move[0] = rand() % 3;
	move[1] = rand() % 3;
	int index = move[0] * 12 + move[1] * 2;
	while(board[index] != ' '){
	move[0] = rand() % 3;
	move[1] = rand() % 3;
	index = move[0] * 12 + move[1] * 2;
	}
	board[index] = 'o';
}

void make_move(int turn, char board[], int move[]){
	int index = move[0] * 12 + move[1] * 2;
	if (turn == 0){
	board[index] = 'x';
	} else {
	board[index] = 'o';
	}
}

int test_win(char board[]){
	// Those easy indices again...
	int top_left = 0;
	int top_mid = 2;
	int top_right = 4;
	int mid_left = 12;
	int mid_mid = 14;
	int mid_right = 16;
	int bot_left = 24;
	int bot_mid = 26;
	int bot_right = 28;
	
	// Checks each of the possible win conditions both for x and o, return of 0 means a win condition hs been met.
	if(board[top_left] != ' ' && board[top_left] == board[top_right] && board[top_right] == board[top_mid]){
	return 0;
	} else if(board[mid_left] != ' ' && board[mid_left] == board[mid_mid] && board[mid_mid] == board[mid_right]){
	return 0;
	} else if(board[bot_left] != ' ' && board[bot_left] == board[bot_mid] && board[bot_mid] == board[bot_right]){
	return 0;
	} else if(board[top_left] != ' ' && board[top_left] == board[mid_left] && board[mid_left] == board[bot_left]){
	return 0;
	} else if(board[top_mid] != ' ' && board[top_mid] == board[mid_mid] && board[mid_mid] == board[bot_mid]){
	return 0;
	} else if(board[top_right] != ' ' && board[top_right] == board[mid_right] && board[mid_right] == board[bot_right]){
	return 0;
	} else if(board[top_left] != ' ' && board[top_left] == board[mid_mid] && board[mid_mid] == board[bot_right]){
	return 0;
	} else if(board[top_right] != ' ' && board[top_right] == board[mid_mid] && board[mid_mid] == board[bot_left]){
	return 0;
	}

	// If no win condition is met, return 1 meaning false... so no win.
	return 1;
	
}