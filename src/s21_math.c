#include "s21_math.h"

#define S21_PI 3.14159265358979
#define S21_E 2.718281828459045
#define S21_INF 1. / 0.
#define S21_NAN 0. / 0.

int s21_abs(int x) { return (x < 0) ? -x : x; }

long double s21_ceil(double x) {
  long double c = s21_remainder(x);
  if (c != 0) {
    x = integer_number_part(x);
    if (x >= 0 && c > 0) {
      x++;
    }
  }
  return (long double)x;
}

long double integer_number_part(double x) {
  long double result = (long double)x - s21_remainder(x);
  return result;
}

long double s21_fabs(double x) { return (long double)((x < 0) ? -x : x); }

long double s21_floor(double x) {
  if (x >= 0) {
    x = integer_number_part(x);
  } else {
    int temp = integer_number_part(x);
    x = s21_remainder(x) == 0 ? temp : temp - 1;
  }
  return (long double)x;
}

long double s21_remainder(double x) {
  int buffer;
  buffer = (int)x;
  x -= (double)buffer;
  return (long double)x;
}

long double s21_fmod(double x, double y) {
  int flag_minus_x = (x < 0 ? 1 : 0), flag_minus_y = (y < 0 ? 1 : 0);
  double buffer = y;
  int factor;
  x = s21_fabs(x);
  y = s21_fabs(y);
  if (y != 0) {
    factor = (int)(x / y);
    y *= (factor + 1);
    y -= buffer;
    x = x - y;
  } else {
    x = 0.0 / 0.0;
  }
  x = (flag_minus_x == 1 ? -x : x);
  x = (flag_minus_y == 1 ? -x : x);
  return (long double)(x);
}

long double s21_asin(double x) {
  long double result = 0;

  if ((x >= 0 && x <= 1) || (x >= -1 && x < 0)) {
    result = s21_atan((x / s21_sqrt(1 - x * x)));
  } else {
    result = S21_NAN;
  }

  return result;
}

long double s21_acos(double x) {
  long double result = 0;

  if (x >= 0 && x < 1) {
    result = s21_atan((s21_sqrt(1 - x * x) / x));
  } else if (x == 1) {
    result = 0;
  } else if (x >= -1 && x < 0) {
    result = s21_atan((s21_sqrt(1 - x * x) / x)) + S21_PI;
  } else {
    result = S21_NAN;
  }

  return result;
}

long double abs_double(long double n) { return n < 0 ? -n : n; }

long double s21_atan(double x) {
  long double polynomial = 0;
  long double argument = x;

  if (s21_fabs(x) > 1) {
    argument = 1 / s21_fabs(x);
  }

  long double monomial = argument;

  for (int i = 1; s21_fabs(monomial) > 1e-8; i++) {
    polynomial += monomial;
    monomial *= (-1) * (((argument * argument) * (2 * i - 1)) / (2 * i + 1));
  }

  if (s21_fabs(x) > 1) {
    polynomial = (S21_PI / 2) - polynomial;
  }

  if (x < -1) {
    polynomial = -polynomial;
  }

  return polynomial;
}

long double s21_cos(double x) {
  long double polynomial = 0;
  long double argument = x;
  while (!(argument > S21_PI / -2 && argument < (3 * S21_PI) / 2)) {
    if (x < 0) {
      argument += 2 * S21_PI;
    } else {
      argument -= 2 * S21_PI;
    }
  }

  long double monomial = 1;

  for (int i = 1; s21_fabs(monomial) > 1e-10; i++) {
    polynomial += monomial;
    monomial *= (-1) * argument * argument / ((2 * i) * (2 * i - 1));
  }

  return polynomial;
}

long double s21_exp(double x) {
  if (x < 0) {
    return 1 / s21_exp(-x);
  }
  if (x > 20) {
    return s21_exp(x / 2) * s21_exp(x / 2);
  }

  long double argument = 1;
  long double polynomial = 1;

  for (int i = 1; s21_fabs(argument) > 1e-10; i++) {
    argument *= x / i;
    polynomial += argument;
  }

  return polynomial;
}

long double s21_log(double x) {
  long double argument = x;
  long double integer_part = 0;
  long double polynomial;
  if (argument == 0) {
    polynomial = -S21_INF;
  } else if (argument < 0) {
    polynomial = S21_NAN;
  } else {
    while (argument >= 2) {
      argument /= S21_E;
      integer_part++;
    }

    polynomial = integer_part;

    for (int i = 1; i < 1000; i++) {
      int coefficient = i % 2 == 0 ? -i : i;
      polynomial += pow_int(argument - 1, i) / coefficient;
    }
  }
  return polynomial;
}

long double s21_pow(double base, double exp) {
  long double xnp1;
  if (base == 0) {
    if (exp == 0) {
      xnp1 = 1;
    } else {
      xnp1 = 0;
    }
  } else {
    int flag = 1;
    if (base < 0) {
      if (exp < 0 && s21_remainder(exp) != 0) {
        xnp1 = S21_NAN;
        flag = 0;
      }
    }
    if (flag) {
      double b = base;
      double e = exp;
      if (base < 0) {
        b = -base;
      }
      if (exp < 0) {
        e = -exp;
      }
      long double x0 = 1;
      long double xn = x0 * (1 - s21_log(x0) + e * s21_log(b));

      xnp1 = xn * (1 - s21_log(xn) + e * s21_log(b));

      while (s21_fabs(xn - xnp1) >= 1e-6) {
        xn = xnp1;
        xnp1 = xn * (1 - s21_log(xn) + e * s21_log(b));
      }
      if (base < 0) {
        if (s21_fmod(e, 2) == 1.0) {
          xnp1 *= -1;
        }
      }
      if (exp < 0) {
        xnp1 = 1 / xnp1;
      }
    }
  }
  return xnp1;
}

long double s21_sin(double x) {
  long double polynomial = 0;
  long double argument = x;
  while (!(argument > S21_PI / -2 && argument < (3 * S21_PI) / 2)) {
    if (x < 0) {
      argument += 2 * S21_PI;
    } else {
      argument -= 2 * S21_PI;
    }
  }

  long double monomial = argument;

  for (int i = 1; s21_fabs(monomial) > 1e-10; i++) {
    polynomial += monomial;
    monomial *= (-1) * argument * argument / (2 * i) / (2 * i + 1);
  }

  return polynomial;
}

long double s21_sqrt(double n) {
  long double result;
  result = 1.0;
  if (n < 0) {
    result = S21_NAN;
  } else {
    while (s21_fabs(result * result - n) > 1e-12) {
      result = (result + n / result) / 2;
    }
  }
  return result;
}

long double s21_tan(double x) {
  double argument = x;
  while (!(argument > S21_PI / -2 && argument < S21_PI / 2)) {
    if (x < 0) {
      argument += S21_PI;
    } else {
      argument -= S21_PI;
    }
  }

  long double cos = s21_cos(2 * argument);
  long double result = s21_sqrt((1 - cos) / (1 + cos));
  if (argument < 0) {
    result = -result;
  }

  return result;
}

long double pow_int(double base, int exp) {
  if (exp == 0) {
    return 1;
  } else if (exp % 2 == 1) {
    return base * pow_int(base, exp - 1);
  } else {
    long double temp = pow_int(base, exp / 2);
    return temp * temp;
  }
}
