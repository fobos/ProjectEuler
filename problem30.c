#include<stdlib.h>
#include<stdio.h>
#include <math.h>


/*
 * Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:
 *
 * 1634 = 1^(4) + 6^(4) + 3^(4) + 4^(4)
 * 8208 = 8^(4) + 2^(4) + 0^(4) + 8^(4)
 * 9474 = 9^(4) + 4^(4) + 7^(4) + 4^(4)
 *
 * As 1 = 1^(4) is not a sum it is not included.
 * The sum of these numbers is 1634 + 8208 + 9474 = 19316.
 * 
 * Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.
 *
 * Solving and numbers calculation:
 *
 * 9^(5) = 59049
 *
 * It meanse that 6-digit numbers which contains only 9 numbers will produce
 * max power: 354294. I mean that thix '9' digits will produs max 6-digit numer 354294.
 * And it means that this number is max number which should be checked. Numbers bigger this num
 * we can not produce by powering. (Ugly eplanation)
 * 
 * Answer: 443839
 */
int problem30()
{
    int i, j = 0;
    int sum = 0;

    for (i = 100; i <= 354294; i++) {
        double x;
        int a = i % 10;
        int b = ((int)(i/10)) % 10;
        int c = ((int)(i/100)) % 10;

        int d = 0, f = 0, g = 0;
        
        if (i > 999) {
            d = ((int)(i/1000)) % 10;
        }
        if (i > 9999) {
            f = ((int)(i/10000)) % 10;
        }
        if (i > 99999) {
            g = ((int)(i/100000)) % 10;
        }

        x = pow(a, 5);
        x += pow(b, 5);
        x += pow(c, 5);
        if (i > 999) {
            x += pow(d, 5);
        }
        if (i > 9999) {
            x += pow(f, 5);
        }
        if (i > 99999) {
            x += pow(g, 5);
        }

        if (x == i) {
            sum += x;
        }
    }

    return sum;
}

