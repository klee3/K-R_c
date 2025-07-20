/*
 * Shell Sort Algorithm
 *
 * Shell Sort is an optimization of Insertion Sort.
 * Instead of comparing and swapping adjacent elements (as in Insertion Sort),
 * it compares elements that are far apart, using a shrinking gap sequence.
 *
 * The algorithm works by:
 * 1. Starting with a large gap (typically n/2), and reducing the gap each
 * iteration.
 * 2. For each gap, perform a "gap-based insertion sort":
 *    - Compare elements that are 'gap' positions apart.
 *    - Swap them if they are out of order.
 * 3. Repeat until the gap is reduced to 1, where a final insertion sort is
 * performed.
 *
 * This improves efficiency by moving elements closer to their correct position
 * faster, especially useful for large, unsorted arrays.
 *
 * Time Complexity (depends on gap sequence):
 * - Best case: O(n log n)
 * - Average case: O(n^1.5)
 * - Worst case: O(n^2)
 */

#include <stdio.h>

void shellsort(int v[], int n);

int main() {
  int v[] = {5, 3, 8, 6, 2};
  int n = 5;
  shellsort(v, n);

  for (int i = 0; i < n; i++) {
    printf("%d ", v[i]);
  }
  printf("\n");
  return 0;
}

/* shellsort: sort v[0]...v[n-1] into increasing order */
void shellsort(int v[], int n) {
  int gap, i, j, temp;
  for (gap = n / 2; gap > 0; gap /= 2) {
    for (i = gap; i < n; i++) {
      for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap) {
        temp = v[j];
        v[j] = v[j + gap];
        v[j + gap] = temp;
      }
    }
  }
}