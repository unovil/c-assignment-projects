#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>

#include "headers/essentials.h"

size_t BUFSIZE;

bool IsEven(int n);
bool IsPrime(int n);

// using fgets + sscanf
/*int main(int argc, char **argv) {
    FILE *fp;
    if ((fp = fopen(argv[1], "r")) == NULL) {
        error("Failed to open file.");
        exit(EXIT_FAILURE);
    }

    char buf[BUFSIZE];
    int numList[NUMLISTSIZE];

    while (!feof(fp)) {
        fgets(buf, BUFSIZE, fp);
        sscanf(buf, "%d %d %d", &numList[0], &numList[1], &numList[2]);

        for (int i = 0; i < NUMLISTSIZE; ++i) {
            if (numList[i] == INT_MAX || numList[i] == INT_MIN) {
                printf("Too little/large number! Input: %d\n", numList[i]);
            }
            else if ((numList[i] > 0) && (IsPrime(numList[i]) == true)) {
                printf("Prime number found: %d\n", numList[i]);
            }
            else if (IsEven(numList[i])) {
                printf("Even number found: %d\n", numList[i]);
            }
            else {
                printf("Odd number found: %d\n", numList[i]);
            }
        }
    }

    fclose(fp);
    printf("\n\033[0;32mFinished operations!\033[0m\n");

    return 0;
}*/

// using fgets + strtok + strtol (safer)
int main(int argc, char **argv) {
    if (argc != 2) {
        error("File argument needed only.");
        exit(EXIT_FAILURE);
    }

    char *buf = NULL;

    FILE *fp = NULL;
    if ((fp = fopen(argv[1], "r")) == NULL) {
        error("Failed to open file.");
        exit(EXIT_FAILURE);
    }

    char *token = NULL, *endptr = NULL;
    long int number;
    while (!feof(fp)) {
        getline(&buf, &BUFSIZE, fp);

        token = strtok(buf, " ");
        while (token != NULL) {
            number = strtol(token, &endptr, 10);
            if (*endptr != '\0' && *endptr != '\n') {
                printf("\033[0;31mERROR: input invalid. must be integer. string: \"%s\"\033[0m\n", token);
                token = strtok(NULL, " ");
                continue;
            }
            else if (number == LONG_MAX || number == LONG_MIN) {
                printf("\033[0;31mERROR: input out of long bounds. string: %s\033[0m\n", token);
                token = strtok(NULL, " ");
                continue;
            }

            if ((number > 0) && (IsPrime(number) == true)) {
                printf("Prime number found: %ld\n", number);
            }
            else if (IsEven(number)) {
                printf("Even number found: %ld\n", number);
            }
            else {
                printf("Odd number found: %ld\n", number);
            }

            token = strtok(NULL, " ");
        }
    }

    fclose(fp);
    free(buf);

    printf("\n\033[0;32mFinished operations!\033[0m\n");

    return 0;
}

bool IsEven(const int n) {
    return (n % 2 == 0);
}

bool IsPrime (const int n) {
    if (n == 2 || n == 3)
        return true;

    if (n <= 1 || n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }

    return true;
}
