#include "s21_math.h"

long double s21_exp(long double x) {
  if (S21_ISNAN(x) || x == S21_POS_INF) {
    return x;
  }
  if (x == S21_NEG_INF) {
    return 0;
  }
  if (x > EXP_LIM) {
    return S21_POS_INF;
  }

  int sign = SWAP_IF_NEGATIVE(x);
  long double result = 0;
  long double step = 1;
  for (int i = 1; s21_fabs(step) > S21_EPS && i < CYCLE_LIM; i++) {
    result += step;
    step *= x / i;
  }
  return sign ? 1 / result : result;
}
