/**
 * @file main.c
 * @brief main file for this project
 *
 * @date 07/09/2021
 * @author Miguel
*/
#include <stdio.h>
#include <stdlib.h>

/**  sqrNum - gets the square of an integer.
 *   This function is a test that takes the
     address of an integer and squares it.
     It returns nothing since the integer
     itself will be changed.
 *  @param[in] *toSquare pointer to integer to be squared
 *  @return   void
 */
void sqrNum (int *toSquare);

/**
 * Main entry point of program.
*/
int main()
{
    int toSquare;

    printf("Number to square: ");
    scanf("%d", &toSquare);

    sqrNum(&toSquare);

    printf("Your number is  : %d", toSquare);

    return 0;
}

void sqrNum (int *toSquare)
{
    *toSquare = (*toSquare) * (*toSquare);
}
