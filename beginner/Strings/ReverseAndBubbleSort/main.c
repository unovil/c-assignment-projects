#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <stdbool.h>

const int STR_LIMIT = 100;
const char IGNORE_CHAR = '\n';

/*
function to reverse a string
should read input from the keyboard
use strlen()
*/
void reverseString (char str[], char result[])
{
    /*
        since C is 0-indexed, having a length of 5 chars (like in 'hello')
        will be 0h 1e 2l 3l 4o
        so putting 5 as an index in result will point to \0 (coz 5 is actually 6th char in indexing), which is bad
        since for last iteration, the result will be
        0\0 1o 2l 3l 4e 5h

        so we put -1 to adjust.
        now, the last index will point to 4 (which is the 5th char)
        and now we get what we want
    */
    int strLength = strlen(str) - 1;

    for (int strpos = 0; str[strpos] != '\0'; ++strpos, --strLength)
        result[strLength] = str[strpos];
}

/*
function to sort strings with bubble sort
use strcmp() and strcpy()
    Input # of strings : 3
    Input Strings:
    zero
    one
    two

    Return:
    one
    two
    zero
*/
void sortStrings (int rowSize, char groupStr[][STR_LIMIT])
{
    // 1st var for storing the string temporarily as it moves through array
    // 2nd var for checking if the loop needs to continue because array is not ordered
    char tempStrHolder[STR_LIMIT];
    bool hastoturn;

    while (true)
    {
        hastoturn = false;

        // for every string in groupStr, check if that string and the string in
        // front is ordered (in 'ascending' order: a, b, c, d...)
        for (int count = 0; count < rowSize; ++count)
        {
            // if so, then hastoturn becomes true so it has to make another loop
            // after this
            if (strcmp(groupStr[count], groupStr[count + 1]) > 0)
            {
                hastoturn = true;

                // move string1 to another container
                // overwrite original position of said string with string2
                // overwrite position of string in front with string1 from container
                strcpy(tempStrHolder, groupStr[count]);
                strcpy(groupStr[count], groupStr[count + 1]);
                strcpy(groupStr[count + 1], tempStrHolder);
            }
        }

        // if the if block does not happen (meaning the array is perfectly ordered)
        // break the loop
        if (!hastoturn) break;
    }
}

void reverseInit ()
{
    /// REVERSE!
    printf("----- REVERSE -----\n");
    sleep(1);

    // setting vars
    char strReverse[STR_LIMIT];
    char resReverse[STR_LIMIT];

    // get strReverse
    printf("Enter text less than %d characters: ", STR_LIMIT);
    fgets(strReverse, STR_LIMIT, stdin);

    // removing the newline from fgets
    strReverse[strcspn(strReverse, "\n")] = 0;

    // function and printf
    reverseString(strReverse, resReverse);
    printf("Reversed String: \"%s\"\n", resReverse);

    sleep(1);
    printf("------- END -------\n\n");
}

void sortInit ()
{
    /// SORT!
    sleep(1);
    printf("------ SORT ------\n");
    sleep(1);

    // setting num and getting it from input
    int numStrings;

    printf("Enter number of strings you want to input: ");
    scanf("%d\n", &numStrings);
    /* why is there a newline after %d in scanf?
    it's becoz fgets is used after scanf. (just search it)
    since scanf %d won't read the newline after it, fgets will
    take the newline as a buffer. this causes strSort[] to jump from
    0th index to 1st index (0th -> \n) and causes major damage

    just add a \n after the format specifier to make scanf absorb \n
    and for fgets to not worry about a newline in the buffer

    https://www.geeksforgeeks.org/problem-with-scanf-when-there-is-fgetsgetsscanf-after-it/
    */

    // setting group of strings and getting those from input
    char strSort[numStrings][STR_LIMIT];

    for (int count = 0; count < numStrings; ++count)
    {
        fgets(strSort[count], STR_LIMIT, stdin);
        // remove newline from fgets
        strSort[count][strcspn(strSort[count], "\n")] = 0;
    }
    printf("\n");

    // function and printf
    sortStrings(numStrings, strSort);

    for (int count = 0; count < numStrings; ++count)
        printf("%s\n", strSort[count]);
}

int main()
{
    reverseInit();
    sortInit();

    return 0;
}
