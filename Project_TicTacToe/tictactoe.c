#include <stdio.h>

int main(){
	// WOW! look I made a crazy change!
	// declaration for function that looks for wins
	int test_win(char board[]);
	
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

	// Random testing stuff
	/* board[top_left] = 'x';
	board[bot_mid] = 'x';
	board[bot_right] = 'x'; */
	printf("%s\n", board);

	// Text will be printed if you won.
	if(test_win(board) == 0){
	printf("Yay, you won!");
	};

	// End of main function.
	return 0;
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