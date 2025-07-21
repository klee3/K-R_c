/*
 * This program reads lines of text from standard input and prints those
 * that contain a specified substring (pattern). It uses a custom function
 * to find the position of the rightmost occurrence of the pattern in each line.
 * If the pattern is found anywhere in a line, the entire line is printed.
 *
 * This mimics a simplified version of the Unix `grep` command, but instead of
 * finding the first match, it searches for the last (rightmost) match.
 */

#include <stdio.h>

#define MAXLINE 1000
char pattern[] = "ould";

int get_line(char *s, int lim);
int rightmost_strindex(char *s, char *t);

int main() {
  char line[MAXLINE];
  [[maybe_unused]] int len;
  int found = 0;
  int index;

  while ((len = get_line(line, MAXLINE)) > 0) {
    if ((index = rightmost_strindex(line, pattern)) >= 0) {
      printf("Found on %d\n", index);
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

/* strindex: return rightmost index of t in s, -1 if none */
int rightmost_strindex(char *s, char *t) {
  int i, j, k;
  int rightmost = -1;
  for (i = 0; s[i] != '\0'; i++) {
    for (k = 0, j = i; t[k] != '\0' && s[j] == t[k]; ++k, ++j) {
    }
    if (k > 0 && t[k] == '\0') {
      rightmost = i;
    }
  }

  return rightmost;
}
