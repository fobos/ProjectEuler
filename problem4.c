#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * A palindromic number reads the same both ways.
 * The largest palindrome made from the product of two 2-digit numbers is
 * 9009 = 91 × 99.
 * 
 * Find the largest palindrome made from the product of two 3-digit numbers.
 *
 * Answer: 906609
 */
int problem4()
{
    int a, b;
    int c;
    int max = 0;
    char s[7], ss[7];
    int x;

    for (a = 100; a < 1000; a++) {
        for (b = 100; b < 1000; b++) {
            c = a * b;
            itoa(c, s, 10);
            strcpy(ss, s);
            x = strcmp(s, strrev(ss));
            if (x == 0 && c > max) {
                max = c;
            }
        }
    }

    return max;
}
