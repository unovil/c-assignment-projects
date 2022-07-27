#include <stdio.h>  // print_array
#include <stdlib.h> // malloc, rand, srand
#include <time.h>   // time() function

#include "intarr.h"

struct intArray
{
    int length;
    int bytesize;
    int array[];
};

/** \brief initializes an intArray structure.
 *
 * \param[in] length the length of the array to be initialized
 *
 * \return pointer to intArray
 */
struct intArray* init_intArray(int length)
{
    struct intArray *arr = malloc(sizeof(struct intArray) + sizeof(int) * length);

    arr->length = length;
    arr->bytesize = sizeof(struct intArray) + sizeof(int) * length;
    for (int i = 0; i < length; ++i) arr->array[i] = 0;

    return arr;
}

/** \brief assigns random values to array in intArray.
 * rand_intArray assigns random values to an intArray structure.
 * These random values range from 0 to the length of the array.
 *
 * \param[in] arr pointer to intArray (already initialized)

 * \return pointer to intArray
 *
 */
struct intArray* rand_intArray(struct intArray *arr)
{
    srand(time(0));

    for (int i = 0; i < arr->length; ++i)
        arr->array[i] = rand() % arr->length;

    return arr;
}

/** \brief prints an intArray to stdout
 * Displays the length, array, and the total structure size in bytes.
 * \param[in] arr pointer to intArray
 *
 * \return void
 *
 */

void print_intArray(struct intArray *arr)
{
    printf("Length: %d\n", arr->length);
    printf("Array:  {");
    for (int i = 0; i < arr->length - 1; ++i)
        printf("%d, ", arr->array[i]);
    printf("%d}\n", arr->array[arr->length - 1]);
    printf("Bytes:  %d\n", arr->bytesize);
}
