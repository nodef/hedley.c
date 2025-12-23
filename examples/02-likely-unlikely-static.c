// Combining HEDLEY_LIKELY, HEDLEY_UNLIKELY, and static assertions
#include <hedley.h>
#include <stdio.h>
#include <time.h>


HEDLEY_STATIC_ASSERT(sizeof(int) == 4, "This code assumes 4-byte integers.");


int main() {
  int x = 5;
  clock_t start, end;

  start = clock();
  for (int i = 0; i < 1000000; i++) {
    if (HEDLEY_LIKELY(x == 5)) {
      // Likely branch
    } else {
      // Unlikely branch
    }
  }
  end = clock();
  printf("Execution time with HEDLEY_LIKELY: %lf seconds\n",
         (double)(end - start) / CLOCKS_PER_SEC);

  start = clock();
  for (int i = 0; i < 1000000; i++) {
    if (x == 5) {
      // Regular branch
    } else {
      // Regular branch
    }
  }
  end = clock();
  printf("Execution time without HEDLEY_LIKELY: %lf seconds\n",
         (double)(end - start) / CLOCKS_PER_SEC);

  return 0;
}
