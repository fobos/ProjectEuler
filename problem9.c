#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/*
 * A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
 * a^(2) + b^(2) = c^(2)
 *
 * For example, 3^(2) + 4^(2) = 9 + 16 = 25 = 5^(2).
 *
 * There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 *
 * Find the product abc.
 *
 * Answer: 31875000 (a= 200; b= 375; c= 425;)
 */
int problem9()
{
    int a, b, c;
    int n = 1000;

    for (a = 1; a <= (n - 3) / 3 ; a++) {
        for (b = a + 1; b < (n - a) / 2 ; b++) {
            c = n - a - b;
            if (c*c == a*a + b*b) {
                return a*b*c;
            }
        }
    }
    
    return -1;
}
