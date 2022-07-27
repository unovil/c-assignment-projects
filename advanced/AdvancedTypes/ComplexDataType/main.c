#include <stdio.h>    // input/output
#include <math.h>     // math functions
#include <complex.h>  // complex math functions
#define PI acos(-1)

// challenge 3: calculations on complex numbers

/*
create double complex with imaginary number squared using *
    display output real number and imaginary number
create double complex with imaginary number squared using m.pow
    display output real number and imaginary number
create double complex that performs Euler's formula
    PI = acos(-1)
    complex num is exponent of I * PI
    display output real number and imaginary number
create double complex number that performs product of conjugates
    complex number that is 1 + 2 * I
    complex number that is 1 - 2 * I
    display output real number and imaginary number
use complex.h, math.h, creal() and cimag()
*/

double complex to_conjugate(double complex number);

int main()
{
    double complex i_squared = I * I, i_squared_pow = pow(I, 2);
    printf("I * I    = %.0f%+.0fi\n", creal(i_squared), cimag(i_squared));
    printf("I^2      = %.0f%+.0fi\n\n", creal(i_squared_pow), cimag(i_squared_pow));

    double complex e_to_i_pi = exp(I * PI);
    printf("e^(i_pi) = %.0f%+.0fi\n\n", creal(e_to_i_pi), cimag(e_to_i_pi));

    double complex z1 = 1 + 2 * I, z2 = conj(z1);
    printf("1+2i * 1-2i = %.0f%+.0fi\n", creal(z1 * z2), cimag(z1 * z2));

    return 0;
}
