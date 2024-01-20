#include "s21_math.h"

/* using trigonometric identities formulas */
long double s21_asin(long double x) {
  if (S21_ISNAN(x)) {
    return x;
  }
  if (S21_ISINF(x) && s21_fabs(x) > 1) {
    return S21_NAN;
  }
  long double sign = S21_SIGN(x);
  long double result = 0;

  if (s21_fabs(x) != 1) {
    long double multiplier = s21_sqrt(1 - x * x);
    result = s21_atan(x / multiplier);
  } else {
    result = S21_PI * sign / 2;
  }

  return result;
}
