/* A program to reverse a line */

#include <stdio.h>

#define MAX_LINE 1000

void reverse(char from[], char to[], int len);
int get_line(char line[], int max_len);

int main() {
  char line[MAX_LINE], rev_line[MAX_LINE];
  int line_len = 0;

  while ((line_len = get_line(line, MAX_LINE)) > 0) {
    reverse(line, rev_line, line_len);
    printf("%s", rev_line);
  }

  return 0;
}

/* reverse: reverse a string */
void reverse(char from[], char to[], int len) {
  int i = 0;

  while (i < len) {
    to[i] = from[len - i - 1];
    ++i;
  }
  to[len] = '\0';
}

/* get a line from the input, return length */
int get_line(char line[], int max_len) {
  int c, i = 0;

  while (((c = getchar()) != EOF && c != '\n') && i < max_len - 1) {
    line[i++] = c;
  }

  line[i] = '\0';
  return i;
}