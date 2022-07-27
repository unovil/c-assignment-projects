#include <stdio.h>
#include <stdlib.h>

// write function to calculate length of string
// function takes param as const char pointer
// function determines length using pointer arithmetic
// use while loop
// subtract two ptrs (end and start) and return int
int strlenPointer (const char *string)
{
    const char *startpointer, *endpointer;
    startpointer = string;
    endpointer = string;

    while (*endpointer != '\0')
        ++endpointer;


    return (int) (endpointer - startpointer);
}

int main()
{
    const char testStr[20] = "Hello there!";

    printf("TestStr's length is %d", strlenPointer(testStr));
    printf("Waterloo's length is %d", strlenPointer("Waterloo"));

    return 0;
}
