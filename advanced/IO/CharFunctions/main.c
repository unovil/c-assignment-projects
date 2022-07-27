#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char **argv) {
    FILE *fp = NULL;
    int ch;

    // checks if CLA are passed
    if (argc == 1) {
        printf("Type a flag, please!\n");
        printf("Type --help for more documentation and details.\n");

        return 1;
    }

    // flag checking
    if (strcmp(argv[1], "--help") == 0) {
        if ((fp = fopen("flagDocumentation/program_help.txt", "r"))) {
            while (ch = fgetc(fp), ch != EOF) {
                fputchar(ch);
            }
            fclose(fp);
            exit(EXIT_SUCCESS);
        }
        else {
            perror("program help not found :(");
            exit(EXIT_FAILURE);
        }
    }
    else if (strcmp(argv[1], "--count") == 0) {
        int wordcount = 0, ch_count = 0;

        switch (argc) {
            case 2: // stdin
                printf("All characters and words are now counted from stdin.\n");
                while (ch = getchar(), ch != EOF) {
                    ++ch_count;
                    if (ch == '\n' || ch == ' ') {
                        ++wordcount;
                    }
                }
                printf("Character count is: %d\n", ch_count);
                printf("Word count is: %d\n", wordcount);
                break;
            case 3: // file
                if ((fp = fopen(argv[2], "r"))) {
                    printf("File:\n'");
                    while (ch = getc(fp), ch != EOF) {
                        putchar(ch);
                        ++ch_count;
                        if (ch == '\n' || ch == ' ') {
                            ++wordcount;
                        }
                    }

                    printf("'\n");
                    printf("Character count is: %d\n", ch_count);
                    printf("Word count is: %d\n", wordcount + 1);
                    fclose(fp);
                }
                else {
                    perror("File not found.\n");
                    exit(EXIT_FAILURE);
                }
                break;
            default: // error
                printf("Too many arguments. Use only:\n");
                printf("--count <file> to count the file contents\n");
                printf("--count to count from stdin\n");
                exit(EXIT_FAILURE);
        }

    }
    else if (strcmp(argv[1], "--convert_case") == 0) {
        FILE *fp_temp;
        bool modeIsUpper = strcmp(argv[3], "upper") == 0;
        bool modeIsLower = strcmp(argv[3], "lower") == 0;
        bool modeIsFlip  = strcmp(argv[3], "flip") == 0;

        // isupper or islower returns nonzero if ch is not upper or not lower

        if (!modeIsUpper && !modeIsLower && !modeIsFlip) {
            perror("Not a valid mode! Use 'upper', 'lower', or keep it blank.");
            exit(EXIT_FAILURE);
        }
        if ((fp = fopen(argv[2], "r")) && (fp_temp = fopen("temp.txt", "a"))) {
            printf("File contents:\n");
            printf("\n--(START FILE)--\n");
            if (modeIsUpper) {
                while (ch = getc(fp), ch != EOF) {
                    putchar(ch);
                    putc((isupper(ch) != 0) ? ch : toupper(ch), fp_temp);
                }
            }
            else if (modeIsLower) {
                while (ch = getc(fp), ch != EOF) {
                    putchar(ch);
                    putc((islower(ch) != 0) ? ch : tolower(ch), fp_temp);
                }
            }
            else if (modeIsFlip) {
                while (ch = getc(fp), ch != EOF) {
                    putchar(ch);
                    if (islower(ch) != 0) putc(toupper(ch), fp_temp);
                    else if (isupper(ch) != 0) putc(tolower(ch), fp_temp);
                    else putc(ch, fp_temp);
                }
            }
            printf("\n---(END FILE)--\n");

            fclose(fp); fp = NULL;
            fclose(fp_temp); fp = NULL;
            remove(argv[2]);
            rename("temp.txt", argv[2]);

            if ((fp = fopen(argv[2], "r"))) {
                printf("\nConverted contents:\n");
                printf("\n--(START FILE)--\n");
                while (ch = getc(fp), ch != EOF) {
                    putchar(ch);
                }
                printf("\n---(END FILE)--\n");
            }
        }
        else {
            perror("File not found.");
            exit(EXIT_FAILURE);
        }
    }
    else {
        printf("Flag not found. Type the flag '--help' to read documentation.\n");
        return 1;
    }

    printf("\nThank you!\n");

    return 0;
}