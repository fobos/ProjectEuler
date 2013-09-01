/*
 * The decimal number, 585 = 1001001001_(2) (binary), is palindromic in both bases.
 *
 * Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.
 *
 * (Please note that the palindromic number, in either base, may not include leading zeros.)
 *
 * Answer: 872187
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int problem36()
{
    int num, sum = 0;
    char s10[7];
    char s2[21];

    for (num = 1; num < 1000000 ; num++) {
        itoa(num, s10, 10);

        // Check only odd palindroms (odd because only odd contains 1 on right side)
        if (num % 2 != 0 && strcmp(s10, strrev(strdup(s10))) == 0) {
            itoa(num, s2, 2);

            if (strcmp(s2, strrev(strdup(s2))) == 0) {
                sum += num;
            }
        }
    }
    
    return sum;
}
