#include "s21_math.h"

int is_odd_long_double(long double number) {
  if ((long long int)number != number) {
    return 0;
  }
  if (s21_abs((long long int)number % 2) == 1) {
    return 1;
  } else {
    return 0;
  }
}

long double s21_pown(long double base, long double exp) {
  long double result = 1;
  if (exp > 0) {
    for (int i = 0; i < exp; i++) {
      result *= base;
    }
  } else if (exp < 0) {
    for (int i = 0; i < -exp; i++) {
      result /= base;
    }
  }
  return result;
}

long double s21_powq(long double base, long double exp) {
  long double result = base >= 0 ? s21_exp(exp * s21_log(base)) : S21_NAN;
  return result;
}

long double check_for_special_values(long double base, long double exp,
                                     int *p_flag_is_special_case) {
  long double return_value = INIT_RETURN_VALUE;

  if (base == 1) {
    return_value = 1.f;
  }
  if (base == -1 && (exp == S21_NEG_INF || exp == S21_POS_INF)) {
    return_value = 1.f;
  }
  if (base == S21_NEG_INF && exp < 0.f && !is_odd_long_double(exp)) {
    return_value = 0.f;
  }
  if (base == S21_NEG_INF && exp < 0.f && is_odd_long_double(exp)) {
    return_value = -0.f;
  }
  if (base == S21_NEG_INF && exp > 0.f && !is_odd_long_double(exp)) {
    return_value = S21_POS_INF;
  }
  if (base == S21_NEG_INF && exp > 0.f && is_odd_long_double(exp)) {
    return_value = S21_NEG_INF;
  }
  if (s21_fabs(base) < 1.f && exp == S21_NEG_INF) {
    return_value = S21_POS_INF;
  }
  if (s21_fabs(base) > 1.f && exp == S21_NEG_INF) {
    return_value = +0.f;
  }
  if (s21_fabs(base) < 1.f && exp == S21_POS_INF) {
    return_value = +0.f;
  }
  if (s21_fabs(base) > 1.f && exp == S21_POS_INF) {
    return_value = S21_POS_INF;
  }

  if (return_value != INIT_RETURN_VALUE) {
    *p_flag_is_special_case = 1;
  }
  return return_value;
}

long double s21_pow(long double base, long double exp) {
  int flag_is_special_case = 0;
  long double result = 0;
  result = check_for_special_values(base, exp, &flag_is_special_case);
  if (flag_is_special_case) {
    return result;
  }

  if ((long double)(long long int)exp == exp) {
    result = s21_pown(base, exp);
  } else {
    result = s21_powq(base, exp);
  }

  return result;
}
