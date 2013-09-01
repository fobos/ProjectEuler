#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

/*
 * The following iterative sequence is defined for the set of positive integers:
 *
 * n → n/2 (n is even)
 * n → 3n + 1 (n is odd)
 *
 * Using the rule above and starting with 13, we generate the following sequence:
 *
 * 13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
 *
 * It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms.
 * Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.
 *
 * Which starting number, under one million, produces the longest chain?
 *
 * NOTE: Once the chain starts the terms are allowed to go above one million. 
 *
 * Answer: 837799
 */

int PR14[1000000] = {0};

int pr14_count_collatz_seq(int64_t n)
{
    int cnt = 0;
    while (n > 1) {
        cnt++;
        if (n % 2) { // n is odd
           n = 3 * n + 1;
        } else {
            n = n / 2;
        }
    }
    cnt++;

    return cnt;
}

int64_t problem14()
{
    int max = 0;
    int cnt;
    int64_t i, max_n = 0LL;

    for (i = 1LL; i <= 1000000LL; i++) {
        cnt = pr14_count_collatz_seq(i);
        
        if (max < cnt) {
            max = cnt;
            max_n = i;
        }
    }
    //printf("Problem14: %0*"PRIi64"\n", 15, max_n);

    return max_n;
}

    
