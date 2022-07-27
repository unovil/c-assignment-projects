#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    int allocation;

    printf("Enter number of elements: ");
    scanf("%d\n", &allocation);

    int elements[allocation];

    for (int i = 0; i < allocation; ++i)
        scanf("%d", &elements[i]);


    printf("These are the elements:\n");

    for (int i = 0; i < allocation; ++i)
        printf("%d", elements[i]);
}
