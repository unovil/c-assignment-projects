#include <stdio.h>  // input/output
#include <stdlib.h> // standard library
#include <ctype.h>

/*
little context:
islower() returns 0 if character is lowercase.
same with isupper()

so example:
chr     islower(chr)      if statement runs:
---------------------------------------------
'a'     0                 no  (0     = false)
'@'     0                 no  (0     = false)
'B'     not 0             yes (not 0 = true )
*/

// use fgetc, fputc, rename, remove, islower
void convert_case(char *filepath, char lucase) {
    if (lucase != 'l' && lucase != 'u') {
        printf("Invalid case. You have typed: '%c'\n", lucase);
        return;
    }

    FILE *fp = NULL, *tfp = NULL;
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

    while ((chr = fgetc(fp)) != EOF) {
        if (lucase == 'u') {
            if (islower(chr)) chr -= 32;
        }
        else if (lucase == 'l') {
            if (isupper(chr)) chr += 32;
        }

        fputc(chr, tfp);
        fputc(chr, stdout);
    }

    fclose(tfp); tfp = NULL;
    fclose(fp); fp = NULL;

    remove(filepath);
    rename("tfp.txt", filepath);
}

int main() {
    convert_case("ajsdlksa/lipsum.txt", 'l');
    return 0;
}
