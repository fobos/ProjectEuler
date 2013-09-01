/*
 *By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
 *
 * What is the 10001st prime number?
 *
 * Answer: 104743
 */
#include <stdio.h>
#include <stdlib.h>

int problem7()
{
    int sz = 20000;
    int *primes;
    int i, cnt;

    for (;; sz = sz + 200) {
        primes = athkin_sieve(sz);
        cnt = 0;
        for (i = 2; i <= sz; i++) {
            if (primes[i]) {
                cnt++;
                if (cnt == 10001) {
                    return i;
                }
            }
        }
    }
}
