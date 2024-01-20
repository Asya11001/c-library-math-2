#ifndef S21_MATH
#define S21_MATH

#define CYCLE_LIM 10000
#define EXP_LIM 709

#define S21_EXP 2.71828182845904523536
#define S21_PI 3.14159265358979323846
#define S21_LN2 0.693147180559945286
#define S21_EPS 1e-20
#define INIT_RETURN_VALUE (-7)  // random non-existent in special values value

#define S21_POS_INF (1.0 / 0.0)
#define S21_NEG_INF (-1.0 / 0.0)
#define S21_NAN (0.0 / 0.0)

#define SWAP_IF_NEGATIVE(x) ((x) < 0 ? ((x) = -(x), 1) : 0)
#define S21_SIGN(x) ((x) < 0 ? -1 : 1)
#define S21_ISPOS_INF(X) ((x) == S21_POS_INF ? 1 : 0)
#define S21_ISNEG_INF(X) ((x) == S21_NEG_INF ? 1 : 0)
#define S21_ISINF(x) ((x) == (S21_POS_INF) || (x) == (S21_NEG_INF) ? 1 : 0)
#define S21_ISNAN(x) ((x) != (x))

int s21_abs(int x);
long double s21_acos(long double x);
long double s21_asin(long double x);
long double s21_atan(long double x);
long double s21_ceil(long double x);
long double s21_cos(long double x);
long double s21_exp(long double x);
long double s21_fabs(long double x);
long double s21_floor(long double x);
long double s21_fmod(long double x, long double y);
long double s21_log(long double x);
long double s21_pow(long double base, long double exp);
long double s21_sin(long double x);
long double s21_sqrt(long double x);
long double s21_tan(long double x);

#endif