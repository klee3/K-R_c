/* A program to print the histogram of the frequency of the character (only
 * lower case) */

#include <stdio.h>
#include <string.h>

int main() {
  int c_freq[26];
  memset(c_freq, 0, sizeof(c_freq));
  int c;

  while ((c = getchar()) != EOF) {
    // convert to lowercase
    if (c >= 65 && c <= 90) {
      c += 32;
    }

    if (c >= 97 && c <= 122) {
      ++c_freq[c - 'a'];
    }
  }

  // print the histogram
  for (int i = 0; i < 26; ++i) {
    if (c_freq[i] == 0) {
      continue;
    }

    printf("%c: ", 'a' + i);
    for (int j = 0; j < c_freq[i]; ++j) {
      putchar('*');
    }
    putchar('\n');
  }

  return 0;
}
