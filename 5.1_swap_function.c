/*
 *   This program demonstrates swapping two integer values using
 *   a function and call-by-reference (pointer) mechanism in C.
 *   The 'swap' function takes two integer pointers and exchanges
 *   their values. The main function initializes two integers,
 *   displays their values before and after swapping.
 */

#include <stdio.h>

void swap(int *a, int *b);

int main() {
  int x = 5, y = 3;

  printf("Before swap X: %d, Y; %d\n", x, y);
  swap(&x, &y);
  printf("Before swap X: %d, Y; %d\n", x, y);

  return 0;
}

// swap the value using call by reference
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}