/* Program 6.8 Testing characters in a string */
#include <stdio.h>
#include <ctype.h>
int main(void) {

    char buff[20];

    gets(buff);

    for (int i = 0; ; ++i)
        if ( ( buff[i] = (char) toupper(buff[i]) ) == '\0')
            break;

    printf("%s", buff);
    return 0;
}
