#include <stdio.h>   // input/output
#include <stdbool.h> // binary
#include <limits.h>  // LLONG_MAX
#include <math.h>    // log10 ()

/// challenges 1 and 2: conversion

/*
make a function that converts decimal to binary
make a function converts binary to decimal
    both functions have long long parameter
*/

typedef long long int lli;
int convBinDec (lli bin);
lli convDecBin (int dec);

short int binDigitCount = 0;
short int decDigitCount = 0;

typedef union BinDec {
    lli binary;
    int decimal;
} BinDec;

int main() {
	// disable buffering
	setbuf(stdout, NULL);

    BinDec input;

    binDigitCount = log10(LLONG_MAX) + 1;
    decDigitCount = log10(convBinDec(LLONG_MAX)) + 1;

    bool bd = false;

    printf("Please select a choice based on numbering:\n");
    printf("1. Binary => Decimal\n");
    printf("2. Decimal => Binary\n");
    printf("Your choice: ");

    switch (getc(stdin)) {
        case '1':
            printf("\nYou selected: Binary => Decimal.\n");
            bd = true;
            break;
        case '2':
            printf("\nYou selected: Decimal => Binary.\n");
            bd = false;
            break;
        default:
            printf("\nYou have entered the wrong message.\n");
            return 0;
            break;
    }

    printf("You are only allowed %hd digits.\n", bd ? binDigitCount : decDigitCount);
    printf("\nYour number is: ");
    if ((bd ? binDigitCount : decDigitCount) != 6) {
        scanf("%lld", &(input.binary));
        printf("\nOutput: %d\n", convBinDec(input.binary));
    }
    else {
        scanf("%d", &(input.decimal));
        printf("\nOutput: %lld\n", convDecBin(input.decimal));
    }
}

int convBinDec (lli bin) {
    int dec = 0;

    for (lli pow10 = 10, pow2 = 1, digit_value = 0; bin / (pow10 / 10) >= 1; pow10 *= 10, pow2 *= 2) {
        digit_value = bin % pow10;
        dec += (bool) digit_value * pow2;

        bin -= digit_value;
    }

    return dec;
}

lli convDecBin (int dec) {
    long long int bin = 0;

    for (int pow10 = 1; ; pow10 *= 10) {
        bin += (dec % 2) * pow10;
        if ((dec /= 2) == 0) break;
    }

    return bin;
}
