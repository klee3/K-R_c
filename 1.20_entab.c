/* A program to replace tab with space */

#include <inttypes.h>
#include <stdio.h>

#define TAB_SPACES 4
#define MAX_LINE 1000

int get_line(char line[], int max_len);
void entab(char input[], char output[], int length);

int main() {
  char line[MAX_LINE];
  char entabbed[MAX_LINE];

  int length;
  while ((length = get_line(line, sizeof(line))) > 0) {
    entab(line, entabbed, sizeof(entabbed));
    printf("%s\n", entabbed);
  }
  return 0;
}

/* get a line from the input, return length */
int get_line(char line[], int max_len) {
  int c, i = 0;

  while ((c = getchar()) != EOF && c != '\n' && i < max_len - 1) {
    line[i++] = c;
  }

  line[i] = '\0';
  return i;
}

/* entab a line */
void entab(char input[], char output[], int length) {
  int i = 0, j = 0;

  while (input[i] != '\0' && i < length - 1) {
    if (input[i] != ' ') {
      output[j++] = input[i++];
    } else {
      int space_count = 0;
      // Count consecutive spaces
      while (input[i + space_count] == ' ') {
        space_count++;
      }

      // Insert as many tabs as possible
      int tabs = space_count / TAB_SPACES;
      int leftover_spaces = space_count % TAB_SPACES;

      for (int t = 0; t < tabs && j < length - 1; ++t) {
        output[j++] = '\t';
      }

      for (int s = 0; s < leftover_spaces && j < length - 1; ++s) {
        output[j++] = ' ';
      }

      i += space_count; // skip those spaces in input
    }
  }

  output[j] = '\0';
}