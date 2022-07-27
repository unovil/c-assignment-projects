#include <stdio.h>  // input/output
#include <stdlib.h> // free
#include <unistd.h> // sleep

#include "intarr.h"

// challenge 2: flexible array member

int main()
{
    int length;
    struct intArray *myArray;

    puts("Random number generator");
    puts("-----------------------");
    sleep(1);
    puts("type in the number of elements");
    puts("-> will give out elements between 0 and that number");
    sleep(1);

    printf("Number of elements: ");
    scanf("%d", &length);

    myArray = init_intArray(length);
    myArray = rand_intArray(myArray);
    print_intArray(myArray);

    free(myArray);

    return 0;
}
