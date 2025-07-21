/*
 * Extended atof implementation with scientific notation support
 *
 * This program converts a numeric string, including optional decimal point
 * and scientific notation (e.g., "123.45e-6"), into a double-precision
floating-point number.
 *
 * Functions:
 * - atof: Parses a string and returns its double value, supporting:
 *   * optional leading whitespace and sign
 *   * integer and fractional parts
 *   * optional scientific notation with 'e' or 'E' and signed exponent
 *
 * The main function demonstrates atof by converting a sample string and
printing the result.
 */

#include <ctype.h>
#include <math.h>
#include <stdio.h>

double atof(char s[]);

int main() {
  char test_str[] = "123.45e-6";
  double result = atof(test_str);
  printf("The string \"%s\" converts to %g\n", test_str, result);
  return 0;
}
/* atof: convert string s to double */
double atof(char s[]) {
  double val = 0.0, power = 1.0;
  int i = 0, sign = 1, exp_sign = 1, exponent = 0;

  // Skip whitespace
  while (isspace(s[i]))
    i++;

  // Handle optional sign
  if (s[i] == '-') {
    sign = -1;
    i++;
  } else if (s[i] == '+') {
    i++;
  }
  // Integer part
  while (isdigit(s[i])) {
    val = 10.0 * val + (s[i] - '0');
    i++;
  }
  // Fractional part
  if (s[i] == '.') {
    i++;
    while (isdigit(s[i])) {
      val = 10.0 * val + (s[i] - '0');
      power *= 10.0;
      i++;
    }
  }

  // Scientific notation part
  if (s[i] == 'e' || s[i] == 'E') {
    i++;
    if (s[i] == '-') {
      exp_sign = -1;
      i++;
    } else if (s[i] == '+') {
      i++;
    }

    while (isdigit(s[i])) {
      exponent = 10 * exponent + (s[i] - '0');
      i++;
    }

    exponent *= exp_sign;
    return sign * (val / power) * pow(10, exponent);
  }

  return sign * (val / power);
}