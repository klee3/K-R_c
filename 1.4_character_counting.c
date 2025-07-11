/* Program to count character including newline */

#include <stdio.h>

int main() {
  long number_of_character = 0;

  while (getchar() != EOF) {
    ++number_of_character;
  }

  printf("Total character: %ld\n", number_of_character);
  return 0;
}
