#include <stdio.h>  // input/output
#include <stdlib.h> // standard library
#include <string.h> // string functions
#include <stdbool.h>

/**
 * @brief reverses contents of a file
 * @param[in] filepath[] string of location of file (either relative or absolute)
 * @param[in] replace    char to delete or make a copy of the file ('r' to replace, 'n' to make copy)
 * @return true if successful, false if not
**/
bool reverseFile(char filepath[], char replace) {
    if (replace != 'r' && replace != 'n') {
        printf("Invalid replace char, you typed %c", replace);
        return false;
    }
    FILE *fp, *tfp;
    int chr;

    if ((fp = fopen(filepath, "r")) == NULL) {
        printf("fp\n");
        perror("\033[0;31mError"); // in case error happens
        exit (EXIT_FAILURE);
    }
    if ((tfp = fopen("tfp.txt", "w")) == NULL) {
        printf("tfp\n");
        perror("\033[0;31mError\033[0m"); // in case error happens
        exit (EXIT_FAILURE);
    }

    // this gets the length of file 1
    fseek(fp, 0, SEEK_END);
    long fp_len = ftell(fp);

    // rewind 1 character from end of file
    fseek(fp, -1, SEEK_END);

    while (ftell(tfp) < fp_len) {
        // getting character from fp moves fp 1 char to the right
        chr = fgetc(fp);

        // putting character to tfp moves tfp 1 char to the right
        fputc(chr, tfp);

        // rewind 2 characters to fp so that next fgetc would
        // only move fp 1 to the right ( <2  +   1> = <1 )
        //                            fseek    fgetc  fp position moves
        fseek(fp, -2, SEEK_CUR);
    }

    fclose(tfp); tfp = NULL;
    fclose(fp); fp = NULL;

    if (replace == 'r') {
        remove(filepath);
        rename("tfp.txt", filepath);
    }
    else if (replace == 'n') {
        rename("tfp.txt", "output.txt");
    }

    return true;
}

int main()
{
    reverseFile("TextFiles/lipsum.txt", 'n');

    return 0;
}
