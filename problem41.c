#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>

int is_pandigital(int64_t n)
{
    int M[10] = {0};
    int i;

    do {
        int d = n % 10;
        M[d] = 1;
    } while (n /= 10);

    for (i = 0; i < 10; i++) {
        if (!M[i]) {
            return 0;
        }
    }


    return 1;
}

int64_t problem41()
{
/*
    int64_t i = 9876543210LL;
    int64_t imin = 1023456789LL;
*/
    int64_t i = 2143LL;
    int64_t imin = 1234LL;

    for (; i >= imin; i--) {
        if (is_pandigital(i) && is_prime64(i)) {
            printf("xxx: %0*"PRIi64"\n", 15, i);
            return i;
        }
    }
}

