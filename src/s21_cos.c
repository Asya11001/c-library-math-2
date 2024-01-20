#include "s21_math.h"

/* Taylor series */
long double s21_cos(long double x) {
  if (S21_ISNAN(x)) {
    return x;
  }
  if (S21_ISINF(x)) {
    return S21_NAN;
  }

  long double result = 0;
  long double k = s21_floor(x / S21_PI);
  long double temp = x - k * S21_PI;
  long double temp_squared = temp * temp;
  long double step = (s21_floor(k / 2) == k / 2 ? 1 : -1);

  for (int i = 1; i < CYCLE_LIM && s21_fabs(step) > S21_EPS; i += 2) {
    result += step;
    step *= (-1) * temp_squared / (i * (i + 1));
  }
  return result;
}
