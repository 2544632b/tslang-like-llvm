#pragma once

#include <math.h>

double type_log(double exp);
double type_log10(double exp);
/* Unused */
float type_log_float(float exp);

double type_pow(double base, double exponent);
/* Quick Pow will written as TypeScript. */
double type_sqrt(double sq);

double type_sin(double deg);
double type_cos(double deg);
double type_tan(double deg);

long type_ceil(double x);
long type_floor(double x);

// double type_fmax(double x, double y);

// int type_abs(int num);