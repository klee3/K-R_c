/* A program to convert the tab into spaces */

#include <stddef.h>
#include <stdio.h>

#define TAB_SPACES 1
#define MAX_LINE 1000

int get_line(char line[], int max_len);
void detab(char o[], char d[], int len);

int main() {
  char line[MAX_LINE];
  char detabbed_line[MAX_LINE * TAB_SPACES];

  int len;
  while ((len = get_line(line, MAX_LINE)) > 0) {
    detab(line, detabbed_line, sizeof(detabbed_line));
    printf("%s", detabbed_line);
  }
  return 0;
}

/* get a line from the input, return length */
int get_line(char line[], int max_len) {
  int c, i = 0;

  while (((c = getchar()) != EOF && c != '\n') && i < max_len - 1) {
    line[i++] = c;
  }

  if (c == '\n' && i < max_len - 1) {
    line[i++] = c;
  }

  line[i] = '\0';
  return i;
}

/* detab a line */
void detab(char input[], char output[], int out_len) {
  int i = 0, j = 0;

  while (input[i] != '\0' && j < out_len - 1) {
    if (input[i] != '\t') {
      output[j++] = input[i];
    } else {
      for (int k = 0; k < TAB_SPACES && j < out_len - 1; ++k) {
        output[j++] = ' ';
      }
    }

    ++i;
  }
  output[j] = '\0';
}