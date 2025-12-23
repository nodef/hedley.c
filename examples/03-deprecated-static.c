// Using HEDLEY_DEPRECATED and static assertions
#include <hedley.h>
#include <stdio.h>


HEDLEY_STATIC_ASSERT(sizeof(int) == 4, "This code assumes 4-byte integers.");


HEDLEY_DEPRECATED("Since 2025") void old_function() {
  printf("This function is deprecated.\n");
}


void new_function() { printf("This is the new and improved function.\n"); }


int main() {
#ifdef USE_OLD_FUNCTION
  old_function();
#else
  new_function();
#endif
  return 0;
}
