/* A program to fold the input line if it longer than nth column */
#include <stdio.h>

#define MAXCOLUMN 5
#define MAXLINE 1000

int get_line(char line[], int len);
void fold_line(char *input, char *output, int length, int max_col);

int main() {
  char line[MAXLINE];
  char folded[MAXLINE + 1];

  int length;
  while ((length = get_line(line, sizeof(line))) > 0) {
    fold_line(line, folded, sizeof(folded), MAXCOLUMN);
    printf("%s\n", folded);
  }
  for (int i = 0; folded[i] != '\0'; ++i) {
    printf("%d: %c\n", i, folded[i]);
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

/* Fold line with length of nth column */
void fold_line(char *input, char *output, int length, int max_col) {
  int i = 0, j = 0;
  int col = 0;
  int last_blank = -1;

  while (input[i] != '\0' && j < length - 1) {
    output[j] = input[i];

    if (input[i] == ' ' || input[i] == '\t') {
      last_blank = j; // Save the last blank position in output
    }

    col++;
    if (col >= max_col) {
      if (last_blank != -1) {
        output[last_blank] = '\n';
        col = j - last_blank;
        last_blank = -1;
      } else {
        output[j++] = '\n';
        col = 0;
        continue;
      }
    }

    i++;
    j++;
  }

  output[j] = '\0';
}
