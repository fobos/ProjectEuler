#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

/*
 *
 * Answer: 6857
 */
int64_t problem3()
{
    int64_t prime = 0LL;
    int64_t num = 600851475143LL;
    int64_t i, rf; // left and right factor ld * rd = num

    for (i = 2LL; i <= num / 2LL;) {
        if (num % i == 0) {
            rf = num / i;
            printf("i: %0*"PRIi64"  ", 15, i);
            printf("rf: %0*"PRIi64"\n", 15, rf);

            if (is_prime64(rf)) {
                prime = rf;
                return prime;
            }
        }
        
        // Just check only numbers which ended on 1,3,7,9
        switch(i % 10) {
            case 1:
            case 7:
            case 9:
                i += 2;
                break;
            case 3:
                i += 4;
                break;
        }
    }

    return -1LL;
}
