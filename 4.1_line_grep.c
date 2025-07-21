/*
 * This program reads lines of input from standard input and prints any line
 * that contains a specified pattern. The search pattern is defined in the
 * global variable `pattern`.
 *
 * In this example, the pattern being searched is "ould". Any line that contains
 * this substring will be printed to the standard output.
 *
 * Functions:
 * - get_line: Reads a line from input and returns its length.
 * - strindex: Returns the position of the first occurrence of the pattern in a
 *             string, or -1 if the pattern is not found.
 */

#include <stdio.h>

#define MAXLINE 1000

int get_line(char *line, int len);
int strindex(char *s, char *t);

char pattern[] = "ould";

int main() {
  char line[MAXLINE];
  [[maybe_unused]] int len;
  int found = 0;

  while ((len = get_line(line, MAXLINE)) > 0) {
    if (strindex(line, pattern) >= 0) {
      printf("%s", line);
      found++;
    }
  }

  return found;
}

/* get the line, return length */
int get_line(char *s, int lim) {
  int c = 0, i;
  i = 0;
  while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    s[i++] = c;
  if (c == '\n')
    s[i++] = c;
  s[i] = '\0';
  return i;
}

/* strindex: return index of t in s, -1 if none */
int strindex(char *s, char *t) {
  int i, k, j;
  for (i = 0; s[i] != '\0'; i++) {
    for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++) {
    }
    if (k > 0 && t[k] == '\0') {
      return i;
    }
  }
  return -1;
}
