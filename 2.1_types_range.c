/* A program to print the size of the different data type */

#include <float.h>
#include <limits.h>
#include <stdio.h>

int main() {
  printf("Char min: %d\n", CHAR_MIN);
  printf("Char max: %d\n", CHAR_MAX);
  printf("Signed Char min: %d\n", SCHAR_MIN);
  printf("Signed Char max: %d\n", SCHAR_MAX);
  printf("Unsigned Char min: %d\n", 0);
  printf("Unsigned Char max: %d\n", UCHAR_MAX);

  printf("Int min: %d\n", INT_MIN);
  printf("Int max: %d\n", INT_MAX);
  printf("Short Int min: %d\n", SHRT_MIN);
  printf("Short Int max: %d\n", SHRT_MAX);
  printf("Unsigned Short Int min: %d\n", 0);
  printf("Unsigned Short Int max: %d\n", USHRT_MAX);
  printf("Unsigned Int min: %d\n", 0);
  printf("Unsigned Int max: %ld\n", UINT_MAX);
  printf("Long Int min: %ld\n", LONG_MIN);
  printf("Long Int max: %ld\n", LONG_MAX);
  printf("Unsigned Long Int min: %d\n", 0);
  printf("Unsigned Long Int max: %ld\n", ULONG_MAX);

  printf("Char min: %d\n", CHAR_MIN);
  printf("Char max: %d\n", CHAR_MAX);

  printf("Float min: %e\n", FLT_MIN);
  printf("Float max: %e\n", FLT_MAX);
  printf("Double min: %e\n", DBL_MIN);
  printf("Double max: %e\n", DBL_MAX);
  printf("Long double min: %Le\n", LDBL_MIN);
  printf("Long double max: %Le\n", LDBL_MAX);

  return 0;
}