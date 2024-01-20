#include "s21_math.h"

// Edmund Halley's Method
long double s21_log(long double x) {
  if (s21_fabs(x) < S21_EPS) {
    return S21_NEG_INF;
  }
  if (x < 0 || x == S21_NEG_INF) {
    return S21_NAN;
  }
  if (x == S21_POS_INF) {
    return x;
  }

  long double result = 0;
  long double power_of_two = 0;

  while (s21_pow(2, power_of_two) < x) {
    power_of_two++;
  }

  long double y_prev = power_of_two * S21_LN2;
  long double y_next = 0;
  int break_flag = 0;
  for (int i = 0; i < CYCLE_LIM && !break_flag; i++) {
    y_next = y_prev + 2 * (x - s21_exp(y_prev)) / (x + s21_exp(y_prev));
    if (s21_fabs(y_next - y_prev) < S21_EPS) {
      break_flag = 1;
    }
    y_prev = y_next;
  }
  result = y_next;
  return result;
}
