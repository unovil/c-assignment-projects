#include <stdio.h>  // input/output

/// challenge 1: using variable-length arrays

/*
write program to read elements in array and find sum
Example:
    number of elements: 5
    input elements:
    10
    20
    30
    40
    50
    output:
    Sum of all elements = 150
use variable-length array
*/

typedef int Counter;

int getArraySum(int array[], int n_elements);

int main()
{
    int n_elements;

    printf("# of numbers: ");
    scanf("%d", &n_elements);
    int elements[n_elements];

    printf("Numbers:\n");
    for (Counter ct = 0; ct < n_elements; ++ct)
        scanf("%d", &elements[ct]);

    printf("List: {%d,", elements[0]);
    for (Counter ct = 1; ct < n_elements - 1; ++ct)
        printf(" %d,", elements[ct]);
    printf(" %d}\n", elements[n_elements - 1]);

    printf("Total: %d", getArraySum(elements, n_elements));

    return 0;
}

int getArraySum(int array[], int n_elements)
{
    int sum;

    for (Counter ct = 0; ct < n_elements; ++ct)
    {
        sum += array[ct];
    }

    return sum;
}
