/*
 * Description:
 *   This program demonstrates a simple memory allocator in C using a static
 buffer.
 *   It includes two functions:
 *     - alloc(n): allocates 'n' bytes from a fixed-size buffer.
 *     - afree(p): frees memory by moving the allocation pointer back to 'p'.
 *
 *   The main function tests these routines by allocating and freeing memory
 blocks,
 *   and printing out the results to verify correct behavior.
 *
 * Note:
 *   This is a basic stack-like (LIFO) allocator — memory must be freed in
 reverse
 *   order of allocation. No real memory management (like malloc/free) is used.
 *
 */

#include <stdio.h>

#define ALLOCSIZE 1000           /* Size of available space */
static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf;  /* next free position */

char *alloc(int n);
void afree(char *p);

int main() {
  char *p1, *p2;

  p1 = alloc(100); // allocate 100 bytes
  if (p1 == NULL) {
    printf("Not enough memory for p1\n");
    return 1;
  }

  p2 = alloc(200); // allocate 200 bytes
  if (p2 == NULL) {
    printf("Not enough memory for p2\n");
    return 1;
  }

  // Use the allocated memory (for demonstration, we'll fill it with something)
  for (int i = 0; i < 100; i++)
    p1[i] = 'A';
  p1[99] = '\0'; // Null-terminate

  printf("p1 contents: %s\n", p1);

  afree(p2); // Free second block
  afree(p1); // Free first block

  // Now we can reuse the memory
  char *p3 = alloc(300);
  if (p3)
    printf("Successfully reallocated 300 bytes\n");
  else
    printf("Failed to allocate 300 bytes\n");

  return 0;
}

char *alloc(int n) /* return pointer to n characters */
{
  if (allocbuf + ALLOCSIZE - allocp >= n) { /* it fits */
    allocp += n;
    return allocp - n; /* old p */
  } else               /* not enough room */
    return 0;
}

void afree(char *p) /* free storage pointed to by p */
{
  if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
    allocp = p;
}