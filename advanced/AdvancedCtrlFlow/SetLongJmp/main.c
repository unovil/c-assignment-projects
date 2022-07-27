#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

jmp_buf buf;

float average(const float *numList, int length);
void error_recovery(char *error);

int main(int argc, char **argv) {
    int lenArgs = argc - 1;
    printf("You have entered %d arguments.\n", lenArgs);

    if (!setjmp(buf)) {
        float numbers[lenArgs];

        // call longjmp if there are no arguments passed
        if (lenArgs == 0) error_recovery("0 arguments entered.");

        // printing arguments and writing them to numbers list
        printf("Arguments: ");
        for (int i = 1; i < lenArgs; ++i) {
            printf("%s, ", argv[i]);
            numbers[i-1] = strtof(argv[i], NULL);
        }
        printf("%s\n", argv[argc - 1]);
        numbers[lenArgs-1] = strtof(argv[lenArgs], NULL);

        // printing average
        printf("Average is: %.7f\n", average(numbers, argc));
    }
    else {
        // longjmp called already
        exit(1);
    }

    return 0;
}

float average(const float *numList, int length) {
    float avg = 0.0;

    for (int i = 0; i < length - 1; ++i) {
        avg += numList[i];
    }
    avg /= length - 1;

    return avg;
}

void error_recovery(char *error) {
    printf("Error: %s\n", error);
    longjmp(buf, 1);
}