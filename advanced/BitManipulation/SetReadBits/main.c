/*  --------------------------------
    C program to input any number and 'n' bit from user
        checks whether nth bit of the number is 1 or 0
        set nth bit of number as 1
    -------------------------------- */

#include <stdio.h>
#include <stdbool.h>
int main(int argc, char const *argv[])
{
    unsigned int number, newNumber;
    int bitpos;

    // getting input
    while (true) {
        printf("Enter any number between 0 and 4,294,967,295: ");
        scanf("%u", &number);
        if (!(number >= 0 && number <= 0xFFFFFFFF)) {
            printf("\033[0;31mNumber not within bounds! Do it again bitch.\033[0m\n");
            continue;
        }
        break;
    }
    
    while (true) {
        printf("Enter nth bit to check and set between 0 and 31: ");
        scanf("%d", &bitpos);
        if (!(bitpos >= 0 && bitpos <= 31)) {
            printf("\033[0;31mBit position within bounds! Do it again bitch.\033[0m\n");
            continue;
        }
        break;
    }

    int bit = (number >> bitpos) & 1;
    printf("\nThe %d bit is set to %d\n", bitpos, bit);
    if (!bit) {
        newNumber = number ^ (1 << bitpos);
        printf("\033[0;32mBit set successfully.\033[0m\n");
    }
    else {
        newNumber = number;
        printf("\033[0;32mBit is already set to 1!\033[0m\n");
    }

    printf("\nNumber before setting %d bit: %u (in decimal)\n", bit, number);
    printf("Number after setting %d bit: %u (in decimal)\n", bit, newNumber);    

    return 0;
}
