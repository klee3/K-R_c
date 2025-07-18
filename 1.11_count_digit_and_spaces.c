/* A program to count the digit, whitespace and other character */

#include <stdio.h>
#include <string.h>

int main() {
  long nwhite = 0, nother = 0;
  int ndigit[10];
  int c;

  // Fill array with zeros
  memset(ndigit, 0, sizeof(ndigit));

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      ++nwhite;
    } else if (c >= '0' && c <= '9') {
      ++ndigit[c - '0'];
    } else {
      ++nother;
    }
  }

  printf("Total no of whitespaces: %ld\n", nwhite);
  printf("Digit: ");
  for (int i = 0; i < 10; ++i) {
    printf("%d ", ndigit[i]);
  }
  putchar('\n');
  printf("Total no of other character: %ld\n", nother);

  return 0;
}
