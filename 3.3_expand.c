/*
 * Exercise 3-3: expand(s1, s2)
 *
 * This program defines a function expand(s1, s2) that takes a string s1
 * containing shorthand character ranges (like "a-z", "0-9", or "A-Z") and
 * expands them into the full list of characters in s2 (like
 * "abcdefghijklmnopqrstuvwxyz0123456789").
 *
 * Features:
 * - Expands lowercase, uppercase letters, and digit ranges (e.g., a-z, A-Z,
 * 0-9).
 * - Handles multiple ranges in the same string (e.g., a-d0-3).
 * - Ignores invalid or reverse ranges (e.g., z-a, 9-0) and treats them
 * literally.
 * - Leading or trailing '-' characters are treated as literal hyphens, not
 * ranges.
 * - Mixed or overlapping ranges are also supported (e.g., a-b-c becomes abc).
 *
 * Assumptions:
 * - s2 must be large enough to hold the expanded result.
 * - No dynamic memory allocation is used.
 *
 * Example:
 *   Input:  s1 = "-a-d0-3-"
 *   Output: s2 = "-abcd0123-"
 */

#include <ctype.h>
#include <stdio.h>

void expand(const char *s1, char *s2);

int main() {
  char s2[200];

  expand("a-d", s2);
  printf("expand(\"a-d\") = %s\n", s2); // Output: abcd

  expand("a-z0-9", s2);
  printf("expand(\"a-z0-9\") = %s\n",
         s2); // Output: abcdefghijklmnopqrstuvwxyz0123456789

  expand("-a-c-", s2);
  printf("expand(\"-a-c-\") = %s\n", s2); // Output: -abc-

  expand("z-a", s2);
  printf("expand(\"z-a\") = %s\n",
         s2); // Output: z-a (invalid range, taken literally)

  return 0;
}

void expand(const char *s1, char *s2) {
  int i = 0, j = 0;
  int c;

  while (s1[i] != '\0') {
    if ((i == 0 || s1[i + 1] == '\0') && s1[i] == '-') {
      s2[j++] = s1[i++];
      continue;
    }

    if (s1[i] != '-') {
      c = s2[j++] = s1[i++];
    } else if (((isdigit(c) && isdigit(s1[i + 1])) ||
                (islower(c) && islower(s1[i + 1])) ||
                (isupper(c) && isupper(s1[i + 1]))) &&
               c < s1[i + 1]) {
      // Valid range, expand from c+1 to s1[i+1]
      char end = s1[i + 1];
      while (++c <= end) {
        s2[j++] = c;
      }
      // Skip over the end of the range
      i += 2;
    } else {
      // Invalid range or decreasing order, treat '-' literally
      s2[j++] = s1[i++];
    }
  }

  s2[j] = '\0'; // null-terminate result string
}