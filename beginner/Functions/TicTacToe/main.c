#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

// struct for markBoard
struct result {
    char Rmoves[10];
    bool Rerror;
    bool RplayerTurn;
} result;

// use system("clear") for clearing screen (as such)
struct result markBoard (int choice, char moves[], bool error, bool playerTurn);
void drawBoard (char moves[]);
void checkForWin ();

int main()
{
    /* variables */
    // names of the players are stored here
    char playerOne[41] = "";
    char playerTwo[41] = "";

    // moves are stored here
    char moves[10] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '\0'};

    // player's turn and their choice
    bool playerTurn = true; // if true, playerOne. if false, playerTwo.
    int choice = 0;
    // checks for error in their choice (possibly overlapped with another choice)
    bool error = false;

    printf("       Tic Tac Toe       \n\n");

    sleep(1);

    printf("Players can choose from 1-41 letters.\n");

    sleep(1);
    printf("Player 1, choose a name: ");
    scanf("%s", playerOne);
    printf("Aight, %s!\n", playerOne);

    sleep(1);
    printf("\nPlayer 2, choose a name: ");
    scanf("%s", playerTwo);
    printf("OK, %s!\n\n", playerTwo);

    sleep(1);
    system("clear");

    printf("Players will choose between 1 and 9. Start!\n\n");
    drawBoard(moves);
    while (true) // true is placeholder, will be replaced by checkForWin()
    {
        printf("%s, pick a number: ", (playerTurn) ?  playerOne : playerTwo);
        scanf("%d", &choice);

        struct result marked = markBoard(choice, moves, error, playerTurn);
        strcpy(moves, marked.Rmoves);
        error = marked.Rerror;
        playerTurn = marked.RplayerTurn;

        system("clear");
        printf("       Tic Tac Toe       \n\n");
        drawBoard(moves);
        // checkForWin();
    }

    return 0;
}

struct result markBoard (int choice, char moves[], bool error, bool playerTurn)
{
    static bool letter = true;

    struct result r1;
    strcpy(moves, r1.Rmoves);
    r1.Rerror = error;
    r1.RplayerTurn = playerTurn;

    if ( choice > 0 && choice < 10 )
    {
        if (moves[choice - 1] != 'X' && moves[choice - 1] != 'O')
        {
            r1.Rmoves[choice - 1] = (letter) ? 'X' : 'O'; // moves[choice] becomes X or O depending on who is playing
            letter = (playerTurn) ? false : true; // switches between X and O
        }
        else
        {
            printf("Invalid move! Try again.\n");
            r1.Rerror = true;
        }
    }
    else
    {
        printf("Invalid move! Try again.\n");
        r1.Rerror = true;
    }

    r1.RplayerTurn = (r1.Rerror) ? playerTurn : !(playerTurn);

    return r1;
}

void drawBoard (char moves[])
{
    printf("-------------------------\n");
    printf("|       |       |       |\n");
    printf("|   %c   |   %c   |   %c   |\n", moves[0], moves[1], moves[2] );
    printf("|       |       |       |\n");
    printf("-------------------------\n");
    printf("|       |       |       |\n");
    printf("|   %c   |   %c   |   %c   |\n", moves[3], moves[4], moves[5] );
    printf("|       |       |       |\n");
    printf("-------------------------\n");
    printf("|       |       |       |\n");
    printf("|   %c   |   %c   |   %c   |\n", moves[6], moves[7], moves[8] );
    printf("|       |       |       |\n");
    printf("-------------------------\n");
    return;
}
void checkForWin ();
