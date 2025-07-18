/* A program to remove comment from c file */

#include <stddef.h>
#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int len);
void remove_comment(char *input, char *output, size_t len);

int main() {
  size_t len;
  char line[MAXLINE];
  char removed_comment[MAXLINE];

  while ((len = get_line(line, sizeof(line))) > 0) {
    remove_comment(line, removed_comment, sizeof(removed_comment));
    printf("%s", removed_comment);
  }

  return 0;
}

/* get a line, return length */
int get_line(char line[], int len) {
  int i = 0, c;
  while ((c = getchar()) != EOF && c != '\n' && i < len - 1) {
    line[i++] = c;
  }

  if (c == '\n' && i < len - 1) {
    line[i++] = c;
  }
  line[i] = '\0';

  return i;
}

/* remove comments from a line */
void remove_comment(char *input, char *output, size_t len) {
  static int inside_comment = 0;
  int i = 0, j = 0;
  int inside_string = 0;

  while (input[i] != '\0' && j < len - 1) {
    // Handle string or char literals
    if (!inside_comment && input[i] == '"' || input[i] == '\'') {
      output[j++] = input[i];
      if (!inside_string)
        inside_string = input[i]; // Remember whether we're in " or '
      else if (inside_string == input[i] && input[i - 1] != '\\')
        inside_string = 0;
      i++;
      continue;
    }

    // Skip // single-line comments
    if (!inside_comment && !inside_string && input[i] == '/' &&
        input[i + 1] == '/') {
      break; // ignore rest of line
    }

    if (!inside_string && !inside_comment && input[i] == '/' &&
        input[i + 1] == '*') {
      inside_comment = 1;
      i += 2;
      continue;
    }

    if (!inside_string && inside_comment && input[i] == '*' &&
        input[i + 1] == '/') {
      inside_comment = 0;
      i += 2;
      continue;
    }

    if (!inside_comment) {
      output[j++] = input[i];
    }
    i++;
  }

  output[j] = '\0';
}
