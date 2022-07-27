#include <stdio.h>  // input/output
#include <stdlib.h> // standard library

/// challenge 2: sum without a total
/*
create program that finds sum of some numbers
can't pass any variable representing running total to sum func
*/


int sum (int num)
{
    static int total;

    total += num;

    return total;
}

int main()
{
    printf("%d ", sum(25));
    printf("%d ", sum(15));
    printf("%d ", sum(30));

    return 0;
}
