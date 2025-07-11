/* A program to replace multiple spaces with a single space */

#include <stdio.h>

int main() {
  int prev_c = 0, c;

  while ((c = getchar()) != EOF) {
    if (c != ' ') {
      putchar(c);
    } else if (prev_c != ' ') {
      putchar(c);
    }
    prev_c = c;
  }

  return 0;
}
