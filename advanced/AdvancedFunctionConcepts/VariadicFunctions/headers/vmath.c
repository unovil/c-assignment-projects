//
// Created by Uno on 07/29/2022.
//

#include "vmath.h"

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

float i_vmean(int num1, ...) {
    va_list addends;
    int sum = num1, currentnum;
    unsigned int addendCount = 1;

    va_start(addends, num1);
    while ((currentnum = va_arg(addends, int)) != INT_MIN) {
        sum += currentnum;
        addendCount += 1;
    }
    va_end(addends);

    return (float)sum / (float)addendCount;
}
double d_vmean(double num1, ...) {
    va_list addends;
    double sum = num1, currentnum;
    unsigned int addendCount = 1;

    va_start(addends, num1);
    while ((currentnum = va_arg(addends, double)) != -DBL_MAX) {
        sum += currentnum;
        addendCount += 1;
    }
    va_end(addends);

    return (float)sum / (float)addendCount;
}

int i_vext(enum EXTREMES ext, int num1, ...) {
    va_list numbers;
    int currentnum;
    int retval = num1;

    va_start(numbers, num1);
    if (ext == E_MIN) {
        while ((currentnum = va_arg(numbers, int)) != INT_MIN) {
            retval = ((currentnum < retval) ? currentnum : retval);
        }
    }
    else if (ext == E_MAX) {
        while ((currentnum = va_arg(numbers, int)) != INT_MIN) {
            retval = ((currentnum > retval) ? currentnum : retval);
        }
    }
    else {
        retval = INT_MAX;
    }

    va_end(numbers);

    return retval;
}
double d_vext(enum EXTREMES ext, double num1, ...) {
    va_list numbers;
    double currentnum;
    double retval = num1;

    va_start(numbers, num1);
    if (ext == E_MIN) {
        while ((currentnum = va_arg(numbers, double)) != -DBL_MAX) {
            retval = ((currentnum < retval) ? currentnum : retval);
        }
    }
    else if (ext == E_MAX) {
        while ((currentnum = va_arg(numbers, double)) != -DBL_MAX) {
            retval = ((currentnum > retval) ? currentnum : retval);
        }
    }
    else {
        retval = -DBL_MAX;
    }

    va_end(numbers);

    return retval;
}