#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#include <stdbool.h>

#define s21_eps 1e-06
#define s21_nan 0. / 0.
#define s21_inf 1. / 0.
#define s21_minus_inf -1. / 0.
#define s21_M_E 2.7182818284590452354
#define s21_pi 3.14159265358979323846264338327950288

long double s21_sin(double x);
long double s21_cos(double x);
long double s21_tan(double x);
long double s21_asin(double x);
long double s21_acos(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_floor(double x);

/**
 * @brief Calculates the absolute value of an integer
 * @param x
 * @return int
 */
int s21_abs(int x);

/**
 * @brief Calculates the absolute value of an long double
 * @param x
 * @return long double
 */
long double s21_fabs(double x);

/**
 * @brief Returns the value of e raised to the given power
 * @param x
 * @return long double
 */
long double s21_exp(double x);

/**
 * @brief Raises a number to a given power
 * @param base
 * @param exp
 * @return long double
 */
long double s21_pow(double base, double exp);

/**
 * @brief Raises a number to the power given by an integer
 * @param base
 * @param exp
 * @return long double
 */
long double pow_int(double base, int exp);

/**
 * @brief Raises a number to the power given by a floating point number
 * @param base
 * @param exp
 * @return long double
 */
long double pow_double(double base, double exp);

/**
 * @brief Floating point division remainder
 * @param x
 * @param y
 * @return long double
 */
long double s21_fmod(double x, double y);

/**
 * @brief Calculates the natural logarithm(base e)
 * @param x
 * @return long double
 */
long double s21_log(double x);

/**
 * @brief Calculation of the natural logarithm
 * in a Taylor series near unity
 * @param x
 * @return long double
 */
long double log_Taylor(double x);

/**
 * @brief Calculation of the natural logarithm
 * in a Euler series near unity
 * @param x
 * @return long double
 */
long double log_Euler(double x);

/**
 * @brief Calculates the square root
 * @param x
 * @return long double
 */
long double s21_sqrt(double x);

#endif  // SRC_S21_MATH_H_
