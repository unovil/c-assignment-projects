#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
allows user to input number of bytes, then text string
use scanf, gets, or fgets
should create char pointer only, no character arrays
release memory allocated
*/
int main()
{
    char *pstring;
    int limit;

    printf("Enter the number of bytes: ");
    scanf("%d\n", &limit);

    pstring = malloc(limit);

    printf("Enter the string: ");
    fgets(pstring, limit, stdin);

    printf("Your string is %s", pstring);

    free(pstring);
    pstring = NULL;

    return 0;
}
