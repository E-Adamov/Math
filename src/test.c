#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_math.h"

START_TEST(test_abs) {
  ck_assert_int_eq(s21_abs(0), abs(0));
  ck_assert_int_eq(s21_abs(1), abs(1));
  ck_assert_int_eq(s21_abs(-1), abs(-1));
  ck_assert_int_eq(s21_abs(2147483647), abs(2147483647));
  ck_assert_int_eq(s21_abs(-2147483647), abs(-2147483647));
}
END_TEST

START_TEST(test_fabs) {
  ck_assert_double_eq_tol(s21_fabs(0.0), fabs(0.0), s21_eps);
  ck_assert_double_eq_tol(s21_fabs(1.1), fabs(1.1), s21_eps);
  ck_assert_double_eq_tol(s21_fabs(-1.9), fabs(-1.9), s21_eps);
  ck_assert_double_eq_tol(s21_fabs(1.7E+308), fabs(1.7E+308), s21_eps);
  ck_assert_double_eq_tol(s21_fabs(-1.7E+308), fabs(-1.7E+308), s21_eps);
}
END_TEST

START_TEST(test_pow) {
  ck_assert_double_eq_tol(s21_pow(0., 0.), pow(0., 0.), s21_eps);
  ck_assert_double_eq_tol(s21_pow(0., 1.), pow(0., 1.), s21_eps);
  ck_assert_double_eq_tol(s21_pow(0., 1.1), pow(0., 1.1), s21_eps);
  ck_assert_double_eq_tol(s21_pow(0., 2), pow(0., 2), s21_eps);
  ck_assert(s21_pow(0., -1.) == s21_inf);
  ck_assert(s21_pow(0., -1.1) == s21_inf);
  ck_assert(s21_pow(0., -2) == s21_inf);

  ck_assert_double_eq_tol(s21_pow(1., 1.), pow(1., 1.), s21_eps);
  ck_assert_double_eq_tol(s21_pow(-1., 1.), pow(-1., 1.), s21_eps);
  ck_assert_double_eq_tol(s21_pow(-1., 2), pow(-1., 2), s21_eps);
  ck_assert(isnan(s21_pow(-1., 1.1)) == isnan(pow(-1., 1.1)));
  ck_assert_double_eq_tol(s21_pow(1., -1.), pow(1., -1.), s21_eps);

  ck_assert_double_eq_tol(s21_pow(1.1, 0), pow(1.1, 0), s21_eps);
  ck_assert_double_eq_tol(s21_pow(1.1, 1), pow(1.1, 1), s21_eps);
  ck_assert_double_eq_tol(s21_pow(1.1, -1), pow(1.1, -1), s21_eps);
  ck_assert_double_eq_tol(s21_pow(1.1, -2), pow(1.1, -2), s21_eps);

  ck_assert(isnan(s21_pow(-1.1, 1.1)) == isnan(pow(-1.1, 1.1)));
  ck_assert_double_eq_tol(s21_pow(1., -1.1), pow(1., -1.1), s21_eps);
  ck_assert_double_eq_tol(s21_pow(1.1, -1.1), pow(1.1, -1.1), s21_eps);

  ck_assert_double_eq_tol(s21_pow(2, 2.2), pow(2, 2.2), s21_eps);
  ck_assert_double_eq_tol(s21_pow(1, 2), pow(1, 2), s21_eps);
  ck_assert_double_eq_tol(s21_pow(10, 4), pow(10, 4), s21_eps);
  ck_assert_double_eq_tol(s21_pow(66, 5), pow(66, 5), s21_eps);
  ck_assert_double_eq_tol(s21_pow(0.1, 0.5), pow(0.1, 0.5), s21_eps);
  ck_assert_double_eq_tol(s21_pow(0.123, 3), pow(0.123, 3), s21_eps);
  ck_assert_double_eq_tol(s21_pow(-10, 4), pow(-10, 4), s21_eps);
  ck_assert_double_eq_tol(s21_pow(66.0, -5), pow(66.0, -5), s21_eps);
  ck_assert_double_eq_tol(s21_pow(-0.12, 3), pow(-0.12, 3), s21_eps);
  ck_assert_double_eq_tol(s21_pow(0.123, -3), pow(0.123, -3), s21_eps);
  ck_assert_double_eq_tol(s21_pow(-66, -5), pow(-66, -5), s21_eps);
  ck_assert_double_eq_tol(s21_pow(-0.123, -3), pow(-0.123, -3), s21_eps);
  ck_assert_double_eq_tol(s21_pow(3.65, 0), pow(3.65, 0), s21_eps);
  ck_assert_double_eq_tol(s21_pow(0, 15.3), pow(0, 15.3), s21_eps);

  ck_assert(isnan(s21_pow(1.1, s21_nan)) == isnan(pow(1.1, s21_nan)));
  ck_assert(isnan(s21_pow(-1.1, s21_nan)) == isnan(pow(-1.1, s21_nan)));
  ck_assert(isnan(s21_pow(s21_nan, 1.1)) == isnan(pow(s21_nan, 1.1)));
  ck_assert(isnan(s21_pow(s21_nan, -1.1)) == isnan(pow(s21_nan, -1.1)));
  ck_assert_double_eq_tol(s21_pow(1., s21_nan), pow(1., s21_nan), s21_eps);
  ck_assert(isnan(s21_pow(-1., s21_nan)) == isnan(pow(-1., s21_nan)));
  ck_assert(isnan(s21_pow(s21_nan, 1.)) == isnan(pow(s21_nan, 1.)));
  ck_assert(isnan(s21_pow(s21_nan, -1.)) == isnan(pow(s21_nan, -1.)));

  ck_assert(isnan(s21_pow(s21_inf, s21_nan)) == isnan(pow(s21_inf, s21_nan)));
  ck_assert(isnan(s21_pow(s21_nan, s21_inf)) == isnan(pow(s21_nan, s21_inf)));
  ck_assert(isnan(s21_pow(s21_nan, s21_minus_inf)) ==
            isnan(pow(s21_nan, s21_minus_inf)));
  ck_assert(isnan(s21_pow(s21_minus_inf, s21_nan)) ==
            isnan(pow(s21_minus_inf, s21_nan)));

  ck_assert_double_eq_tol(s21_pow(1., s21_inf), pow(1., s21_inf), s21_eps);
  ck_assert(s21_pow(1.1, s21_inf) == s21_inf);
  ck_assert(s21_pow(2, s21_inf) == s21_inf);
  ck_assert_double_eq_tol(s21_pow(0., s21_inf), pow(0., s21_inf), s21_eps);
  ck_assert_double_eq_tol(s21_pow(-1., s21_inf), pow(-1., s21_inf), s21_eps);
  ck_assert(s21_pow(-1.1, s21_inf) == s21_inf);
  ck_assert(s21_pow(-2, s21_inf) == s21_inf);

  ck_assert(s21_pow(s21_inf, 1.) == s21_inf);
  ck_assert(s21_pow(s21_inf, 1.1) == s21_inf);
  ck_assert(s21_pow(s21_inf, 2) == s21_inf);
  ck_assert_double_eq_tol(s21_pow(s21_inf, 0.), pow(s21_inf, 0.), s21_eps);
  ck_assert_double_eq_tol(s21_pow(s21_inf, -1.), pow(s21_inf, -1.), s21_eps);
  ck_assert_double_eq_tol(s21_pow(s21_inf, -1.1), pow(s21_inf, -1.1), s21_eps);
  ck_assert_double_eq_tol(s21_pow(s21_inf, -2), pow(s21_inf, -2), s21_eps);

  ck_assert(s21_pow(s21_inf, s21_inf) == s21_inf);
  ck_assert(s21_pow(s21_minus_inf, s21_inf) == s21_inf);
  ck_assert_double_eq_tol(s21_pow(s21_inf, s21_minus_inf),
                          pow(s21_inf, s21_minus_inf), s21_eps);

  ck_assert_double_eq_tol(s21_pow(1., s21_minus_inf), pow(1., s21_minus_inf),
                          s21_eps);
  ck_assert_double_eq_tol(s21_pow(1.1, s21_minus_inf), pow(1.1, s21_minus_inf),
                          s21_eps);
  ck_assert_double_eq_tol(s21_pow(2, s21_minus_inf), pow(2, s21_minus_inf),
                          s21_eps);
  ck_assert(s21_pow(0., s21_minus_inf) == s21_inf);
  ck_assert_double_eq_tol(s21_pow(-1., s21_minus_inf), pow(-1., s21_minus_inf),
                          s21_eps);
  ck_assert_double_eq_tol(s21_pow(-1.1, s21_minus_inf),
                          pow(-1.1, s21_minus_inf), s21_eps);
  ck_assert_double_eq_tol(s21_pow(-2, s21_minus_inf), pow(-2, s21_minus_inf),
                          s21_eps);

  ck_assert(s21_pow(s21_minus_inf, 1.) == s21_minus_inf);
  ck_assert(s21_pow(s21_minus_inf, 1.1) == s21_inf);
  ck_assert(s21_pow(s21_minus_inf, 2) == s21_inf);
  ck_assert_double_eq_tol(s21_pow(s21_minus_inf, 0.), pow(s21_minus_inf, 0.),
                          s21_eps);
  ck_assert_double_eq_tol(s21_pow(s21_minus_inf, -1.), pow(s21_minus_inf, -1.),
                          s21_eps);
  ck_assert_double_eq_tol(s21_pow(s21_minus_inf, -1.1),
                          pow(s21_minus_inf, -1.1), s21_eps);
  ck_assert_double_eq_tol(s21_pow(s21_minus_inf, -2), pow(s21_minus_inf, -2),
                          s21_eps);
}
END_TEST

START_TEST(test_exp) {
  ck_assert(fabsl(s21_exp(0) - exp(0)) < s21_eps);
  ck_assert(fabsl(s21_exp(1) - exp(1)) < s21_eps);
  ck_assert(fabsl(s21_exp(1.1) - exp(1.1)) < s21_eps);
  ck_assert(fabsl(s21_exp(2) - exp(2)) < s21_eps);
  ck_assert(fabsl(s21_exp(2.345) - exp(2.345)) < s21_eps);
  ck_assert(fabsl(s21_exp(-1) - exp(-1)) < s21_eps);
  ck_assert(fabsl(s21_exp(-1.1) - exp(-1.1)) < s21_eps);
  ck_assert(fabsl(s21_exp(-2) - exp(-2)) < s21_eps);
  ck_assert(fabsl(s21_exp(-2.345) - exp(-2.345)) < s21_eps);
  ck_assert(isnan(s21_exp(s21_nan)) == isnan(exp(s21_nan)));
  ck_assert(s21_exp(s21_inf) == s21_inf);
  ck_assert_double_eq_tol(s21_exp(s21_minus_inf), exp(s21_minus_inf), s21_eps);
}
END_TEST

START_TEST(test_log) {
  ck_assert(s21_log(0) == s21_minus_inf);
  ck_assert(s21_log(s21_inf) == s21_inf);
  ck_assert(isnan(s21_log(-1)) == true);
  ck_assert(isnan(s21_log(-1.1)) == true);
  ck_assert(isnan(s21_log(-2)) == true);
  ck_assert(isnan(s21_log(s21_nan)) == isnan(log(s21_nan)));
  ck_assert(isnan(s21_log(s21_minus_inf)) == isnan(log(s21_minus_inf)));
  ck_assert_double_eq_tol(s21_log(1), log(1), s21_eps);
  ck_assert_double_eq_tol(s21_log(0.000001), log(0.000001), s21_eps);
  ck_assert_double_eq_tol(s21_log(1.1), log(1.1), s21_eps);
  ck_assert_double_eq_tol(s21_log(2), log(2), s21_eps);
}
END_TEST

START_TEST(test_fmod) {
  ck_assert(isnan(s21_fmod(s21_nan, 2)) == isnan(fmod(s21_nan, 2)));
  ck_assert(isnan(s21_fmod(2, s21_nan)) == true);
  ck_assert(isnan(s21_fmod(2, 0)) == true);
  ck_assert(isnan(s21_fmod(s21_inf, 2)) == isnan(fmod(s21_inf, 2)));
  ck_assert(isnan(s21_fmod(s21_minus_inf, 2)) == isnan(fmod(s21_minus_inf, 2)));
  ck_assert_double_eq_tol(s21_fmod(2, s21_inf), fmod(2, s21_inf), s21_eps);
  ck_assert_double_eq_tol(s21_fmod(2, s21_minus_inf), fmod(2, s21_minus_inf),
                          s21_eps);
  ck_assert_double_eq_tol(s21_fmod(2.2, s21_eps), fmod(2.2, s21_eps), s21_eps);
  ck_assert_double_eq_tol(s21_fmod(5, 2), fmod(5, 2), s21_eps);
  ck_assert_double_eq_tol(s21_fmod(4, 2), fmod(4, 2), s21_eps);
  ck_assert_double_eq_tol(s21_fmod(2.2, 2.2), fmod(2.2, 2.2), s21_eps);
}
END_TEST

START_TEST(test_sqrt) {
  ck_assert(isnan(s21_sqrt(s21_nan)) == isnan(sqrt(s21_nan)));
  ck_assert(isnan(s21_sqrt(s21_minus_inf)) == isnan(sqrt(s21_minus_inf)));
  ck_assert(isnan(s21_sqrt(-1)) == true);
  ck_assert(isnan(s21_sqrt(-1.1)) == true);
  ck_assert(s21_sqrt(s21_inf) == s21_inf);
  ck_assert_double_eq_tol(s21_sqrt(0), sqrt(0), s21_eps);
  ck_assert_double_eq_tol(s21_sqrt(1.1), sqrt(1.1), s21_eps);
  ck_assert_double_eq_tol(s21_sqrt(2.), sqrt(2.), s21_eps);
}
END_TEST

START_TEST(test_acos) {
  ck_assert(fabsl(s21_acos(1) - acos(1)) < s21_eps);
  ck_assert(fabsl(s21_acos(0.9) - acos(0.9)) < s21_eps);
  ck_assert(fabsl(s21_acos(0.5) - acos(0.5)) < s21_eps);
  ck_assert(fabsl(s21_acos(0.1) - acos(0.1)) < s21_eps);
  ck_assert(fabsl(s21_acos(0.01) - acos(0.01)) < s21_eps);
  ck_assert(fabsl(s21_acos(0.001) - acos(0.001)) < s21_eps);
  ck_assert(fabsl(s21_acos(-1) - acos(-1)) < s21_eps);
  ck_assert(fabsl(s21_acos(-0.9) - acos(-0.9)) < s21_eps);
  ck_assert(fabsl(s21_acos(-0.5) - acos(-0.5)) < s21_eps);
  ck_assert(fabsl(s21_acos(-0.1) - acos(-0.1)) < s21_eps);
  ck_assert(fabsl(s21_acos(-0.01) - acos(-0.01)) < s21_eps);
  ck_assert(fabsl(s21_acos(-0.001) - acos(-0.001)) < s21_eps);
  // Test 1
  double num = 0.55;
  long double orig_res = acos(num), our_res = s21_acos(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);
  // Test 4
  double num3 = s21_inf;
  long double orig_res3 = acos(num3), our_res3 = s21_acos(num3);
  int suc3 = 0;
  if (isnan(orig_res3) && isnan(our_res3)) suc3 = 1;
  ck_assert_int_eq(1, suc3);
  // Test 5
  double num4 = -s21_inf;
  long double orig_res4 = acos(num4), our_res4 = s21_acos(num4);
  int suc4 = 0;
  if (isnan(orig_res4) && isnan(our_res4)) suc4 = 1;
  ck_assert_int_eq(1, suc4);
  // Test 6
  double num5 = s21_nan;
  long double orig_res5 = s21_acos(num5), our_res5 = acos(num5);
  int suc5 = 0;
  if (isnan(orig_res5) && isnan(our_res5)) suc5 = 1;
  ck_assert_int_eq(1, suc5);
  // Test 7
  ck_assert_ldouble_nan(s21_acos(s21_nan));
  ck_assert_ldouble_nan(acos(s21_nan));
  // Test 8
  ck_assert_ldouble_eq_tol(s21_acos(1.0), acos(1.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(-1.0), acos(-1.0), 1e-6);
  // Test 9
  ck_assert_ldouble_eq_tol(s21_acos(0.0), acos(0.0), s21_eps);
  ck_assert_ldouble_eq_tol(s21_acos(-0.0), acos(-0.0), s21_eps);
  // Test 10
  ck_assert_ldouble_eq_tol(s21_acos(-1), acos(-1), s21_eps);
  // Test 11
  ck_assert_ldouble_eq_tol(s21_acos(1), acos(1), s21_eps);
  // Test 12
  ck_assert_ldouble_eq_tol(s21_acos(-sqrt(3) / 2), acos(-sqrt(3) / 2), s21_eps);
  // Test 13
  ck_assert_ldouble_eq_tol(s21_acos(-sqrt(2) / 2), acos(-sqrt(2) / 2), s21_eps);
  // Test 14
  ck_assert_ldouble_eq_tol(s21_acos(-1 / 2), acos(-1 / 2), s21_eps);
  // Test 15
  ck_assert_ldouble_eq_tol(s21_acos(1 / 2), acos(1 / 2), s21_eps);
  // Test 16
  ck_assert_ldouble_eq_tol(s21_acos(1), acos(1), s21_eps);
  // Test 17
  ck_assert_ldouble_eq_tol(s21_acos(sqrt(2) / 2), acos(sqrt(2) / 2), s21_eps);
  // Test 18
  ck_assert_ldouble_eq_tol(s21_acos(sqrt(3) / 2), acos(sqrt(3) / 2), s21_eps);
}
END_TEST

START_TEST(test_asin) {
  ck_assert(isnan(s21_asin(5)) == true);
  ck_assert(fabsl(s21_asin(1) - asin(1)) < s21_eps);
  ck_assert(fabsl(s21_asin(0.9) - asin(0.9)) < s21_eps);
  ck_assert(fabsl(s21_asin(0.5) - asin(0.5)) < s21_eps);
  ck_assert(fabsl(s21_asin(0.1) - asin(0.1)) < s21_eps);
  ck_assert(fabsl(s21_asin(0.01) - asin(0.01)) < s21_eps);
  ck_assert(fabsl(s21_asin(0.001) - asin(0.001)) < s21_eps);
  ck_assert(fabsl(s21_asin(0.0001) - asin(0.0001)) < s21_eps);
  ck_assert(fabsl(s21_asin(0) - asin(0)) < s21_eps);
  ck_assert(fabsl(s21_asin(-0) - asin(-0)) < s21_eps);
  ck_assert(isnan(s21_asin(-5)) == true);
  ck_assert(fabsl(s21_asin(-1) - asin(-1)) < s21_eps);
  ck_assert(fabsl(s21_asin(-0.9) - asin(-0.9)) < s21_eps);
  ck_assert(fabsl(s21_asin(-0.5) - asin(-0.5)) < s21_eps);
  ck_assert(fabsl(s21_asin(-0.1) - asin(-0.1)) < s21_eps);
  ck_assert(fabsl(s21_asin(-0.01) - asin(-0.01)) < s21_eps);
  ck_assert(fabsl(s21_asin(-0.001) - asin(-0.001)) < s21_eps);
  ck_assert(fabsl(s21_asin(-0.0001) - asin(-0.0001)) < s21_eps);
  ck_assert(isnan(s21_asin(s21_nan)) && isnan(asin(s21_nan)));
  ck_assert(isnan(s21_asin(-s21_nan)) && isnan(asin(-s21_nan)));
  double num = 0.55;
  long double orig_res = asin(num), our_res = s21_asin(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);
  // Test 1
  double num1 = -0.99;
  long double orig_res1 = asin(num1), our_res1 = s21_asin(num1);
  int suc1 = 0;
  if ((fabsl(orig_res1 - our_res1) <= 1e-6)) suc1 = 1;
  ck_assert_int_eq(1, suc1);
  // Test 3
  double num3 = s21_inf;
  long double orig_res3 = asin(num3), our_res3 = s21_asin(num3);
  int suc3 = 0;
  if (isnan(orig_res3) && isnan(our_res3)) suc3 = 1;
  ck_assert_int_eq(1, suc3);
  // Test 4
  double num4 = -s21_inf;
  long double orig_res4 = asin(num4), our_res4 = s21_asin(num4);
  int suc4 = 0;
  if (isnan(orig_res4) && isnan(our_res4)) suc4 = 1;
  ck_assert_int_eq(1, suc4);
  // Test 5
  double num5 = s21_nan;
  long double orig_res5 = asin(num5), our_res5 = s21_asin(num5);
  int suc5 = 0;
  if (isnan(orig_res5) && isnan(our_res5)) suc5 = 1;
  ck_assert_int_eq(1, suc5);
  // Test 9
  ck_assert_ldouble_eq_tol(s21_asin(1.0), asin(1.0), s21_eps);
  ck_assert_ldouble_eq_tol(s21_asin(-1.0), asin(-1.0), s21_eps);
  // Test 10
  ck_assert_ldouble_eq_tol(s21_asin(0.0), asin(0.0), s21_eps);
  ck_assert_ldouble_eq_tol(s21_asin(-0.0), asin(-0.0), s21_eps);
  // Test 11
  ck_assert_ldouble_eq_tol(s21_asin(0.0), asin(0.0), s21_eps);
  // Test 12
  ck_assert_ldouble_eq_tol(s21_asin(-1), asin(-1), s21_eps);
  // Test 13
  ck_assert_ldouble_eq_tol(s21_asin(1), asin(1), s21_eps);
  // Test 14
  ck_assert_ldouble_eq_tol(s21_asin(-sqrt(3) / 2), asin(-sqrt(3) / 2), s21_eps);
  // Test 15
  ck_assert_ldouble_eq_tol(s21_asin(-sqrt(2) / 2), asin(-sqrt(2) / 2), s21_eps);
  // Test 16
  ck_assert_ldouble_eq_tol(s21_asin(-1 / 2), asin(-1 / 2), s21_eps);
  // Test 17
  ck_assert_ldouble_eq_tol(s21_asin(1 / 2), asin(1 / 2), s21_eps);
  // Test 19
  ck_assert_ldouble_eq_tol(s21_asin(sqrt(2) / 2), asin(sqrt(2) / 2), s21_eps);
  // Test 20
  ck_assert_ldouble_eq_tol(s21_asin(sqrt(3) / 2), asin(sqrt(3) / 2), s21_eps);
}
END_TEST

START_TEST(test_atan) {
  ck_assert(fabsl(s21_atan(0.5) - atan(0.5)) < s21_eps);
  ck_assert(fabsl(s21_atan(1) - atan(1)) < s21_eps);
  ck_assert(fabsl(s21_atan(2) - atan(2)) < s21_eps);
  ck_assert(fabsl(s21_atan(3) - atan(3)) < s21_eps);
  ck_assert(fabsl(s21_atan(4) - atan(4)) < s21_eps);
  ck_assert(fabsl(s21_atan(5) - atan(5)) < s21_eps);
  ck_assert(fabsl(s21_atan(10) - atan(10)) < s21_eps);
  ck_assert(fabsl(s21_atan(100) - atan(100)) < s21_eps);
  ck_assert(fabsl(s21_atan(1000) - atan(1000)) < s21_eps);
  ck_assert(fabsl(s21_atan(-0.5) - atan(-0.5)) < s21_eps);
  ck_assert(fabsl(s21_atan(-1) - atan(-1)) < s21_eps);
  ck_assert(fabsl(s21_atan(-2) - atan(-2)) < s21_eps);
  ck_assert(fabsl(s21_atan(-3) - atan(-3)) < s21_eps);
  ck_assert(fabsl(s21_atan(-4) - atan(-4)) < s21_eps);
  ck_assert(fabsl(s21_atan(-5) - atan(-5)) < s21_eps);
  ck_assert(fabsl(s21_atan(-10) - atan(-10)) < s21_eps);
  ck_assert(fabsl(s21_atan(-100) - atan(-100)) < s21_eps);
  ck_assert(isnan(s21_atan(s21_nan)) && isnan(atan(s21_nan)));
  ck_assert(isnan(s21_atan(-s21_nan)) && isnan(atan(-s21_nan)));
  ck_assert_float_eq_tol(s21_atan(-15.01), atan(-15.01), 1e-6);
  // Test 1
  double num = -0.99;
  long double orig_res = s21_atan(num), our_res = atan(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);
  // Test 2
  ck_assert_float_eq(-9999999999, -9999999999);
  double num1 = s21_nan;
  long double orig_res1 = s21_atan(num1), our_res1 = atan(num1);
  int suc1 = 0;
  if (isnan(orig_res1) && isnan(our_res1)) suc1 = 1;
  ck_assert_int_eq(1, suc1);
  ck_assert_ldouble_nan(s21_atan(s21_nan));
  ck_assert_ldouble_nan(atan(s21_nan));
  // Test 7
  ck_assert_ldouble_eq_tol(s21_atan(1.0), atan(1.0), s21_eps);
  ck_assert_ldouble_eq_tol(s21_atan(1.1), atan(1.1), s21_eps);
  ck_assert_ldouble_eq_tol(s21_atan(-1.0), atan(-1.0), s21_eps);
  ck_assert_ldouble_eq_tol(s21_atan(-1.1), atan(-1.1), s21_eps);
  // Test 8
  ck_assert_ldouble_eq_tol(s21_atan(0.0), atan(0.0), s21_eps);
  ck_assert_ldouble_eq_tol(s21_atan(-0.0), atan(-0.0), s21_eps);
  // Test 9
  ck_assert_ldouble_eq_tol(s21_atan(-1), atan(-1), s21_eps);
  // Test 10
  ck_assert_ldouble_eq_tol(s21_atan(-sqrt(3) / 2), atan(-sqrt(3) / 2), s21_eps);
  // Test 11
  ck_assert_ldouble_eq_tol(s21_atan(-sqrt(2) / 2), atan(-sqrt(2) / 2), s21_eps);
  // Test 12
  ck_assert_ldouble_eq_tol(s21_atan(-1 / 2), atan(-1 / 2), s21_eps);
  // Test 13
  ck_assert_ldouble_eq_tol(s21_atan(1 / 2), atan(1 / 2), s21_eps);
  // Test 14
  ck_assert_ldouble_eq_tol(s21_atan(1), atan(1), s21_eps);
  // Test 15
  ck_assert_ldouble_eq_tol(s21_atan(sqrt(3) / 2), atan(sqrt(3) / 2), s21_eps);
  // Test 16
  ck_assert_ldouble_eq_tol(s21_atan(1), atan(1), s21_eps);
  // Test 17
  ck_assert_ldouble_eq_tol(s21_atan(1.23456e-7), atan(1.23456e-7), s21_eps);
  // Test 18
  ck_assert_ldouble_eq_tol(s21_atan(2.1234567), atan(2.1234567), s21_eps);
  // Test 19
  ck_assert_ldouble_eq_tol(s21_atan(2.1234567e-7), atan(2.1234567e-7), s21_eps);
  // Test 20
  ck_assert_ldouble_eq_tol(s21_atan(2.1234567e-16), atan(2.1234567e-16),
                           s21_eps);
  // Test 21
  ck_assert_float_nan(s21_atan(s21_nan));
}
END_TEST

START_TEST(test_ceil) {
  ck_assert(fabsl(s21_ceil(-0.567) - ceil(-0.567)) < s21_eps);
  ck_assert(fabsl(s21_ceil(-0.523) - ceil(-0.523)) < s21_eps);
  ck_assert(fabsl(s21_ceil(1.6) - ceil(1.6)) < s21_eps);
  ck_assert(fabsl(s21_ceil(1.9999) - ceil(1.999)) < s21_eps);
  ck_assert(fabsl(s21_ceil(123456.6789) - ceil(123456.6789)) < s21_eps);
  ck_assert(fabsl(s21_ceil(-1.6) - ceil(-1.6)) < s21_eps);
  ck_assert(fabsl(s21_ceil(-1.9999) - ceil(-1.999)) < s21_eps);
  ck_assert(fabsl(s21_ceil(-123456.6789) - ceil(-123456.6789)) < s21_eps);
  ck_assert(fabsl(s21_ceil(0) - ceil(0)) < s21_eps);
  ck_assert(fabsl(s21_ceil(1e-9) - ceil(1e-9)) < s21_eps);
  ck_assert(fabsl(s21_ceil(1e9) - ceil(1e9)) < s21_eps);
  ck_assert(fabsl(s21_ceil(99999.9999999) - ceil(99999.9999999)) < s21_eps);
  ck_assert(fabsl(s21_ceil(-99999.9999999) - ceil(-99999.9999999)) < s21_eps);
  ck_assert(isnan(s21_ceil(s21_nan)) && isnan(ceil(s21_nan)));
  ck_assert(s21_ceil(s21_inf) && s21_inf);
  ck_assert(s21_ceil(s21_minus_inf) && s21_minus_inf);
  ck_assert_ldouble_nan(s21_ceil(s21_nan));
  ck_assert_ldouble_nan(ceil(s21_nan));
  ck_assert_ldouble_eq(s21_ceil(-15.01), ceil(-15.01));
  // Test 1
  ck_assert_ldouble_eq(s21_ceil(15.01), ceil(15.01));
  // Test 2
  ck_assert_ldouble_eq(s21_ceil(s21_inf), ceil(s21_inf));
  // Test 3
  ck_assert_ldouble_eq(s21_ceil(-s21_inf), ceil(-s21_inf));
  // Test 4
  ck_assert_ldouble_eq(s21_ceil(-0.12), ceil(-0.12));
  // Test 8
  ck_assert_ldouble_eq(s21_ceil(0), ceil(0));
  // Test 9
  ck_assert_ldouble_eq(s21_ceil(0.0), ceil(0.0));
  // Test 10
  ck_assert_ldouble_eq(s21_ceil(21.21), ceil(21.21));
  // Test 11
  ck_assert_ldouble_eq(s21_ceil(21.91), ceil(21.91));
  // Test 12
  ck_assert_ldouble_eq(s21_ceil(-21.21), ceil(-21.21));
  // Test 13
  ck_assert_ldouble_eq(s21_ceil(-21.91), ceil(-21.91));
  ck_assert(fabsl(s21_ceil(1e9) - ceil(1e9)) < s21_eps);
  ck_assert(fabsl(s21_ceil(99999.9999999) - ceil(99999.9999999)) < s21_eps);
  ck_assert(fabsl(s21_ceil(-99999.9999999) - ceil(-99999.9999999)) < s21_eps);
  ck_assert(isnan(s21_ceil(s21_nan)) && isnan(ceil(s21_nan)));
  ck_assert(s21_ceil(s21_inf) && s21_inf);
  ck_assert(s21_ceil(-s21_inf) && -s21_inf);
}
END_TEST

START_TEST(test_cos) {
  ck_assert(fabsl(s21_cos(1) - cos(1)) < s21_eps);
  ck_assert(fabsl(s21_cos(2) - cos(2)) < s21_eps);
  ck_assert(fabsl(s21_cos(3) - cos(3)) < s21_eps);
  ck_assert(fabsl(s21_cos(4) - cos(4)) < s21_eps);
  ck_assert(fabsl(s21_cos(5) - cos(5)) < s21_eps);
  ck_assert(fabsl(s21_cos(-1) - cos(-1)) < s21_eps);
  ck_assert(fabsl(s21_cos(-2) - cos(-2)) < s21_eps);
  ck_assert(fabsl(s21_cos(-3) - cos(-3)) < s21_eps);
  ck_assert(fabsl(s21_cos(-4) - cos(-4)) < s21_eps);
  ck_assert(fabsl(s21_cos(-5) - cos(-5)) < s21_eps);
  ck_assert(fabsl(s21_cos(100) - cos(100)) < s21_eps);
  ck_assert(fabsl(s21_cos(0.1) - cos(0.1)) < s21_eps);
  ck_assert(fabsl(s21_cos(0.01) - cos(0.01)) < s21_eps);
  ck_assert(fabsl(s21_cos(0.001) - cos(0.001)) < s21_eps);
  ck_assert(fabsl(s21_cos(-0.1) - cos(-0.1)) < s21_eps);
  ck_assert(fabsl(s21_cos(-0.01) - cos(-0.01)) < s21_eps);
  ck_assert(fabsl(s21_cos(-0.001) - cos(-0.001)) < s21_eps);
  ck_assert(isnan(s21_cos(s21_nan)) == isnan(cos(s21_nan)));
  ck_assert(isinf(s21_cos(s21_minus_inf)) == isinf(cos(s21_minus_inf)));
  ck_assert(isinf(s21_cos(s21_inf)) == isinf(cos(s21_inf)));
  double num = 0.55;
  long double orig_res = s21_cos(num), our_res = s21_cos(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);
  // Test 1
  double num1 = -0.999999;
  long double orig_res1 = cos(num1), our_res1 = s21_cos(num1);
  int suc1 = 0;
  if ((fabsl(orig_res1 - our_res1) <= 1e-6)) suc1 = 1;
  ck_assert_int_eq(1, suc1);
  // Test 2
  double num2 = 628;
  long double orig_res2 = cos(num2), our_res2 = s21_cos(num2);
  int suc2 = 0;
  if ((fabsl(orig_res2 - our_res2) <= 1e-6)) suc2 = 1;
  ck_assert_int_eq(1, suc2);
  // Test 3
  ck_assert_float_eq(s21_cos(0), cos(0));
  // Test 4
  ck_assert_float_eq(s21_cos(-1), cos(-1));
  // Test 5
  double num3 = s21_nan;
  long double orig_res3 = cos(num3), our_res3 = s21_cos(num3);
  int suc3 = 0;
  if (isnan(orig_res3) && isnan(our_res3)) suc3 = 1;
  ck_assert_int_eq(1, suc3);
  // Test 6
  double num4 = s21_inf;
  long double orig_res4 = cos(num4), our_res4 = s21_cos(num4);
  int suc4 = 0;
  if (isnan(orig_res4) && isnan(our_res4)) suc4 = 1;
  ck_assert_int_eq(1, suc4);
  // Test 7
  double num5 = -s21_inf;
  long double orig_res5 = cos(num5), our_res5 = s21_cos(num5);
  int suc5 = 0;
  if (isnan(orig_res5) && isnan(our_res5)) suc5 = 1;
  ck_assert_int_eq(1, suc5);
  // Test 8
  double x = 0;
  ck_assert_double_eq_tol(s21_cos(x), cosl(x), 1e-06);
  // Test 12
  ck_assert_ldouble_eq_tol(s21_cos(0.0), cosl(0.0), 1e-06);
  // Test 13
  ck_assert_double_eq_tol(s21_cos(M_PI / 4), cosl(M_PI / 4), 1e-06);
  // Test 14
  ck_assert_double_eq_tol(s21_cos(M_PI / 6), cosl(M_PI / 6), 1e-06);
  // Test 15
  ck_assert_double_eq_tol(s21_cos(M_PI / 3), cosl(M_PI / 3), 1e-06);
  // Test 16
  ck_assert_double_eq_tol(s21_cos(M_PI / 2), cosl(M_PI / 2), 1e-06);
  // Test 17
  ck_assert_double_eq_tol(s21_cos(3 * M_PI / 2), cosl(3 * M_PI / 2), 1e-06);
  // Test 18
  ck_assert_double_eq_tol(s21_cos(2 * M_PI), cosl(2 * M_PI), 1e-06);
  // Test 19
  ck_assert_double_eq_tol(s21_cos(174.532925199433), cosl(174.532925199433),
                          1e-06);
  // Test 20
  ck_assert_double_eq_tol(s21_cos(-174.532925199433), cosl(-174.532925199433),
                          1e-06);
  double exp49;
  double res1;
  long double res2;
  for (exp49 = -100; exp49 < 110; exp49 += 0.25) {
    res1 = cos(exp49);
    res2 = s21_cos(exp49);
    ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
  }
  for (exp49 = -10000; exp49 < 14310; exp49 += 10.54646) {
    res1 = cos(exp49);
    res2 = s21_cos(exp49);
    ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
  }
  for (exp49 = -100 * M_PI; exp49 < 110 * M_PI; exp49 += (M_PI / 12)) {
    res1 = cos(exp49);
    res2 = s21_cos(exp49);
    ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
  }
  ck_assert_ldouble_eq_tol(cos(0.0), s21_cos(0.0), 1e-6);
}
END_TEST

START_TEST(test_floor) {
  ck_assert(fabsl(s21_floor(-1.7) - floor(-1.7)) < s21_eps);
  ck_assert(fabsl(s21_floor(1.6) - floor(1.6)) < s21_eps);
  ck_assert(fabsl(s21_floor(1.9999) - floor(1.999)) < s21_eps);
  ck_assert(fabsl(s21_floor(123456.6789) - floor(123456.6789)) < s21_eps);
  ck_assert(fabsl(s21_floor(-1.6) - floor(-1.6)) < s21_eps);
  ck_assert(fabsl(s21_floor(-1.9999) - floor(-1.999)) < s21_eps);
  ck_assert(fabsl(s21_floor(-123456.6789) - floor(-123456.6789)) < s21_eps);
  ck_assert(isnan(s21_floor(s21_nan)) && isnan(floor(s21_nan)));
  ck_assert(s21_floor(s21_inf) && s21_inf);
  ck_assert(s21_floor(s21_minus_inf) && s21_minus_inf);
  ck_assert_ldouble_nan(floor(s21_nan));
  ck_assert_ldouble_nan(s21_floor(s21_nan));

  ck_assert_ldouble_eq(s21_floor(0.0), floor(0.0));

  ck_assert_ldouble_eq(s21_floor(21.21), floor(21.21));

  ck_assert_ldouble_eq(s21_floor(21.91), floor(21.91));

  ck_assert_ldouble_eq(s21_floor(-21.21), floor(-21.21));

  ck_assert_ldouble_eq(s21_floor(-21.91), floor(-21.91));

  ck_assert_ldouble_eq(s21_floor(0), floor(0));

  ck_assert_ldouble_eq(s21_floor(-15.01), floor(-15.01));

  ck_assert_ldouble_eq(s21_floor(15.01), floor(15.01));

  ck_assert_ldouble_eq(s21_floor(s21_inf), floor(s21_inf));

  ck_assert_ldouble_eq(s21_floor(-s21_inf), floor(-s21_inf));
  double exp49;
  for (exp49 = -1000; exp49 < 1000; exp49 += 0.25) {
    long double res1;
    long double res2;
    res1 = floor(exp49);
    res2 = s21_floor(exp49);
    ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
  }
}
END_TEST

START_TEST(test_sin) {
  ck_assert(fabsl(s21_sin(1) - sin(1)) < s21_eps);
  ck_assert(fabsl(s21_sin(2) - sin(2)) < s21_eps);
  ck_assert(fabsl(s21_sin(3) - sin(3)) < s21_eps);
  ck_assert(fabsl(s21_sin(4) - sin(4)) < s21_eps);
  ck_assert(fabsl(s21_sin(5) - sin(5)) < s21_eps);
  ck_assert(fabsl(s21_sin(-1) - sin(-1)) < s21_eps);
  ck_assert(fabsl(s21_sin(-2) - sin(-2)) < s21_eps);
  ck_assert(fabsl(s21_sin(-3) - sin(-3)) < s21_eps);
  ck_assert(fabsl(s21_sin(-4) - sin(-4)) < s21_eps);
  ck_assert(fabsl(s21_sin(-5) - sin(-5)) < s21_eps);
  ck_assert(fabsl(s21_sin(100) - sin(100)) < s21_eps);
  ck_assert(fabsl(s21_sin(0.1) - sin(0.1)) < s21_eps);
  ck_assert(fabsl(s21_sin(0.01) - sin(0.01)) < s21_eps);
  ck_assert(fabsl(s21_sin(0.001) - sin(0.001)) < s21_eps);
  ck_assert(fabsl(s21_sin(-0.1) - sin(-0.1)) < s21_eps);
  ck_assert(fabsl(s21_sin(-0.01) - sin(-0.01)) < s21_eps);
  ck_assert(fabsl(s21_sin(-0.001) - sin(-0.001)) < s21_eps);
  ck_assert(isnan(s21_sin(s21_nan)) == isnan(sin(s21_nan)));
  double num = 2147444543;
  long double orig_res = s21_sin(num), our_res = s21_sin(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);
  // Test 1
  ck_assert_float_eq(s21_sin(0), sin(0));
  // Test 2
  double num1 = 1;
  long double orig_res1 = s21_sin(num1), our_res1 = s21_sin(num1);
  int suc1 = 0;
  if ((fabsl(orig_res1 - our_res1) <= 1e-6)) suc1 = 1;
  ck_assert_int_eq(1, suc1);
  // Test 3
  double num2 = -1;
  long double orig_res2 = s21_sin(num2), our_res2 = s21_sin(num2);
  int suc2 = 0;
  if ((fabsl(orig_res2 - our_res2) <= 1e-6)) suc2 = 1;
  ck_assert_int_eq(1, suc2);
  // Test 4
  double num3 = 0.999999;
  long double orig_res3 = s21_sin(num3), our_res3 = s21_sin(num3);
  int suc3 = 0;
  if ((fabsl(orig_res3 - our_res3) <= 1e-6)) suc3 = 1;
  ck_assert_int_eq(1, suc3);
  // Test 5
  double num4 = -0.999999;
  long double orig_res4 = s21_sin(num4), our_res4 = s21_sin(num4);
  int suc4 = 0;
  if ((fabsl(orig_res4 - our_res4) <= 1e-6)) suc4 = 1;
  ck_assert_int_eq(1, suc4);
  // Test 6
  double num5 = s21_nan;
  long double orig_res5 = sin(num5), our_res5 = s21_sin(num5);
  int suc5 = 0;
  if (isnan(orig_res5) && isnan(our_res5)) suc5 = 1;
  ck_assert_int_eq(1, suc5);
  // Test 7
  double num6 = s21_inf;
  long double orig_res6 = sin(num6), our_res6 = s21_sin(num6);
  int suc6 = 0;
  if (isnan(orig_res6) && isnan(our_res6)) suc6 = 1;
  ck_assert_int_eq(1, suc6);
  // Test 8
  double num7 = -s21_inf;
  long double orig_res7 = sin(num7), our_res7 = s21_sin(num7);
  int suc7 = 0;
  if (isnan(orig_res7) && isnan(our_res7)) suc7 = 1;
  ck_assert_int_eq(1, suc7);
  // Test 9
  double x = 0;
  ck_assert_double_eq_tol(s21_sin(x), sinl(x), 1e-06);
  // Test 10
  ck_assert_ldouble_nan(s21_sin(-s21_inf));
  ck_assert_ldouble_nan(sinl(-s21_inf));
  // Test 11
  ck_assert_ldouble_nan(s21_sin(s21_inf));
  ck_assert_ldouble_nan(sinl(s21_inf));
  // Test 12
  ck_assert_ldouble_nan(s21_sin(s21_nan));
  ck_assert_ldouble_nan(sinl(s21_nan));
  // Test 13
  ck_assert_double_eq_tol(s21_sin(0.0), sin(0.0), 1e-06);
  // Test 14
  ck_assert_double_eq_tol(s21_sin(M_PI / 6), sin(M_PI / 6), 1e-06);
  // Test 15
  ck_assert_double_eq_tol(s21_sin(M_PI / 4), sin(M_PI / 4), 1e-06);
  // Test 16
  ck_assert_double_eq_tol(s21_sin(M_PI / 3), sin(M_PI / 3), 1e-06);
  // Test 17
  ck_assert_double_eq_tol(s21_sin(M_PI / 2), sin(M_PI / 2), 1e-06);
  // Test 18
  ck_assert_double_eq_tol(s21_sin(3 * M_PI / 2), sin(3 * M_PI / 2), 1e-06);
  // Test 19
  ck_assert_double_eq_tol(s21_sin(2 * M_PI), sin(2 * M_PI), 1e-06);
  // Test 20
  ck_assert_double_eq_tol(s21_sin(-5 * M_PI), sin(-5 * M_PI), 1e-06);
  // Test 21
  ck_assert_double_eq_tol(s21_sin(M_PI / 100), sin(M_PI / 100), 1e-06);
  ck_assert_double_eq_tol(s21_sin(99 * M_PI / 100), sin(99 * M_PI / 100),
                          1e-06);
  ck_assert_double_eq_tol(s21_sin(-3 * M_PI), sin(-3 * M_PI), 1e-06);
  ck_assert_double_eq_tol(s21_sin(12.453 * M_PI), sin(12.453 * M_PI), 1e-06);
  // Test 22
  ck_assert_double_eq_tol(s21_sin(174.532925199433), sin(174.532925199433),
                          1e-06);
  // Test 23
  ck_assert_double_eq_tol(s21_sin(-174.532925199433), sin(-174.532925199433),
                          1e-06);
  // Test 24
  ck_assert_double_eq_tol(s21_sin(-M_PI), sin(-M_PI), 1e-06);
  double exp49;
  double res1;
  long double res2;
  for (exp49 = -100; exp49 < 110; exp49 += 0.25) {
    res1 = sin(exp49);
    res2 = s21_sin(exp49);
    ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
  }
  for (exp49 = -10000; exp49 < 14310; exp49 += 10.54646) {
    res1 = sin(exp49);
    res2 = s21_sin(exp49);
    ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
  }
  for (exp49 = -100 * M_PI; exp49 < 110 * M_PI; exp49 += (M_PI / 12)) {
    res1 = sin(exp49);
    res2 = s21_sin(exp49);
    ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
  }
  ck_assert_ldouble_eq_tol(sin(0.0), s21_sin(0.0), 1e-6);
}
END_TEST

START_TEST(test_tan) {
  ck_assert(fabsl(s21_tan(0) - tan(0)) < s21_eps);
  ck_assert(fabsl(s21_tan(0.7) - tan(0.7)) < s21_eps);
  ck_assert(fabsl(s21_tan(0.07) - tan(0.07)) < s21_eps);
  ck_assert(fabsl(s21_tan(0.007) - tan(0.007)) < s21_eps);
  ck_assert(fabsl(s21_tan(0.0007) - tan(0.0007)) < s21_eps);
  ck_assert(fabsl(s21_tan(1) - tan(1)) < s21_eps);
  ck_assert(fabsl(s21_tan(2) - tan(2)) < s21_eps);
  ck_assert(fabsl(s21_tan(3) - tan(3)) < s21_eps);
  ck_assert(fabsl(s21_tan(4) - tan(4)) < s21_eps);
  ck_assert(fabsl(s21_tan(5) - tan(5)) < s21_eps);
  ck_assert(fabsl(s21_tan(100) - tan(100)) < s21_eps);
  ck_assert(fabsl(s21_tan(-0.7) - tan(-0.7)) < s21_eps);
  ck_assert(fabsl(s21_tan(-0.07) - tan(-0.07)) < s21_eps);
  ck_assert(fabsl(s21_tan(-0.007) - tan(-0.007)) < s21_eps);
  ck_assert(fabsl(s21_tan(-0.0007) - tan(-0.0007)) < s21_eps);
  ck_assert(fabsl(s21_tan(-1) - tan(-1)) < s21_eps);
  ck_assert(fabsl(s21_tan(-2) - tan(-2)) < s21_eps);
  ck_assert(fabsl(s21_tan(-3) - tan(-3)) < s21_eps);
  ck_assert(fabsl(s21_tan(-4) - tan(-4)) < s21_eps);
  ck_assert(fabsl(s21_tan(-5) - tan(-5)) < s21_eps);
  ck_assert(fabsl(s21_tan(-100) - tan(-100)) < s21_eps);
  ck_assert(isnan(s21_tan(s21_nan)) == isnan(tan(s21_nan)));
  ck_assert_float_eq_tol(s21_tan(-15.01), tan(-15.01), 1e-6);
  // Test 1
  double num = 0.55;
  long double orig_res = s21_tan(num), our_res = s21_tan(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);
  // Test 2
  ck_assert_float_eq(-9999999999, -9999999999);
  // Test 3
  double num1 = s21_nan;
  long double orig_res1 = tan(num1), our_res1 = s21_tan(num1);
  int suc1 = 0;
  if (isnan(orig_res1) && isnan(our_res1)) suc1 = 1;
  ck_assert_int_eq(1, suc1);
  // Test 4
  double num2 = s21_inf;
  long double orig_res2 = tan(num2), our_res2 = s21_tan(num2);
  int suc2 = 0;
  if (isnan(orig_res2) && isnan(our_res2)) suc2 = 1;
  ck_assert_int_eq(1, suc2);
  // Test 5
  double num3 = -s21_inf;
  long double orig_res3 = tan(num3), our_res3 = s21_tan(num3);
  int suc3 = 0;
  if (isnan(orig_res3) && isnan(our_res3)) suc3 = 1;
  ck_assert_int_eq(1, suc3);
  // Test 6
  double x = 0;
  ck_assert_double_eq_tol(s21_tan(x), tanl(x), 1e-06);
  // Test 7
  ck_assert_ldouble_nan(s21_tan(-s21_inf));
  ck_assert_ldouble_nan(tanl(-s21_inf));
  // Test 8
  ck_assert_ldouble_nan(s21_tan(s21_inf));
  ck_assert_ldouble_nan(tanl(s21_inf));
  // Test 9
  ck_assert_ldouble_nan(s21_tan(s21_nan));
  ck_assert_ldouble_nan(tanl(s21_nan));
  // Test 10
  ck_assert_double_eq_tol(s21_tan(0.0), tanl(0.0), 1e-06);
  // Test 11
  ck_assert_double_eq_tol(s21_tan(M_PI / 6), tanl(M_PI / 6), 1e-06);
  // Test 12
  ck_assert_double_eq_tol(s21_tan(M_PI / 4), tanl(M_PI / 4), 1e-06);
  // Test 13
  ck_assert_double_eq_tol(s21_tan(-2 * M_PI), tanl(-2 * M_PI), 1e-06);
  // Test 14
  ck_assert_double_eq_tol(s21_tan(M_PI), tanl(M_PI), 1e-06);
  // Test 15
  ck_assert_double_eq_tol(s21_tan(M_PI / 3), tanl(M_PI / 3), 1e-06);
  // Test 16
  ck_assert_double_eq_tol(s21_tan(3 * M_PI / 3), tanl(3 * M_PI / 3), 1e-06);
  // Test 17
  ck_assert_double_eq_tol(s21_tan(174.532925199433), tanl(174.532925199433),
                          1e-06);
  // Test 18
  ck_assert_double_eq_tol(s21_tan(-174.532925199433), tanl(-174.532925199433),
                          1e-06);
  double exp49;
  double res1;
  long double res2;
  for (exp49 = -5; exp49 < -4; exp49 += 0.1) {
    res1 = tan(exp49);
    res2 = s21_tan(exp49);
    ck_assert_double_eq_tol(res1, res2, 1e-6);
  }

  for (exp49 = -M_PI * 2; exp49 < M_PI * 2; exp49 += 0.01) {
    res1 = tan(exp49);
    res2 = s21_tan(exp49);
    ck_assert_double_eq_tol(res1, res2, 1e-6);
  }
}
END_TEST

Suite *example_suite_create(void) {
  Suite *suite = suite_create("Test start");
  TCase *tcase_test = tcase_create("Function test\n");

  tcase_add_test(tcase_test, test_abs);
  tcase_add_test(tcase_test, test_fabs);
  tcase_add_test(tcase_test, test_pow);
  tcase_add_test(tcase_test, test_exp);
  tcase_add_test(tcase_test, test_log);
  tcase_add_test(tcase_test, test_fmod);
  tcase_add_test(tcase_test, test_sqrt);
  tcase_add_test(tcase_test, test_acos);
  tcase_add_test(tcase_test, test_asin);
  tcase_add_test(tcase_test, test_atan);
  tcase_add_test(tcase_test, test_ceil);
  tcase_add_test(tcase_test, test_cos);
  tcase_add_test(tcase_test, test_floor);
  tcase_add_test(tcase_test, test_sin);
  tcase_add_test(tcase_test, test_tan);

  suite_add_tcase(suite, tcase_test);

  return suite;
}

int main(void) {
  Suite *suite = example_suite_create();
  SRunner *suite_runner = srunner_create(suite);

  srunner_set_fork_status(suite_runner, CK_NOFORK);
  srunner_run_all(suite_runner, (enum print_output)CK_NOFORK);

  int failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);

  return (failed_count != 0) ? 1 : 0;
}
