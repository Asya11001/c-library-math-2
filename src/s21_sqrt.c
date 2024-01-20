#include "s21_math.h"

long double s21_sqrt(long double x) {
  if (x == -0.f) {
    return -0.f;
  }
  if (x < 0.f) {
    return S21_NAN;
  }

  return s21_pow(x, 0.5);
}
