/* A program to print the longest line */

#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int max_len);
void copy_line(char from[], char to[]);

int main() {
  int current_line_len = 0;
  int max_line_len = 0;
  char current_line[MAXLINE];
  char max_line[MAXLINE];

  while ((current_line_len = get_line(current_line, MAXLINE)) > 0) {
    if (current_line_len > max_line_len) {
      max_line_len = current_line_len;
      copy_line(current_line, max_line);
    }
  }
  if (max_line_len > 0) {
    printf("Longest line length: %d\n", max_line_len);
    printf("Line: %s\n", max_line);
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

/* copy_line: copy line "from" to 'to' */
void copy_line(char from[], char to[]) {
  for (int i = 0; (to[i] = from[i]) != '\0'; ++i) {
  }
}
