/* A program to count the words */

#include <stdio.h>

#define IN 1
#define OUT 0

int main() {
  int state = OUT;
  long words = 0;
  int c;

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      state = OUT;
    } else if (state == OUT) {
      state = IN;
      ++words;
    }
  }

  printf("Total words is: %ld\n", words);

  return 0;
}
