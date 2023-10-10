#include "s21_math.h"

int s21_abs(int x) { return x = x < 0 ? -x : x; }

long double s21_acos(double x) {
  long double result = 0;
  if (x != x)
    result = x;
  else if (s21_fabs(x) == S21_INF)
    result = S21_NAN;
  else if (!x)
    result = S21_M_PI_2;
  else if (s21_fabs(x) <= 1) {
    if (x > 0)
      result = s21_atan(s21_sqrt(1 - x * x) / x);
    else
      result = s21_atan(s21_sqrt(1 - x * x) / x) + S21_M_PI;
  } else
    result = S21_NAN;
  return result;
}

long double s21_asin(double x) {
  long double result = 0;
  if (x != x)
    result = x;
  else if (x) {
    if (s21_fabs(x) <= 1)
      result = s21_atan(x / (s21_sqrt(1 - x * x)));
    else
      result = S21_NAN;
  }
  return result;
}

long double s21_atan(double x) {
  long double result = 0;
  if (x != x)
    result = x;
  else if (x == 0)
    result = x;
  else if (x == -S21_INF)
    result = -S21_M_PI_2;
  else if (x == S21_INF)
    result = S21_M_PI_2;
  else if (s21_fabs(x) == 1)
    result = S21_M_PI_4 * x;
  else if (s21_fabs(x) < 1) {
    for (int i = 0; i < 5000; i++) {
      result += (s21_pow(-1, i) * s21_pow(x, 1 + 2 * i)) / (1 + 2 * i);
    }
  } else if (s21_fabs(x) > 1) {
    for (int i = 0; i < 5000; i++)
      result += (s21_pow(-1, i) * s21_pow(x, -1 - 2 * i)) / (1 + 2 * i);
    result = ((S21_M_PI * s21_sqrt(x * x)) / (2 * x)) - result;
  }
  return result;
}

long double s21_ceil(double x) {
  long double result = (long int)x;
  if (x != x || s21_fabs(x) == S21_INF)
    result = x;
  else if (x - (int)x > 0)
    result = (long int)x + 1;
  return result;
}

long double s21_cos(double x) {
  long double result = 0;
  if (x != x || s21_fabs(x) == S21_INF)
    result = S21_NAN;
  else
    result = s21_sin(S21_M_PI_2 - x);
  return result;
}

long double s21_exp(double x) {
  long double result = 1, temp = 1;
  if (!x)
    result = 1;
  else if (x > 710)
    result = S21_INF;
  else if (x < 0)
    result = 1 / s21_exp(-x);
  else {
    for (long int i = 1; temp > 1e-17; i++) result += temp *= x / i;
  }
  return result;
}

long double s21_fabs(double x) {
  if (x < 0) x = -x;
  return x;
}

long double s21_fact(int x) {
  long double result = 1;
  for (int i = 1; i <= x; i++) result *= i;
  return result;
}

long double s21_floor(double x) {
  long double result = (long int)x;
  if (x != x || s21_fabs(x) == S21_INF) result = x;
  if (x - (int)x < 0) result = (long int)x - 1;
  return result;
}

long double s21_fmod(double x, double y) {
  long double result = 0;
  if (s21_fabs(x) == S21_INF || !y)
    result = S21_NAN;
  else if (s21_fabs(y) == S21_INF)
    result = x;
  else
    result = x - ((int)(x / y) * y);
  return result;
}

long double s21_log(double x) {
  long double result = 0;
  if (!x)
    result = -S21_INF;
  else if (x < 0)
    result = -S21_NAN;
  else if (x != x || x == S21_INF)
    result = x;
  else {
    for (int i = 0; i < 100; i++)
      result = result + 2 * (x - s21_exp(result)) / (x + s21_exp(result));
  }
  return result;
}

long double s21_pow(double x, double y) {
  long double result = 0;
  if (!x && !y)
    result = 1;
  else if (x == -S21_INF && y == S21_INF)
    result = S21_INF;
  else if (x == -S21_INF && y == -S21_INF)
    result = 0;
  else if (x < 0 && y - (int)y)
    result = -S21_NAN;
  else {
    result = s21_exp(y * s21_log(s21_fabs(x)));
    if (x < 0 && (int)y % 2) result *= -1;
  }
  return result;
}

long double s21_sin(double x) {
  long double result = 0;
  if (s21_fabs(x) > 2 * S21_M_PI) x = s21_fmod(x, 2 * S21_M_PI);
  for (int i = 0; i < 17; i++)
    result += (s21_pow(-1, i) * s21_pow(x, 1 + 2 * i)) / s21_fact(1 + 2 * i);
  return result;
}

long double s21_sqrt(double x) {
  long double result = 0;
  if (x < 0)
    result = S21_NAN;
  else
    result = s21_pow(x, 0.5);
  return result;
}

long double s21_tan(double x) { return s21_sin(x) / s21_cos(x); }