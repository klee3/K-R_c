
/* A program to print the words in new line */

#include <stdio.h>

#define IN 1
#define OUT 0

int main() {
  int state = OUT;
  int c;

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      if (state == IN) {
        state = OUT;
        putchar('\n');
      }
    } else if (state == OUT) {
      state = IN;
    }

    if (state == IN) {
      putchar(c);
    }
  }

  return 0;
}
