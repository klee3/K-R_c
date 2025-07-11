/* A program to copy whatever user input as outpu */

#include <stdio.h>

int main(void) {
  int c;

  while ((c = getchar()) != EOF) {
    putchar(c);
  }

  printf("Is getchar() = EOF? %d\n", c);
  printf("What is EOF? %d\n", EOF);

  return 0;
}
