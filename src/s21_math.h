#ifndef S21_MATH_H
#define S21_MATH_H

#define S21_INF __builtin_inf()
#define S21_NAN __builtin_nan("")
#define S21_M_E 2.718281828459045235360287471352662498
#define S21_M_PI 3.141592653589793238462643383279502884
#define S21_M_PI_2 1.570796326794896619231321691639751442
#define S21_M_PI_4 0.785398163397448309615660845819875721
#define S21_EPS_9 1e-9

int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_fact(int x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double x, double y);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);

#endif