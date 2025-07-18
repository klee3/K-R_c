/* A program to convert fahrenheit to celsius using function */

#include <stdio.h>

#define LOWER 0
#define UPPER 200
#define STEP 20

float to_celsius(float);

int main() {
  for (float i = LOWER; i <= UPPER; i += STEP) {
    printf("%6.0f\t%6.2f\n", i, to_celsius(i));
  }

  return 0;
}

float to_celsius(float fahrenheit) { return (5.0 / 9.0) * (fahrenheit - 32.0); }
