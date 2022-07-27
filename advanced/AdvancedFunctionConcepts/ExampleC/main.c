#include <stdio.h>
#include <stdarg.h>
#include <math.h>

double standard_deviation(int argCount, ...);

int main() {
    double numList[] = {0, 0, 0, 0, 0};

    printf("Enter 5 numbers: ");
    scanf("%lf %lf %lf %lf %lf", &numList[0], &numList[1], &numList[2], &numList[3], &numList[4]);

    printf("The standard deviation of these numbers:\n");
    printf("(%lf, %lf, %lf, %lf, %lf)\n", numList[0], numList[1], numList[2], numList[3], numList[4]);
    printf("is %.5lf\n", standard_deviation(5, numList[0], numList[1], numList[2], numList[3], numList[4]));
    return 0;

}

double standard_deviation(int argCount, ...) {
    va_list argList_mean, argList_variance;
    va_start(argList_mean, argCount);
    va_copy(argList_variance, argList_mean);

    // finding the mean
    double mean = 0.0;
    for (int i = 0; i < argCount; ++i) {
        mean += va_arg(argList_mean, double);
    }
    mean /= argCount;
    va_end(argList_mean);

    double sum_squared_variance = 0.0;
    double variance;
    for (int i = 0; i < argCount; ++i) {
        variance = va_arg(argList_variance, double);
        sum_squared_variance += (variance - mean) * (variance - mean);
    }
    va_end(argList_variance);

    return (sqrt(sum_squared_variance / (argCount - 1)));
}