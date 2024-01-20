#include "s21_math.h"

/* Taylor series */
long double s21_sin(long double x) { return s21_cos((S21_PI / 2) - x); }
