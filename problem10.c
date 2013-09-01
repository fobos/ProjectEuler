#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>

/*
 * The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 *
 * Find the sum of all the primes below two million.
 *
 * Answer: 142913828922
 */

int64_t problem10()
{
    int *primes;
    int i;
    int64_t sum = 0LL;
    
    primes = athkin_sieve(2000000);

    for (i = 2; i <= 2000000; i++) {
        if (primes[i]) {
           sum += i;
        }
    }

    return sum;
}
