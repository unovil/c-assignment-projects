#include <stdio.h>

int main(void) {
    FILE *fp;
    int c;

    fp = fopen("TextFiles/test1.txt", "r");

    if (fp == NULL) {
        perror("\033[0;31mError\033[0m");
        return -1;
    }

    // reads every char (including all whitespaces)
    while ((c = fgetc(fp)) != EOF)
        printf("%c", c);
    // (c = fgetc(fp)):
    // assignment operator returns the
    // R-Value of an expression, so c becomes fgetc(fp)
    // AND it returns fgetc(fp) to check for EOF (-1)
    printf("\033[0;32mEnd of file reached!\033[0m\n");

    return 0;
}
