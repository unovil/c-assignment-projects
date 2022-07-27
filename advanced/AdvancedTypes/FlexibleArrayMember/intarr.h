#ifndef INTARR_H_INCLUDED
#define INTARR_H_INCLUDED

struct intArray;

struct intArray* init_intArray(int length);

struct intArray* rand_intArray(struct intArray *arr);

void print_intArray(struct intArray *arr);

#endif // INTARR_H_INCLUDED
