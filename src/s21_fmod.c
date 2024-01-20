#include "s21_math.h"

long double s21_fmod(long double x, long double y) {
  if (y == 0.0 || S21_ISINF(x)) {
    return S21_NAN;
  }
  if (S21_ISINF(y)) {
    return x;
  }

  long long int z = x / y;
  long double result = x - (long double)z * y;

  return result;
}
