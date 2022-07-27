#include <stdio.h>

void display(void);
extern int counter;

void display(void)
{
    printf("Display: %d\n", counter + 1);
}
