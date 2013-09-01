#include <stdio.h>
#include <stdlib.h>

/*
 * If we list all the natural numbers below 10 that are multiples of 3 or 5,
 * we get 3, 5, 6 and 9. The sum of these multiples is 23.
 *
 * Find the sum of all the multiples of 3 or 5 below 1000.
 *
 * Answer: 233168
 */
int problem1(int limit)
{
    int i, sum = 0, k = 0;
    int mass[2000];

    // For each of nat num that lower than limit
    for (i = 1; i < limit; i++) {
        // Check the task rule: multiples 3 or 5
        if ((i % 3) == 0 || (i % 5) == 0) {
            mass[k] = i; // save the numbers
            mass[++k] = -1; // set the end of sequence
        }
    }

    // Count sum of finded numbers
    for (i = 0; mass[i] != -1; i++) {
        sum += mass[i];
    }

    return sum;
}
