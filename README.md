Implementation details of the Commandline Santoini Game in C 

Used an 6x6 2-D integer array(Gameboard) to store the whole board and initialized it with 2.

Used four variables to describe the indices of the Player and AI position(two for each).
With the indices of the player and AI, and 2-D array, displayed the value in the array except at
the player and AI position where 'P' and 'A' would be displayed respectively.

At the start of the game, the user is prompted to enter the initial position(in row column format) and reprompted until a valid position is entered.
There is a main game loop, the program comes out of this loop only when AI's or player's score is at least 10.

At the player's turn, user is prompted to enter the next move(in row column format) until the user enter a valid move.
The Gameboard is updated based on the rules of the game(more details at the end).

At the AI's turn, the AI loops through all the possible moves it can make and chooses the one that maximizes its score.
When AI's or player's of the scores is greater than 9 the game ends.


Demo of the project https://youtu.be/kNZ2S4b5-TI
A correction at the end of the video I said greater than 10 but I should have said greater than or equal to 10 sorry for the mistake.


Gameboard Updation:

To update the board the values along four lines need to be increased by 1 unless it's
blocked by a builder, in this case it's AI.

Assuming the player just moved into 3,2 

         0 1 2 3 4 5
      0  2 2 2 2 2 2
      1  2 2 A 2 2 2
      2  2 2 2 2 2 2
      3  2 2 P 2 2 2
      4  2 2 2 2 2 2
      5  2 2 2 2 2 2

Line 1 (the column the player is in):
        The loop starts from 0,2(the column the player is in) unless that column has the AI and is above the player in which case the loop starts from 2(AI row + 1),2 (the column the player is in).

        The loop ends either at the end of the column (5,2) or if an AI is encountered in between (this is the case where the AI is in the same column as the Player but the AI is below the player)


Assuming the player just moved into 3,3 

        0 1 2 3 4 5
     0  2 2 2 2 2 2
     1  2 2 2 2 2 2
     2  2 2 2 2 2 2
     3  2 A 2 P 2 2
     4  2 2 2 2 2 2
     5  2 2 2 2 2 2

Line 2 (the row the player is in):
        The loop starts from 3(the row the player is in),0 unless that row has the AI and is to the left of the player in which case the loop starts from 3(the row the player is in), 2(AI row +1).

        The loop ends either at the end of the row (3,5) or if an AI is encountered in between (this is the case where the AI is in the same row as the Player but the AI is to the right of the player)

Assuming the player just moved into 4,1

        0 1 2 3 4 5
     0  2 2 2 2 2 2
     1  2 2 2 2 2 2
     2  2 2 2 A 2 2
     3  2 2 2 2 2 2
     4  2 P 2 2 2 2
     5  2 2 2 2 2 2

Line 3 (the diagonal the player is in):
        The loop starts by going through the array from 3(AI row + 1),2(AI column -1) if that diagonal has the AI and is to the top right of the player else the loop starts from 0(if player Column + player Row <= 5 then 0 else player row -(5 - pCol)), 5(if player Column + player Row <= 5 then player column + player row else 0).

        The loop ends either at the end of the row (5,0) or if an AI is encountered in between (this is the case where the AI is in the diagonal but the AI is to the right of the player)

Assuming the player just moved into 4,3

        0 1 2 3 4 5
     0  2 2 2 2 2 2
     1  2 2 2 2 2 2
     2  2 A 2 2 2 2
     3  2 2 2 2 2 2
     4  2 2 2 P 2 2
     5  2 2 2 2 2 2

Line 4 (the other diagonal the player is in):
       The loop starts by going through the array from 3(AI row +1),2(AI column +1) if that diagonal has the AI and is to the top left of the player else the loop starts from 1(player row - the min(player row, player column)),0 (player row - the min(player row, player column))

       The loop ends either at the end of the row (5,4) or if an AI is encountered in between (this is the case where the AI is in the diagonal but the AI is bottom right the player)
