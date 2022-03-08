#include<stdio.h>

/*
If the given number is an valid row or column number(index) in an 6x6 2-d Array then isValidIndex()
returns 1 else returns 0
*/
int isValidIndex(int x) {
	return (x >= 0 && x < 6);
}

/*
Given (x,y) and (a,b) isAdjacentIndex() returns 1 if the elements referred by these indicies in an 6x6 2-d array is adjacent
else returns 0
*/
int isAdjacentIndex(int x, int y, int a, int b) {
	if ((x + 1 == a || x - 1 == a || (x == a && y != b)) && (y + 1 == b || y - 1 == b || (y == b && x != a))) 
	{
		return 1;
	}
	return 0;
}

/*
Given an 6x6 int array and the indicies of the player and the AI, displayGameBoard() prints the array in a matrix format with the
Player as 'P' and the AI as 'A'
*/
void displayGameBoard(int gameBoard[6][6], int aRow, int aCol, int pRow, int pCol) {
	printf("\n\t\t\t      1  2  3  4  5  6 \n");
	for (int i = 0; i < 6; i++) {
		printf("\t\t\t    %i ", i + 1);
		for (int j = 0; j < 6; j++) {
			if (aRow == i && aCol == j) {
				printf("%s  ", "A");
			}
			else if (pRow == i && pCol == j) {
				printf("%s  ", "P");
			}
			else {
				printf("%i  ", gameBoard[i][j]);
			}
		}
		putchar('\n');
	}
	return;
}

/*
Given an 6x6 int array and the indicies of the player and the AI, buildingLevelUp() increases
the value of all the elements in the row and column of the payer index by 1 if that element is not blocked by the AI.
It also increases the value of all the elements by 1 if they are in the line y=-x and y = x with the player index as origin
where y is the row index and x is the column index.
*/
void buildingLevelUp(int gameBoard[6][6], int aRow, int aCol, int pRow, int pCol) {
	
	//This loop that iterates through the row the player is in
	for (int i = ((aRow == pRow) && (aCol < pCol)) ? aCol + 1 : 0; i < 6; i++) {
		if ((aRow == pRow) && (i == aCol)) {
			break;
		}
		else if (i != pCol && gameBoard[pRow][i] < 4) {
			gameBoard[pRow][i]++;
		}
	}

	
	//This loop that iterates through the column the player is in
	for (int i = ((aCol == pCol) && (aRow < pRow)) ? aRow + 1 : 0; i < 6; i++) {
		if ((aCol == pCol) && (i == aRow)) {
			break;
		}
		else if (i != pRow && gameBoard[i][pCol] < 4) {
			gameBoard[i][pCol]++;
		}
	}


	//This loop that iterates through the left diagonal passing through the player
	for (int j = 0, i = ((pRow - aRow == pCol - aCol) && (aRow < pRow)) ? (pRow - aRow - 1) : (pCol <= pRow ? pCol : pRow); j < 6; j++, i--) 
	{
		if (pRow - i == aRow && pCol - i == aCol) {
			break;
		}
		else if (i != 0 && isValidIndex(pRow - i) && isValidIndex(pCol - i) && gameBoard[pRow - i][pCol - i] < 4) 
		{
			gameBoard[pRow - i][pCol - i]++;
		}
	}


	//This loop iterates through the right diagonal passing through the player
	for (int j = 0, i = ((pRow - aRow == aCol - pCol) && (aRow < pRow)) ? (pRow - aRow - 1) : (pCol + pRow <= 5 ? pRow : 5 - pCol); j < 6; j++, i--) 
	{
		if (pRow - i == aRow && pCol + i == aCol) {
			break;
		}
		else if (i != 0 && isValidIndex(pRow - i) && isValidIndex(pCol + i) && gameBoard[pRow - i][pCol + i] < 4) 
		{
			gameBoard[pRow - i][pCol + i]++;
		}
	}

}

/*
Given an 6x6 int array and the indicies of the player and the AI, buildingLevelDown() decreases
the value of all the elements in the row and column of the AI index by 1 if that element is not blocked by the Player.
It also decreases the value of all the elements by 1 if they are in the line y=-x and y = x with the AI index as origin
where y is the row index and x is the column index.
*/
void buildingLevelDown(int gameBoard[6][6], int aRow, int aCol, int pRow, int pCol) {
	
	//This loop that iterates through the row the player is in
	for (int i = ((pRow == aRow) && (pCol < aCol)) ? pCol + 1 : 0; i < 6; i++) {
		if ((pRow == aRow) && (i == pCol)) {
			break;
		}
		else if (i != aCol && gameBoard[aRow][i] > 0) {
			gameBoard[aRow][i]--;
		}
	}

	//This loop that iterates through the column the player is in
	for (int i = ((pCol == aCol) && (pRow < aRow)) ? pRow + 1 : 0; i < 6; i++) {
		if ((pCol == aCol) && (i == pRow)) {
			break;
		}
		else if (i != aRow && gameBoard[i][aCol] > 0) {
			gameBoard[i][aCol]--;
		}
	}


	//This loop that iterates through the left diagonal passing through the player
	for (int j = 0, i = ((aRow - pRow == aCol - pCol) && (pRow < aRow)) ? (aRow - pRow - 1) : (aCol <= aRow ? aCol : aRow); j < 6; j++, i--) 
	{
		if (aRow - i == pRow && aCol - i == pCol) {
			break;
		}
		else if (i != 0 && isValidIndex(aRow - i) && isValidIndex(aCol - i) && gameBoard[aRow - i][aCol - i] > 0) {
			gameBoard[aRow - i][aCol - i]--;
		}
	}

	//This loop iterates through the right diagonal passing through the player
	for (int j = 0, i = ((aRow - pRow == pCol - aCol) && (pRow < aRow)) ? (aRow - pRow - 1) : (aCol + aRow <= 5 ? aRow : 5 - aCol); j < 6; j++, i--) 
	{
		if (aRow - i == pRow && aCol + i == pCol) {
			break;
		}
		else if (i != 0 && isValidIndex(aRow - i) && isValidIndex(aCol + i) && gameBoard[aRow - i][aCol + i] > 0) {
			gameBoard[aRow - i][aCol + i]--;
		}
	}

}

/*
Given an 6x6 int array, getScore() return the number of 4 in array if who is'P' else it returns the number of 0 in the
array
*/
int getScore(int gameBoard[6][6], char who) {
	int score = 0;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (gameBoard[i][j] == (who == 'P' ? 4 : 0)) {
				score += 1;
			}
		}
	}
	return score;
}

/*
Given a 6x6 int array, index of the player and possible AI index, getPossibleScore() returns the AI score if the
AI moved into the given possible index without changing the given 6x6 int array.
*/
int getPossibleScore(int gameBoard[6][6], int aRow, int aCol, int pRow, int pCol) {
	int duplicate[6][6];
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			duplicate[i][j] = gameBoard[i][j];
		}
	}
	buildingLevelDown(duplicate, aRow, aCol, pRow, pCol);
	return getScore(duplicate, 'A');
}

/*
prints a stream of 81 Hyphen
*/
void printHyphen() {
	for (int i = 0; i < 81; i++) {
		printf("-");
	}
	printf("\n");
}

/*
prints a stream of 81 stars
*/
void printStar() {
	for (int i = 0; i < 81; i++) {
		printf("*");
	}
	printf("\n");
}

/*
prints the header to be displayed in the begining of the game
*/
void printGameBegins() {
	printf("\n");
	printStar();
	printf("\t\t\t\tGAME BEGINS\n");
	printStar();
}

int main() {
	int gameBoard[6][6] = { 2,2,2,2,2,2,
											 2,2,2,2,2,2,
											 2,2,2,2,2,2,
											 2,2,2,2,2,2,
											 2,2,2,2,2,2,
										   2,2,2,2,2,2 };
	int pRow = -1, pCol = -1, aRow = -1, aCol = -1, row = -1, col = -1;
	int aScore = 0, pScore = 0;
	int end = 0;
	char turn = 'P';

	//Gets the user input for the initial position of the player
	while (!isValidIndex(pRow) || !isValidIndex(pCol)) {
		printf("Enter the initial position in row and column ");
		scanf("%i %i", &pRow, &pCol);
		// accounts for the offset that array index starts from 0
		pRow--;
		pCol--;
	}

	// Initializes AI indices
	aRow = pRow;
	aCol = pCol >= 1 ? pCol - 1 : pCol + 1;

	displayGameBoard(gameBoard, aRow, aCol, pRow, pCol);
	printGameBegins();

	//Game Loop
	while (!end) {

		//Player's turn
		if (turn == 'P') {
			// Gets the user input for the next move
			while (!isValidIndex(row) || !isValidIndex(col) || !isAdjacentIndex(row, col, pRow, pCol) || (aRow == row && aCol == col)) 
			{
				printf("\nEnter your move in row and column ");
				scanf("%i %i", &row, &col);
				// accounts for the offset that array index starts from 0
				row--;
				col--;
			}
			pRow = row;
			pCol = col;

			//Updates the board after the player moved
			buildingLevelUp(gameBoard, aRow, aCol, pRow, pCol);
			printf("\nPlayer Moved");
		}
		//AI's turn
		else {
			int possibleRow = 0, possibleCol = 0, maxScore = -1;
			//Finds the next AI index that maximizes it's score by looping throught the possible moves it can make
			for (int i = -1; i <= 1; i++) {
				for (int j = -1; j <= 1; j++) {
					if (i != 0 && j != 0 && isValidIndex(aRow + i) && isValidIndex(aCol + j) && (aRow + i) != pRow && (aCol + j) != aCol) 
					{
						int temp = getPossibleScore(gameBoard, aRow + i, aCol + j, pRow, pCol);
						if (temp > maxScore) {
							maxScore = temp;
							possibleRow = aRow + i;
							possibleCol = aCol + j;
						}
					}
				}
			}
			aRow = possibleRow;
			aCol = possibleCol;

			//Updates the board after the AI moved
			buildingLevelDown(gameBoard, aRow, aCol, pRow, pCol);
			printf("\nAI Moved");
		}
	
		//Computes score
		aScore = getScore(gameBoard, 'A');
		pScore = getScore(gameBoard, 'P');

		//Displays Score
		printf("\t\t\t\t\t\t\t       AI Score %i\n", aScore);
		printf("\t\t\t\t\t\t\t\t   Player Score %i \n", pScore);
		
		displayGameBoard(gameBoard, aRow, aCol, pRow, pCol);
		
		//Displays the corresponding footer after each move
		printHyphen();
		if(aScore == pScore && pScore >=10)
		{
			printf("\t\t\t\tDRAW!\n");
			end =1;
		}else if (pScore>=10) {
			printf("\t\t\t\tPLAYER WON!\n");
			end = 1;
		}
		else if (aScore >= 10) {
			printf("\t\t\t\tAI WON!\n");
			end = 1;

		}
		else if (turn == 'P') {
			turn = 'A';
		}
		else {
			printf("\t\t\t\tNEXT TURN\n");
			printHyphen();
			turn = 'P';
		}

	}
	return 0;
}
