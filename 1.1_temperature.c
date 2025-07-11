/* A Program to convert the Celsius to Fahrenheit */

#include <stdio.h>

int main(void) {
  float celsius, fahrenheit;
  int lower = 0, upper = 200, step = 10;

  printf("%s\n\n", "A Program to print fahrenheit to their equivalent celsius");
  printf("%s\t\t%s\n", "Celsius", "Fahrenheit");
  printf("%s\t\t%s\n", "-------", "----------");

  fahrenheit = lower;
  while (fahrenheit <= upper) {
    celsius = (5.0 / 9.0) * (fahrenheit - 32.0);
    printf("%6.2f\t\t%6.0f\n", celsius, fahrenheit);
    fahrenheit += step;
  }

  return 0;
}
