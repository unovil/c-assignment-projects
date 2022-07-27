#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

size_t BUFSIZE = 256;

void error(char *error_message);

int main(int argc, char **argv) {
    /* VERIFYING CLA */
    // check if there aren't 2 arguments passed
    if (argc != 3) {
        error("This program is designed to print the lines of a file");
        error("with the character included.\n");

        error("You need to have 2 arguments.");
        error("arg 1: character to read.");
        error("arg 2: filename.");
        exit(1);
    }

    if (strlen(argv[1]) != 1)  {
        error("Argument 1 needs to be a single character.");
        exit(EXIT_FAILURE);
    }
    else if (!((argv[1][0] >= 33) && (argv[1][0] <= 126))) {
        error("Argument 1 needs to be an ASCII character.");
        exit(EXIT_FAILURE);
    }

    FILE *fp;
    if (!(fp = fopen(argv[2], "r"))) {
        error("Argument 2 needs to be a valid file.");
        exit(EXIT_FAILURE);
    }

    char *buffer = NULL;
    if ((buffer = (char *)malloc(BUFSIZE * sizeof(char))) == NULL) {
        error("PROGRAM-SIDE ERROR: error allocating BUFSIZE bits into buffer.");
        printf("PROGRAM-SIDE ERROR: BUFSIZE amount: %zu\n", BUFSIZE);
        exit(EXIT_FAILURE);
    }


    int lineCount = 0;
    for (int c = getc(fp); c != EOF; c = getc(fp)) {
        if (c == '\n') lineCount += 1;
    }
    int numWidth = (int) round(1 + log(lineCount)/log(10));

    rewind(fp);

    int lineNum = 0;
    while (!(feof(fp))) {
        ++lineNum;
        getline(&buffer, &BUFSIZE, fp);
        if (strchr(buffer, argv[1][0]) != NULL) {
            printf("line%*d: %s", numWidth, lineNum, buffer);
        }
    }

    printf("\n\n------------------------------\n");
    printf("Done scanning, thank you!\n");
}

void error(char *error_message) {
    printf("ERROR: %s\n", error_message);
}
