/*
 * The number 3797 has an interesting property. Being prime itself, it is possible to continuously
 * remove digits from left to right, and remain prime at each stage: 3797, 797, 97, and 7.
 * Similarly we can work from right to left: 3797, 379, 37, and 3.
 * 
 * Find the sum of the only eleven primes that are both truncatable from left to right and right to left.
 *
 * NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.
 *
 * Answer: 748317
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int isTruncatablePrime(int n, int *primes)
{
    int left, right, len;
    left = n;
    right = n;
    while ((right = right / 10)) {
        len = (int)log10(left);
        left = left % ((int)powf(10, len));
        
        if (!primes[right] || !primes[left]) {
            return 0;
        }
    }

    return 1;
}

int problem37()
{
    int i, sum = 0;
    int *primes;
    int cnt = 0;

    primes = athkin_sieve(750000);

    for (i = 11; i <= 750000; i++) {
        if (primes[i] && isTruncatablePrime(i, primes)) {
            sum += i;
            cnt++;
            if (cnt == 11) {
                return sum;
            }
        }
    }

    printf("CNT: %d", cnt);

    return 0;
}
