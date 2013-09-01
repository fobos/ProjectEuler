#include <stdio.h>
#include <stdlib.h>

/*
 * 2520 is the smallest number that can be divided by each of the numbers from 
 * 1 to 10 without any remainder.
 *
 * What is the smallest positive number that is evenly divisible by all of the
 * numbers from 1 to 20?
 *
 * Answer: 232792560
 */
int problem5()
{
    int num, d;
    int df; // Devisible flag
    for (num = 1; ; num++) {
        df = 1; // Current num is divisible
        for (d = 2; d <= 20; d++) {
            if (num % d != 0) {
                df = 0; // Reset the flag
                break;
            }
        }

        if (df) {
            return num;
        }
    }
}
