/* A program to find the first word of s1 where any character from the string s2
 * occurs */

#include <stdio.h>

int any(char *s1, char *s2);

int main() {
  char s1[] = "Hello welcome to wonderland";
  char s2[] = "dystopia";

  int index = any(s1, s2);
  if (index >= 0) {
    printf("found at %d\n", index);
  } else {
    printf("Not found");
  }
  return 0;
}

/* return the index of s1 where any character from s2 occur */
int any(char *s1, char *s2) {
  for (int i = 0; s1[i] != '\0'; i++) {
    for (int j = 0; s2[j] != '\0'; j++) {
      if (s1[i] == s2[j])
        return i;
    }
  };
  return -1;
}