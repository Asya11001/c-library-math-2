#include "s21_math.h"

// Taylor series
long double s21_atan(long double x) {
  if (S21_ISNAN(x)) {
    return x;
  }
  if (x == S21_POS_INF) {
    return S21_PI / 2;
  }
  if (x == S21_NEG_INF) {
    return -S21_PI / 2;
  }

  long double xx = x * x;
  long double result = 0;

  if (s21_fabs(x) < 1) {
    long double step = x;
    for (int i = 1; i < CYCLE_LIM && s21_fabs(step) / i > S21_EPS; i += 2) {
      result += step / i;
      step *= (-1) * xx;
    }
  } else if (s21_fabs(x) > 1) {
    long double step = 1 / x;
    for (int i = 1; i < CYCLE_LIM && s21_fabs(step) / i > S21_EPS; i += 2) {
      result += step / i;
      step *= (-1) * 1 / xx;
    }
    result = S21_PI * S21_SIGN(x) / 2 - result;
  } else if (s21_fabs(x) == 1) {
    result = S21_PI * S21_SIGN(x) / 4;
  }
  return result;
}
