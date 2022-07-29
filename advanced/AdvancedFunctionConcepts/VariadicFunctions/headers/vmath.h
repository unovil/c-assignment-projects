//
// Created by Uno on 07/29/2022.
//

#ifndef SUMVARIADICFUNCTION_VMATH_H
#define SUMVARIADICFUNCTION_VMATH_H

#include <stdarg.h>
#include <stdio.h>
#include <limits.h>
#include <float.h>

enum EXTREMES {E_MIN = 1, E_MAX = 2};

// sum functions
int i_vsum(int num1, ...);
double d_vsum(double num1, ...);

// average functions
float i_vmean(int num1, ...);
double d_vmean(double num1, ...);

// minmax functions
int i_vext(enum EXTREMES ext, int num1, ...);
double d_vext(enum EXTREMES ext, double num1, ...);

#endif //SUMVARIADICFUNCTION_VMATH_H
