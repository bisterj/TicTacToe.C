#include <stdio.h>

int main(){
	// declaration for function that looks for wins
	int test_win(char board[]);

	void make_move(int turn, char board[], int move[]);
	
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
	
	while (test_win(board) == 1){
	printf("%s\n", board);
	printf("It is x's turn.\nWhere would you like to play?\n(e.g. 0 0 = top left, 1 2 = middle right)\nMake sure its number space number\nYour Move:");
	scanf("%d %d", &move[0], &move[1]);
	make_move(turn, board, move);
	}
	
	// Text will be printed if you won.
	printf("%s\n", board);
	if(test_win(board) == 0){
	printf("Yay, you won!");
	};
	

	// End of main function.
	return 0;
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