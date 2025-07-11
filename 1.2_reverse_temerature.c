/* A program to convert celsius to fahrenheit in reverse order */

#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 10

int main() {
  printf("%s\t\t%s\n", "Celsius", "Fahrenheit");
  printf("%s\t\t%s\n\n", "-------", "----------");

  for (float fahrenheit = UPPER; fahrenheit >= LOWER; fahrenheit -= STEP) {
    float celsius =
        (5.0 / 9.0) *
        (fahrenheit - 32.0); // formula to convert fahrenheit to celsius
    printf("%6.2f\t\t%6.f\n", celsius, fahrenheit);
  }
  return 0;
}
