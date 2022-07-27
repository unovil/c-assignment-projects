#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include <float.h>

int i_vsum(int num1, ...);
double d_vsum(double num1, ...);

int main() {
    printf("The sum of 152, 38, 52, and 85 is %d\n", i_vsum(152,38,52,85, INT_MIN));
    printf("The sum of 200.5, 70.2228, 10.229, and 100.0 is %.7lf", d_vsum(200.5, 70.2228, 10.229, 100.0, -DBL_MAX));
    return 0;
}

int i_vsum(int num1, ...) {
    va_list addends;
    int sum = num1;
    int currentnum;

    va_start(addends, num1);
    while ((currentnum = va_arg(addends, int)) != INT_MIN) {
        sum += currentnum;
    }
    va_end(addends);

    return sum;
}

double d_vsum(double num1, ...) {
    va_list addends;
    double sum = num1;
    double currentnum;

    va_start(addends, num1);
    while ((currentnum = va_arg(addends, double)) != -DBL_MAX) {
        sum += currentnum;
    }
    va_end(addends);

    return sum;
}