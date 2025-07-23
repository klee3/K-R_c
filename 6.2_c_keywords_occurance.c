/*
 * Keyword Counter in C Source Code
 * --------------------------------
 * This program reads C source code from standard input and counts the
 * occurrences of each C keyword defined in the `keytab` table.
 *
 * It correctly ignores keywords that appear inside:
 *   - string literals ("...")
 *   - comments (both mulit line and single line )
 *   - preprocessor control lines (#include, #define, etc.)
 *
 * It also supports identifiers that begin with underscores (e.g., _var).
 *
 */

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAXWORD 100

struct key {
  char *word;
  int count;
};

int getword(char *, int);
int binsearch(char *, struct key *, int);

struct key keytab[] = {
    {"auto", 0},     {"break", 0},    {"case", 0},     {"char", 0},
    {"const", 0},    {"continue", 0}, {"default", 0},  {"do", 0},
    {"double", 0},   {"else", 0},     {"enum", 0},     {"extern", 0},
    {"float", 0},    {"for", 0},      {"goto", 0},     {"if", 0},
    {"int", 0},      {"long", 0},     {"register", 0}, {"return", 0},
    {"short", 0},    {"signed", 0},   {"sizeof", 0},   {"static", 0},
    {"struct", 0},   {"switch", 0},   {"typedef", 0},  {"union", 0},
    {"unsigned", 0}, {"void", 0},     {"volatile", 0}, {"while", 0},
};

#define NKEYS (sizeof keytab / sizeof(keytab[0]))

static int inside_comment = 0;
static int inside_string = 0;

/* count C keywords */
int main() {
  int n;
  char word[MAXWORD];

  while (getword(word, MAXWORD) != EOF)
    if (isalpha(word[0]))
      if ((n = binsearch(word, keytab, NKEYS)) >= 0)
        keytab[n].count++;
  for (n = 0; n < NKEYS; n++)
    if (keytab[n].count > 0)
      printf("%4d %s\n", keytab[n].count, keytab[n].word);
  return 0;
}

/* binsearch: find word in tab[0]...tab[n-1] */
int binsearch(char *word, struct key tab[], int n) {
  int cond;
  int low, high, mid;
  low = 0;
  high = n - 1;
  while (low <= high) {
    mid = (low + high) / 2;
    if ((cond = strcmp(word, tab[mid].word)) < 0)
      high = mid - 1;
    else if (cond > 0)
      low = mid + 1;
    else
      return mid;
  }
  return -1;
}

/* getword: get next word or character from input */
int getword(char *word, int lim) {
  int getch(void);
  void ungetch(int);

  int c;
  int word_start = 0;
  char *w = word;

  while ((c = getch()) != EOF) {
    // Handle multi-line comments
    if (inside_comment) {
      if (c == '*') {
        int next = getch();
        if (next == '/') {
          inside_comment = 0; // comment ends
        } else {
          ungetch(next); // not end yet
        }
      }
      continue; // skip everything inside comment
    }

    // Start of multi-line comment
    if (c == '/') {
      int next = getch();
      if (next == '*') {
        inside_comment = 1;
        continue; // skip comment start
      } else if (next == '/') {
        // single-line comment
        while ((c = getch()) != '\n' && c != EOF)
          ;
        continue;
      } else {
        ungetch(next); // not a comment
      }
    }

    // Handle string literals
    if (inside_string) {
      *w++ = c;
      if (c == '\\') {
        *w++ = getch(); // escape character
        continue;
      }
      if (c == '"') {
        inside_string = 0; // string ends
        *w = '\0';
        return word[0];
      }
      if (--lim <= 0)
        break;
      continue;
    }

    if (c == '"') {
      inside_string = 1;
      *w++ = c;
      continue;
    }

    // Handle preprocessor lines
    if (c == '#') {
      while ((c = getch()) != '\n' && c != EOF)
        ;
      continue;
    }

    // Skip whitespace and non-word-start characters
    if (!isalpha(c) && c != '_')
      continue;

    // Start building a word
    *w++ = c;
    for (; --lim > 0; w++) {
      c = getch();
      if (!isalnum(c) && c != '_') {
        ungetch(c); // put back punctuation like ';', ')', etc.
        break;
      }
      *w = c;
    }

    *w = '\0';
    return word[0];
  }

  return EOF;
}

#define BUFSIZE 100
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0;      /* next free position in buf */
int getch(void)    /* get a (possibly pushed-back) character */
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c) /* push character back on input */
{
  if (c == EOF) {
    printf("ungetch: cannot push back EOF\n");
    return;
  }
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}
// break break break break break break break break break break break break break
// break break break