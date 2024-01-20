#include "s21_math.h"

/* using trigonometric identities formulas */
long double s21_acos(long double x) {
  if (S21_ISNAN(x)) {
    return x;
  }
  if (S21_ISINF(x) && s21_fabs(x) > 1) {
    return S21_NAN;
  }
  if (x == 1) {
    return 0;
  }
  if (x == 0) {
    return S21_PI / 2;
  }
  if (x == -1) {
    return S21_PI;
  }

  long double result = 0;
  if (s21_fabs(x) != 1) {
    long double multiplier = s21_sqrt(1 - x * x);
    result = s21_atan(multiplier / x);
    if (x < 0 && x > -1) {
      result += S21_PI;
    }
  }
  return result;
}
