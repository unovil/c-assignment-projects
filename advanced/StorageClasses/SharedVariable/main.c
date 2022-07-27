#include <stdio.h>  // input/output
#include <stdlib.h> // standard library

/// challenge 3: shared variable on 2 files
/*
create program that shares variable to 2 files

main.c
    includes global variable as loop counter
    file includes main
        uses global to iterate 5 times
            display(void) is invoked (do not use include file

display.c
    display() is defined here
        displays global variable (increment 1) from main.c
*/

int counter;

int main()
{
    for (counter = 0; counter <= 5; counter++) display();

    return 0;
}
