/* A program to print line which is greater than or equal to 80 line */

#include <stdio.h>

#define LINE_LIMIT 1000
#define SHOW_ON 80

int get_line(char line[], int max_len);

int main() {
  char line[LINE_LIMIT];
  int len = 0;

  while ((len = get_line(line, LINE_LIMIT)) > 0) {
    if (len >= SHOW_ON) {
      printf("%s", line);
    }
  }

  return 0;
}

/* getline: read a line into s, return length */
int get_line(char line[], int max_len) {
  int c, i;
  c = i = 0;

  while ((c = getchar()) != EOF && c != '\n') {
    if (i < max_len - 1) {
      line[i] = c;
    }
    i++;
  }
  if (c == '\n') {
    if (i < max_len - 1)
      line[i] = c;
    else
      ++i;
  }
  if (i < max_len)
    line[i] = '\0';
  else
    line[max_len - 1] = '\0';
  return i;
}
