#include <stdio.h>  // input/output
#include <stdlib.h> // standard library
#include <string.h> // string functions

// write program to find total number of lines in text file
// use fgetc function to parse characters until you get to EOF
int countLines (char textFile[], char mode[])
{
    FILE *fp;
    int chr;

    if ((fp = fopen(textFile, mode)) == NULL)
    {
        perror("\033[0;31mError"); // in case error happens
        exit(EXIT_FAILURE);
    }

    int lines;

    while ((chr = fgetc(fp)) != EOF)
    {
        printf("%c", (char) chr);
        if ((char) chr == '\n') ++lines;
    }


    fclose(fp); fp = NULL;

    return lines;
}

// stdout: total number of lines in file


int main()
{
    printf("\n\033[0;32mThe total number of lines in lipsum is: %d\033[0m\n", countLines("TextFiles/lipsum.txt", "r"));

    return 0;
}
