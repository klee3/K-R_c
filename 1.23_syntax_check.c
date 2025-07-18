/* A program to check parenthases, curley, bracket, escape sequence and string
 */

#include <stddef.h>
#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int len);

int main() {
  int len;
  char line[MAXLINE];

  // For checking syntax
  int inside_comment = 0;
  int inside_string = 0;
  int i = 0;
  int parenthases = 0, curley = 0, bracket = 0;

  while ((len = get_line(line, sizeof(line))) > 0) {
    i = 0; // reset i
    while (line[i] != '\0' && i < len - 1) {
      // Skip inside block comment
      if (inside_comment) {
        if (line[i] == '*' && line[i + 1] == '/') {
          inside_comment = 0;
          i += 2;
          continue;
        } else {
          i++;
          continue;
        }
      }

      // Start block comment
      if (!inside_string && line[i] == '/' && line[i + 1] == '*') {
        inside_comment = 1;
        i += 2;
        continue;
      }
      // Skip single-line comment
      if (!inside_string && line[i] == '/' && line[i + 1] == '/') {
        break;
      }

      // Handle string
      // Handle string
      if (line[i] == '\'' || line[i] == '"') {
        if (!inside_string) {
          inside_string = line[i]; // start of string
        } else if (line[i] == inside_string) {
          int backslash_count = 0;
          int j = i - 1;
          while (j >= 0 && line[j--] == '\\')
            backslash_count++;
          if (backslash_count % 2 == 0) {
            inside_string = 0; // end of string
          }
        }
        i++;
        continue;
      }
      // Count brackets if not inside string or comment
      if (!inside_string && !inside_comment) {
        if (line[i] == '(')
          parenthases++;
        else if (line[i] == ')')
          parenthases--;
        else if (line[i] == '{')
          curley++;
        else if (line[i] == '}')
          curley--;
        else if (line[i] == '[')
          bracket++;
        else if (line[i] == ']')
          bracket--;
      }

      i++;
    }
  }

  if (parenthases != 0) {
    printf("Unequal number of parentheses\n");
    return 1;
  }
  if (curley != 0) {
    printf("Unequal number of curly braces\n");
    return 1;
  }
  if (bracket != 0) {
    printf("Unequal number of brackets\n");
    return 1;
  }
  if (inside_string != 0) {
    printf("Unclosed string or character literal\n");
    return 1;
  }

  if (inside_comment != 0) {
    printf("Unclosed comment\n");
    return 1;
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
