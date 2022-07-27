#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

const char str1[] = "Hello there!";
const char str2[] = " My name is Uno";
const int RESULT_LIMIT = 50;


/*
write function to count number of chars in string
    can't use strlen()
    param: char array
    return: int (length)
*/
int countChars(const char string[])
{
    unsigned int len = 0;

    // for every character in the string
    // if character is still not NULL, add 1 to len
    for (len = 0; string[len] != '\0'; ++len);

    // return length of string (without null char)
    return len;
}

/*
write function to concat two char strings
    can't use strcat()
    params:
        char result[] - concat.d string is here
        const char str1[]
        const char str2[]
    return: void
*/
void concatStrings (char result[], const char str1[], const char str2[])
{
    unsigned int result_pos = 0;

    memset(result, '\0', RESULT_LIMIT);
    // set all characters of result to null char
    // so we won't worry about overflows

    // for every char in str1, check if char is not null;
    // if not, every \0 in result (from the beginning) is
    // replaced with char from str1
    for (int pos = 0; str1[pos] != '\0'; ++pos, ++result_pos)
        result[result_pos] = str1[pos];

    // for every char in str2, check if char is not null;
    // if not, every \0 in result (this time beginning from the
    // last place str1 left off) is replaced with char from str2
    for (int pos = 0; str2[pos] != '\0'; ++pos, ++result_pos)
        result[result_pos] = str2[pos];

    // no need to set last char to null, since remaining places in result are \0
    // for example:
    // [START OF RESULT] h e l l o   t h e r e ! \0 \0 \0 \0 \0 ... \0 \0 [END OF RESULT]
}

/*
write function to check if two strings are equal
    can't use strlen() and strcmp()
    params:
        const char str1[]
        const char str2[]
    return: Boolean (true if equal, false if not)
*/
bool equalStrings(const char str1[], const char str2[])
{
    unsigned int strpos = 0;
    bool isequal = false;

    // while every char in str1 and str2 are equal,
    // and both str1 and str2 haven't reached \0 yet
    // increment strpos
    while (str1[strpos] == str2[strpos] && str1[strpos] != '\0' && str2[strpos] != '\0')
        ++strpos;

    /// if both strings are the same and have same length,
    //      then strpos should both locate to \0
    /// if both strings are not the same,
    //      then while loop should have stopped before
    //      reaching the end of any of the strings
    /// if both strings are the same but not in length,
    //      then one of the strings' strpos location
    //      should point to a non-null char
    if (str1[strpos] == '\0' && str2[strpos] == '\0')
        isequal = true;
    else
        isequal = false;

    return isequal;
}

int main()
{
    char result[RESULT_LIMIT];

    printf("%d \n", countChars(str1));
    printf("%d \n", countChars(str2));

    concatStrings(result, str1, str2);
    printf("%s \n", result);

    printf("%s \n", equalStrings(str1, str2) ? "true": "false");

    return 0;
}
