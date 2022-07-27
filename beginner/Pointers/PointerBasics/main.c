#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/*
write program that creates int var hard-coded
assign that variable's address to ptr

display output:
address of pointer
value of pointer
value of what pointer is pointing to
*/
int main()
{
    int number = 20;
    int *pnumber = NULL;

    pnumber = &number;

    printf("pnumber's address is: %p\n", (void*) &pnumber);
    printf("pnumber's value is:   %p\n", pnumber);
    printf("pnumber points to:    %d\n", *pnumber);


    return 0;
}
