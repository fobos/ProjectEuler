#include <stdlib.h>
#include <stdio.h>

/*
 * The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.
 *
 * There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.
 *
 * How many circular primes are there below one million?
 *
 * Answer: 55
 */

/*
 * Rotates word to the left
 */
void rotate_word_left(char *s)
{
    int i, len = strlen(s);
    
    for (i = 0; i <= len - 2; i++) {
        char c = s[i];
        s[i] = s[i+1];
        s[i+1] = c;
    }
}

/*
 * Check is the number is circular prime
 */
int is_circular_prime(int n)
{
    char s[7];
    int i, len, num;

    itoa(n, s, 10);

    len = strlen(s);

    // Check all number rotations
    for (i = 0; i < len - 1; i++) {
        rotate_word_left(s);
        num = atoi(s);
        if (!is_prime(num)) {
            return 0;
        }
    }

    return 1;
}

int problem35()
{
    const int PRIMES_SIZE = 1000000;
    int cnt = 0;
    int *primes;
    int i;

    primes = athkin_sieve(PRIMES_SIZE);

    for (i = 2; i <= PRIMES_SIZE; i++) {
        if (primes[i] && is_circular_prime(i)) {
            cnt++;
        }
    }

    return cnt;
}
