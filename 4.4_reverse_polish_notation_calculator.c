/*
 * RPN Calculator (Reverse Polish Notation)
 * ----------------------------------------
 * This program is an interactive calculator that evaluates expressions written
 * in Reverse Polish Notation (postfix notation), where operators follow their
 * operands. It uses a stack to store intermediate values, allowing efficient
 * and natural expression evaluation without parentheses.
 *
 * How It Works:
 * -------------
 * - Operands (numbers) are pushed onto a value stack.
 * - When an operator (like +, -, *, /) is encountered, the appropriate number
 *   of operands are popped from the stack, the operation is applied, and the
 *   result is pushed back onto the stack.
 * - Single-letter variables A–Z can be assigned using `@A =` syntax.
 * - The most recently printed result can be recalled using `_`.
 *
 * Supported Features:
 * -------------------
 * - Arithmetic: +, -, *, /, %
 * - Math functions: sin, exp, pow
 * - Stack manipulation:
 *     - `dup`   : duplicate top of stack
 *     - `swap`  : swap top two values
 *     - `clear` : clear entire stack
 *     - `top`   : print top value without popping
 * - Variables:
 *     - Assign: `32 @A =` stores 32 in variable A
 *     - Recall: `A` pushes value of A
 * - Recent value: `_` pushes the last printed result
 *
 * Example Usage:
 * --------------
 * > 5 8 +       (pushes 5 and 8, adds them)
 * > \n          (prints result → 13)
 *
 * > 42 @X =     (stores 42 in variable X)
 * > X 2 * \n    (recalls X and multiplies by 2 → prints 84)
 *
 * > 90 sin \n   (computes sine of 90 radians)
 *
 * > _ 10 + \n   (adds 10 to the last printed result)
 *
 * Input is line-based; each expression or operator should be space-separated.
 */

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXOP 100  /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define FUNC 'f'   // signal for a math function like sin, pow

int getop(char[]);
void push(double);
double pop(void);

int getch(void);
void ungetch(int);

#define MAXVAL 100  /* maximum depth of val stack */
int sp = 0;         /* next free stack position */
double val[MAXVAL]; /* value stack */

#define VAR_COUNT 26
#define VAR 'v'
double vars[VAR_COUNT];  // For variables A–Z
double recent_val = 0.0; // Store last printed value

int main() {
  int type;
  double op2;
  char s[MAXOP];

  while ((type = getop(s)) != EOF) {
    switch (type) {
    case NUMBER:
      push(atof(s));
      break;
    case '+':
      push(pop() + pop());
      break;
    case '*':
      push(pop() * pop());
      break;
    case '-':
      op2 = pop();
      push(pop() - op2);
      break;
    case '/':
      op2 = pop();
      if (op2 != 0.0)
        push(pop() / op2);
      else
        printf("error: zero divisor\n");
      break;
    case '%':
      op2 = pop();
      if (op2 != 0.0)
        push(fmod(pop(), op2));
      else
        printf("error: zero divisor for modulus\n");
      break;
    case '_': // push most recent printed value
      push(recent_val);
      break;
    case '\n':
      recent_val = pop();
      printf("\t%.8g\n", recent_val);
      break;
    case '=': {
      double varname = pop(); // ASCII of variable
      double value = pop();   // value to assign
      if (varname >= 'A' && varname <= 'Z') {
        vars[(int)(varname - 'A')] = value;
        push(value); // optionally leave it on stack
      } else {
        printf("error: invalid variable name\n");
      }
      break;
    }
    case VAR:
      // push variable name (ASCII) for assignment
      push((double)s[0]); // s[0] is like 'A'
      break;
    case FUNC:
      if (strcmp(s, "dup") == 0) { // duplicate the stack
        if (sp == 0) {
          printf("No value in stack\n");
          break;
        }

        if (sp == MAXVAL) {
          printf("Stack full, can't duplicate\n");
          break;
        }
        val[sp] = val[sp - 1];
        sp++;
      } else if (strcmp(s, "top") == 0) { // print top of the stack
        if (sp == 0) {
          printf("Stack is empty\n");
          break;
        }
        printf("Top: %.8g\n", val[sp - 1]);
      } else if (strcmp(s, "clear") == 0) { // clear the stack
        sp = 0;
      } else if (strcmp(s, "swap") == 0) { // swap top 2 elem of stack
        if (sp < 2) {
          printf("stack don't have 2 value\n");
        } else {
          double temp = val[sp - 1];
          val[sp - 1] = val[sp - 2];
          val[sp - 2] = temp;
        }
      } else if (strcmp(s, "sin") == 0) {
        push(sin(pop()));
      } else if (strcmp(s, "exp") == 0) {
        push(exp(pop()));
      } else if (strcmp(s, "pow") == 0) {
        double op2 = pop();
        push(pow(pop(), op2));
      } else {
        printf("error: unknown function %s\n", s);
      }
      break;
    default:
      if (type >= 'A' && type <= 'Z') {
        push(vars[type - 'A']); // load variable value
      } else if (type == 'v') {
        push(recent_val); // alias for recent (optional)
      } else if (type == '_') {
        push(recent_val); // underscore for recent
      } else {
        printf("error: unknown command %s\n", s);
      }
      break;
    }
  }
  return 0;
}

/* push: push f onto value stack */
void push(double f) {
  if (sp < MAXVAL)
    val[sp++] = f;
  else
    printf("error: stack full, can't push %g\n", f);
}
/* pop: pop and return top value from stack */
double pop(void) {
  if (sp > 0)
    return val[--sp];
  else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

/* getop: get next character or numeric operand */
int getop(char s[]) {
  int i = 0, c;

  // Skip whitespace
  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';

  // Detect variable assignment (e.g., @A)
  if (c == '@') {
    int next = getch();
    if (next >= 'A' && next <= 'Z') {
      s[0] = next;
      s[1] = '\0';
      return VAR;
    } else {
      printf("error: invalid variable name after @\n");
      if (next != EOF)
        ungetch(next);
      return c;
    }
  }

  // Detect function name or variable use
  if (isalpha(c)) {
    s[i++] = c;
    int next = getch();
    if (!isalpha(next)) {
      s[i] = '\0';
      if (next != EOF)
        ungetch(next);
      return c; // single-letter command like 'A', 'B', 'v', etc.
    }
    while (i < MAXOP - 1 && isalpha(next)) {
      s[i++] = next;
      next = getch();
    }
    s[i] = '\0';
    if (next != EOF)
      ungetch(next);
    return FUNC; // multi-letter function like sin, pow, etc.
  }

  // Handle numbers and negative numbers
  if (!isdigit(c) && c != '.' && c != '-')
    return c; /* not a number */

  i = 0;
  if (c == '-') {
    int next = getch();
    if (!isdigit(next) && next != '.') {
      ungetch(next);
      return '-'; // just a minus
    }
    s[i++] = '-';
    c = next;
  }

  if (isdigit(c)) /* collect integer part */
    while (isdigit(s[++i] = c = getch()))
      ;
  if (c == '.') /* collect fraction part */
    while (isdigit(s[++i] = c = getch()))
      ;
  s[i] = '\0';
  if (c != EOF)
    ungetch(c);
  return NUMBER;
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

// why?
// Uses existing API, keeps encapsulation.
// Doesn't break abstraction or duplicate buffer logic.
// Safer, since ungetch handles buffer overflow.
void ungets(const char s[]) {
  int len = strlen(s);
  while (len > 0)
    ungetch(s[--len]);
}