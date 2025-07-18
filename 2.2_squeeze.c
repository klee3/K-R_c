/* A program to delete each character in string 1 that matches with string 2 */

#include <stdio.h>

void squeeze(char s1[], char s2[]);

int main() {
  char s1[] = "Hi How are you? I am fine";
  char s2[] = "aeiou";

  squeeze(s1, s2);
  printf("%s\n", s1);

  return 0;
}

/* delete in s1 if it matched any character in s2 */
void squeeze(char s1[], char s2[]) {
  int p = 0;
  for (int i = 0; s1[i] != '\0'; i++) {
    int is_match = 0;
    for (int j = 0; s2[j] != '\0'; j++) {
      if (s1[i] == s2[j]) {
        is_match = 1;
        break;
      }
    }
    if (!is_match) {
      s1[p++] = s1[i];
    }
  }
  s1[p] = '\0';
}
