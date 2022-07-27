#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

typedef struct WinOrDraw
{
    bool win;
    bool draw;
} WorD;

bool markBoard (int choice, char moves[], char player)
{
    // the choice has to be between 1 and 9
    if (choice > 0 && choice < 10)
    {
        // choice has to be unoccupied
        char moveString[2] = {moves[choice-1], '\0'};
        if ( atoi(moveString) != 0 )
        {
            moves[choice-1] = player;
            return false;
        }
        else
        {
            printf("Invalid move, try again!\n");
            sleep(1);
            return true;
        }
    }
    else
    {
        printf("Invalid move, try again!\n");
        sleep(1);
        return true;
    }
}

void drawBoard (char moves[])
{
    printf("       Tic Tac Toe       \n");
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
    printf("-------------------------\n\n");
    return;
}

WorD checkForWin(char moves[], char player)
{
    bool w = false;
    bool d = false;

    // first invocation
    static bool start = false;
    if (!start)
    {
        start = true;
        w = false;
    }

    // check for horizontals
    for (int n = 0; n < 9; n += 3)
    {
        if ( moves[n] == moves[n+1] && moves[n] == moves[n+2] )
            w = true;
    }

    // check for verticals
    for (int n = 0; n < 3; ++n)
    {
        if ( moves[n] == moves[n+3] && moves[n] == moves[n+6] )
            w = true;
    }

    // check for diagonals
    if (true)
    {
        if ( moves[0] == moves[4] && moves[4] == moves[8] )
            w = true;
        else if ( moves[2] == moves[4] && moves[4] == moves[6] )
            w = true;
    }

    // check for draw
    int numberOf_X_and_O = 0;
    for (int n = 0; n < 9; ++n)
    {
        if (moves[n] == 'X' || moves[n] == 'O')
            ++numberOf_X_and_O;
    }
    if (numberOf_X_and_O == 9)
        d = true;

    WorD win_or_draw;
    win_or_draw.win = w;
    win_or_draw.draw = d;

    return win_or_draw;
}

char switchPlayers(char player)
{
    char playerNew = player;
    playerNew = (player == 'X') ? 'O' : 'X';

    return playerNew;
}

int main()
{
    char moves[10] = "123456789";
    int choice;
    char player = 'X';
    bool error;
    WorD result_checkForWin;

    while (!result_checkForWin.win)
    {
        drawBoard(moves);
        printf("%c, pick a number: ", player);
        scanf("%d", &choice);

        error = markBoard(choice, moves, player);
        if (!error)
        {
            result_checkForWin = checkForWin(moves, player);
            if (result_checkForWin.win)
            {
                system("clear");
                drawBoard(moves);
                printf("%c wins!", player);
                break;
            }
            else if (result_checkForWin.draw)
            {
                system("clear");
                drawBoard(moves);
                printf("Nobody wins!");
                break;
            }

            player = switchPlayers(player);
        }
        system("clear");
    }
    return 0;
}
