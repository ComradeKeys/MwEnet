#include <stdio.h>

/**
 * 0 - Empty
 * 1 - X
 * 2 - O
 */
int grid[3][3];
int winner;

char getChar(int in) {
	if(in == 0) {
		return ' ';
	} else if(in == 1) {
		return 'X';
	} else {
		return 'O';
	}
}

int main() {
	printf("Welcome to Tick-Tack-Toe\n");
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			grid[i][j] = 0;
		}
	}
	int turn = 0;
	int running = 1;
	do {
		int r, c;
		int valid = 1;
		printf(" %c | %c | %c\n", getChar(grid[0][0]),
			getChar(grid[0][1]), getChar(grid[0][2]));
		printf("---+---+---\n");
		printf(" %c | %c | %c\n", getChar(grid[1][0]),
			getChar(grid[1][1]), getChar(grid[1][2]));
		printf("---+---+---\n");
		printf(" %c | %c | %c\n", getChar(grid[2][0]),
			getChar(grid[2][1]), getChar(grid[2][2]));

		if(!turn) printf("It's X's turn to play\n");
		else printf("It's O's turn to play\n");
		do {
			printf("Which box would you like to play on?\nRow: ");
			scanf("%d", &r);
			printf("Column: ");
			scanf("%d", &c);
			if(r < 3 && r > -1 && c < 3 && c > -1 && grid[r][c] == 0) {
				valid = 0;
			} else {
				printf("Your answer is invalid, please try again.\n");
			}
		} while(valid);
		grid[r][c] = turn ? 2 : 1;

		/* Check for win */
		for(int i = 0; i < 3; i++) {
			if(grid[i][0] == grid[i][1] && grid[i][0] == grid[i][2] && grid[i][0] != 0) {
				running = 0;
				winner = grid[i][0];
			} else if(grid[0][i] == grid[1][i] && grid[0][i] == grid[2][i] && grid[0][i] != 0) {
				running = 0;
				winner = grid[0][i];
			}
		}
		if(grid[0][0] == grid[1][1] && grid[0][0] == grid[2][2] && grid[0][0] != 0) {
			running = 0;
			winner = grid[0][0];
		} else if(grid[0][2] == grid[1][1] && grid[0][2] == grid[2][0] && grid[0][2] != 0) {
			running = 0;
			winner = grid[0][2];
		}

		turn = turn ? 0 : 1;

		if(!running) {
			if(winner == 1) {
				printf("X wins!\n\n");
			} else {
				printf("Y wins!\n\n");
			}
		}
	} while(running);

	return 0;
}
