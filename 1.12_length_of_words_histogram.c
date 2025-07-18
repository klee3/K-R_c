/* A program to print the histogram according to the length of the words */

#include <stdio.h>
#include <string.h>

#define IN 1
#define OUT 0

int main() {
  int c;
  int state = OUT;
  int word_len = 0;
  int word_length[10];
  memset(word_length, 0, sizeof(word_length));

  // analyze the input
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      if (state == IN) {
        state = OUT;
        if (word_len < 10) {
          ++word_length[word_len - 1];
        } else {
          ++word_length[9];
        }
      }
    } else if (state == OUT) {
      state = IN;
      word_len = 0;
    }
    if (state == IN) {
      ++word_len;
    }
  }

  // print the histogram
  for (int i = 0; i < 9; ++i) {
    if (word_length[i] == 0) {
      continue;
    }

    printf("%6d: ", i + 1);
    for (int j = 0; j < word_length[i]; ++j) {
      putchar('*');
    }
    putchar('\n');
  }

  if (word_length[9] != 0) {
    printf("%6s: %d\n", "other", word_length[9]);
  }

  return 0;
}
