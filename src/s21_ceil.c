#include "s21_math.h"

long double s21_ceil(long double x) {
  if (S21_ISINF(x) || S21_ISNAN(x)) {
    return x;
  }
  long long int ipt = (long long int)x;
  ipt += (x > 0 && (x - ipt));
  long double result = (long double)ipt;
  return result;
}
