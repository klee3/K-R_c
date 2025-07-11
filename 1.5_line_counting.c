/*Program to count new line character */
#include <stdio.h>

int main() {
  long new_line = 0;
  int c;

  while ((c = getchar()) != EOF) {
    if (c == '\n') {
      ++new_line;
    }
  }
  printf("Total new line character: %ld\n", new_line);

  return 0;
}
