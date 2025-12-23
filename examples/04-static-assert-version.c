// Combining HEDLEY_STATIC_ASSERT and version checks
#include <hedley.h>
#include <stdio.h>


HEDLEY_STATIC_ASSERT(sizeof(int) == 4,  "This code assumes 4-byte integers.");
HEDLEY_STATIC_ASSERT(sizeof(char) == 1, "This code assumes 1-byte characters.");


struct Example {
  int id;
  char name[10];
};


HEDLEY_STATIC_ASSERT(sizeof(struct Example) <= 16,
                     "Struct Example is too large.");


int main() {
  printf("All static assertions passed.\n");
  return 0;
}
