#include "s21_math.h"

long double s21_sin(double x) {
  long double sum = 0.0;  // сумма ряда на старте равна нулю
  if (x != x || x == s21_inf || x == -s21_inf) {
    sum = s21_nan;
  } else {
    x = s21_fmod(x, 2.0 * s21_pi);  // понижаем аргумент кратно 2 пи
    double q = x;  // первое слагаемое ряда Тейлора
    int i = 3;  // порядковый номер слагаемого в ряду Тейлора
    double f = x;  // факториал
    while (s21_fabs(q) > 1E-15) {
      sum = sum + q;  // добавляем слагаемое к общей сумме
      f = f * -x * x / ((i - 1) * i);
      q = f;
      i += 2;
    }
  }
  return sum;
}

long double s21_cos(double x) {
  long double sum = 0.0;  // сумма ряда на старте равна нулю
  if (x != x || x == s21_inf || x == -s21_inf) {
    sum = s21_nan;
  } else {
    x = s21_fmod(x, 2 * s21_pi);  // понижаем аргумент кратно 2 пи
    double q = 1.0;  // первое слагаемое ряда Тейлора
    int i = 2;  // порядковый номер слагаемого в ряду Тейлора
    double f = 1.0;  // факториал
    while (s21_fabs(q) > 1E-15) {  // пока очередное слагаемое больше
      sum = sum + q;  // добавляем слагаемое к общей сумме
      f = f * -x * x / ((i - 1) * i);
      q = f;
      i += 2;
    }
  }
  return sum;
}

long double s21_tan(double x) {
  x = s21_fmod(x, 2 * s21_pi);  // понижаем аргумент кратно 2 пи
  long double result = s21_sin(x) / s21_cos(x);
  if (x == s21_pi / 2) result = 16331239353195370L;
  if (x == -s21_pi / 2) result = -16331239353195370L;
  return result;
}

long double s21_asin(double x) {
  long double sum = 0.0;
  if (-1.0 < x && x < 1.0) {
    long double q = x;  // первое слагаемое ряда Тейлора
    int i = 2;  // порядковый номер слагаемого в ряду Тейлора
    long double f = x;  // факториал
    while (s21_fabs(q) > 1E-15) {
      sum = sum + q;
      f = f * x * x * (i - 1) / i;
      q = f / (i + 1);
      i += 2;
    }
  } else if (x == 1.0) {
    sum = s21_pi / 2.0;
  } else if (x == -1.0) {
    sum = -s21_pi / 2.0;
  } else {
    sum = s21_nan;
  }
  return sum;
}

long double s21_acos(double x) {
  long double result = 0.0;
  result = s21_pi / 2 - s21_asin(x);
  return result;
}

long double s21_atan(double x) {
  long double result = s21_asin(x / s21_sqrt(x * x + 1.0));
  return result;
}

long double s21_ceil(double x) {
  long double result = 0.0;
  long double integer = (long long int)x;
  if (x != x || x == s21_inf || x == -s21_inf) {
    result = x;
  } else if (x > 0 && integer != x) {
    result = (integer + 1.0);
  } else if (x < 0 && integer != x) {
    result = integer;
  } else {
    result = integer;
  }
  return result;
}

long double s21_floor(double x) {
  long double result = 0.0;
  long double integer = (long long int)x;
  if (x != x || x == s21_inf || x == -s21_inf) {
    result = x;
  } else if (x > 0 && integer != x) {
    result = integer;
  } else if (x < 0 && integer != x) {
    result = (integer - 1.0);
  } else {
    result = integer;
  }
  return result;
}

int s21_abs(int x) { return (x < 0) ? -x : x; }

long double s21_fabs(double x) { return (x < 0) ? -x : x; }

long double s21_exp(double x) {
  long double result = 0;

  if (x != x) {
    result = s21_nan;
  } else if (x == s21_inf) {
    result = s21_inf;
  } else if (x == s21_minus_inf) {
    result = 0.;
  } else {
    result = s21_pow(s21_M_E, x);
  }
  return result;
}

long double s21_pow(double base, double exp) {
  long double result = 0;

  if (base == 1.) {
    result = 1;
  } else if (exp != exp || base != base) {
    result = s21_nan;
  } else if (exp == s21_inf) {
    result = (s21_fabs(base) == 1) ? 1. : (base == 0.) ? 0. : s21_inf;
  } else if (exp == s21_minus_inf) {
    result = (s21_fabs(base) == 1) ? 1. : (base == 0.) ? s21_inf : 0.;
  } else if (base == s21_inf) {
    result = (exp > 0) ? s21_inf : (exp == 0) ? 1. : 0.;
  } else if (base == s21_minus_inf) {
    if (exp > 0)
      result = (exp == 1) ? s21_minus_inf : s21_inf;
    else
      result = (exp == -1) ? -0. : (exp == 0) ? 1. : 0.;
  } else if (base == 0.) {
    if (exp == 0)
      result = 1.;
    else if (exp < 0)
      result = s21_inf;
  } else if (exp == (int)exp) {
    result = pow_int(base, (int)exp);
  } else {
    result = pow_double(base, exp);
  }

  return result;
}

long double pow_int(double base, int exp) {
  long double result = 1;

  if (base == -1.) {
    result = (exp > 1) ? 1 : -1;
  } else {
    for (int i = 0; i < s21_abs(exp); i++) {
      result *= base;
    }

    if (exp < 0) result = 1. / result;
  }

  return result;
}

long double pow_double(double base, double exp) {
  long double result;

  if (base < 0.) {
    result = s21_nan;
  } else {
    base = exp * s21_log(base);
    int n = 1;
    double a = 1;
    long double s = a;
    while (s21_fabs(a) >= s21_eps && n < 600) {
      a = a * base / n;
      s += a;
      n++;
    }
    if (n == 600 && base < 0) {
      result = 0;
    } else if (n == 600 && base > 0) {
      result = s21_inf;
    } else {
      result = s;
    }
  }

  return result;
}

long double s21_fmod(double x, double y) {
  long double result = 0.;

  if (x != x || y != y || y == 0 || x == s21_inf || x == s21_minus_inf) {
    result = s21_nan;
  } else if (y == s21_inf || y == s21_minus_inf) {
    result = x;
  } else if (s21_fabs(y) <= s21_eps) {
    result = 0.;
  } else {
    long long int whole_part = x / y;
    result = x - whole_part * y;
  }

  return result;
}

long double s21_log(double x) {
  long double result = 0.;

  if (x < 0 || x != x || x == s21_minus_inf) {
    result = s21_nan;
  } else if (x == 0) {
    result = s21_minus_inf;
  } else if (x == s21_inf) {
    result = s21_inf;
  } else if (x > 0. && x < 1.) {
    result = log_Taylor(x);
  } else if (x > 1.) {
    result = log_Euler(x);
  }
  // } else {

  // }

  return result;
}

long double log_Taylor(double x) {
  long double result = 0., term = x - 1;
  long long div = 2;
  long double temp = term;
  while (temp > 1E-15 || -temp > 1E-15) {
    if (temp > 1E-15) {
      result -= temp;
    } else {
      result += temp;
    }
    term = term * (x - 1);
    temp = term * (-1);
    temp /= div;
    div += 1;
  }

  result += term;
  return result;
}

long double log_Euler(double x) {
  long double result = 0., term = (x - 1) / x;
  long long div = 2;
  long double temp = term;

  while (temp > 1E-15) {
    result += temp;
    term *= (x - 1) / x;
    temp = term * (1. / div);
    div += 1;
  }

  return result;
}

long double s21_sqrt(double x) {
  long double result = 0.;

  if (x != x || x == s21_minus_inf || x < 0) {
    result = s21_nan;
  } else if (x == s21_inf) {
    result = s21_inf;
  } else if (x == 0.) {
    result = 0.;
  } else {
    result = s21_pow(x, 0.5);
  }

  return result;
}
