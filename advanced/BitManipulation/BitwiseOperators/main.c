#include <stdio.h>  // input/output
#include <stdlib.h> // standard library
#include "headers/dbc.h"    // decimal-binary conversion

/// challenge 2: bitwise operators

/*
program to read two ints from user
    apply ~ to each number
    apply & | ^ operators of pair
    apply << and >> operators to a specific number
    show results in binary strings
*/

int main()
{
	// buffer disabling for Eclipse
	setbuf(stdout, NULL);

    int num1, num2;
    num1 = num2 = 0;

    printf("Enter number 1: ");
    scanf("%d", &num1);
    printf("Enter number 2: ");
    scanf("%d", &num2);

    printf("num2 << 2 is %lld\n", convDecBin(num2));

    printf("\nThe complement (~) of num1 is %lld\n", convDecBin(~num1));
    printf("The complement (~) of num2 is %lld\n", convDecBin(~num2));

    printf("\nThe result from num1 AND (&) num2 is %lld\n", convDecBin(num1 & num2));
    printf("The result from num1 OR (|) num2 is %lld\n", convDecBin(num1 | num2));
    printf("The result from num1 XOR (^) num2 is %lld\n", convDecBin(num1 ^ num2));

    printf("\nnum1 right-shifted two bits is %lld\n", convDecBin(num1 >> 2));
    printf("num2 right-shifted two bits is %lld\n", convDecBin(num2 >> 2));

    printf("\nnum1 left-shifted two bits is %lld\n", convDecBin(num1 << 2));
    printf("num2 left-shifted two bits is %lld\n", convDecBin(num2 << 2));

    return 0;
}
