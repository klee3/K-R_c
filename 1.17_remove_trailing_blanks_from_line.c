/* A program to remove trailing blank spaces from line */

#include <stdio.h>

#define LINE_LIMIT 1000

int get_line(char line[], int max_len);

int main() {
  int line_len = 0;
  char line[LINE_LIMIT];

  while ((line_len = get_line(line, LINE_LIMIT)) > 0) {
    printf("%s", line);
  }

  return 0;
}

/* getline: read a line into s removing trailing spaces and blank line, return
 * length */
int get_line(char line[], int max_len) {
  int c, i;
  int start_reading = 0;
  c = i = 0;

  while ((c = getchar()) != EOF && c != '\n') {

    if (!start_reading && (c == ' ' || c == '\t')) {
      continue;
    }

    start_reading = 1;

    if (i < max_len - 1) {
      line[i++] = c;
    }
  }

  // Remove trailng spaces
  while (i > 0 && (line[i - 1] == ' ' || line[i - 1] == '\t')) {
    --i;
  }

  if (c == '\n' && i < max_len - 1) {
    line[i++] = c;
  }
  line[i] = '\0';
  return i;
}
