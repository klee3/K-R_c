/* A program to do binary search */

/* USE THIS TO COMPILE PROGRAM */
/* gcc -o app 3.1_binary_search.c -O2 -fopenmp */

/*
 * Performance Comparison Report: Original vs Modified Binary Search
 *
 * Summary:
 * -----------
 * The modified binary search algorithm reduces the number of conditional checks
 * inside the loop by using a single test instead of two, theoretically
 * improving efficiency. However, benchmark results show that the modified
 * version runs slightly slower than the original.
 *
 * Observed Results:
 * -----------------
 * Original Parallel runtime: ~31.8 seconds
 * Modified Parallel runtime: ~34.0 seconds
 *
 * Analysis:
 * ----------
 * 1. Branch Prediction:
 *    - The original binary search uses multiple conditional branches which
 * modern CPUs can predict accurately due to predictable data patterns.
 *    - The modified version defers the equality check to after the loop, which
 * might lead to less predictable branching and more mispredictions, causing CPU
 * pipeline stalls.
 *
 * 2. Extra Comparison After Loop:
 *    - The modified search performs an additional equality check outside the
 * loop, introducing extra instructions that accumulate over billions of
 * iterations.
 *
 * 3. Compiler Optimization:
 *    - Compilers can optimize the original loop more aggressively due to
 * straightforward control flow.
 *    - The modified version’s control flow might prevent some optimizations.
 *
 * 4. Cache and Memory Behavior:
 *    - Differences in memory access patterns and cache utilization can impact
 * performance.
 *    - The slight difference in code logic might cause subtle cache misses
 * affecting timing.
 *
 * Conclusion:
 * ------------
 * While fewer comparisons inside a loop might intuitively seem faster,
 * actual performance depends on CPU architecture, branch prediction,
 * compiler optimizations, and memory access patterns.
 *
 * This experiment highlights the complexity of performance tuning:
 * Optimizing for fewer instructions doesn't always translate into better
 * runtime.
 *
 * Recommendations:
 * -----------------
 * - Use compiler optimization flags (e.g., -O3 or -Ofast) when benchmarking.
 * - Run multiple trials and average results for more reliable data.
 * - Profile with tools like `perf` or `valgrind` to understand CPU and memory
 * behavior.
 * - Consider parallelization to fully utilize CPU cores for heavy workloads.
 */

#include <omp.h>
#include <stdio.h>

int binsearch(int x, int v[], int n);
int binsearch_single_test(int x, int v[], int n);

#define SIZE 1000000

int main() {
  int v[SIZE];
  for (int i = 0; i < SIZE; i++)
    v[i] = i * 2; // Sorted array

  int x = 123456; // Value to search

  double start = omp_get_wtime();

#pragma omp parallel for
  for (int i = 0; i < 100000; i++)
    for (int j = 0; j < 100000; j++)
      binsearch(x, v, SIZE);

  double end = omp_get_wtime();
  printf("Original Parallel runtime: %f seconds\n", end - start);

  start = omp_get_wtime();

#pragma omp parallel for
  for (int i = 0; i < 100000; i++)
    for (int j = 0; j < 100000; j++)
      binsearch_single_test(x, v, SIZE);

  end = omp_get_wtime();
  printf("Modified Parallel runtime: %f seconds\n", end - start);

  return 0;
}

/* binsearch: find x in a array of a number */
int binsearch(int x, int v[], int n) {
  int low = 0, high = n - 1, mid;
  while (low <= high) {
    mid = (low + high) / 2;
    if (x < v[mid]) {
      high = mid - 1;
    } else if (x > v[mid]) {
      low = mid + 1;
    } else {
      return mid;
    }
  }

  return -1; /* No match */
}

/* binsearch: find x in a array of a number */
int binsearch_single_test(int x, int v[], int n) {
  int low = 0, high = n - 1, mid;
  while (low <= high) {
    mid = (low + high) / 2;
    if (x <= v[mid]) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  if (low < n && v[low] == x)
    return low;
  else
    return -1;
}