/* A program to count spaces, blanks and new line */

#include <stdio.h>

int main() {
  long spaces = 0, tabs = 0, new_lines = 0;
  int c;

  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      ++spaces;
    } else if (c == '\n') {
      ++new_lines;
    } else if (c == '\t') {
      ++tabs;
    }
  }

  printf("Total Spaces: %ld\n", spaces);
  printf("Total Tabs: %ld\n", tabs);
  printf("Total New Line: %ld\n", new_lines);
  printf("Total: %ld\n", spaces + tabs + new_lines);
  return 0;
}
