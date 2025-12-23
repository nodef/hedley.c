// Basic usage of Hedley macros
#include <hedley.h>
#include <stdio.h>


HEDLEY_STATIC_ASSERT(sizeof(int) == 4, "This code assumes 4-byte integers.");


void feature_function() { printf("Feature function executed.\n"); }


int main() {
#ifdef HEDLEY_VERSION
    int major    = HEDLEY_VERSION_DECODE_MAJOR(HEDLEY_VERSION);
    int minor    = HEDLEY_VERSION_DECODE_MINOR(HEDLEY_VERSION);
    int revision = HEDLEY_VERSION_DECODE_REVISION(HEDLEY_VERSION);
    printf("Hedley version: %d.%d.%d\n", major, minor, revision);

    #if HEDLEY_VERSION_MAJOR >= 1
        feature_function();
    #else
        printf("Feature not supported in this version.\n");
    #endif
#else
    printf("Hedley is not defined.\n");
#endif

    int x = 5;
    if (HEDLEY_LIKELY(x == 5)) {
        printf("Likely branch executed.\n");
    } else {
        printf("Unlikely branch executed.\n");
    }

    return 0;
}
