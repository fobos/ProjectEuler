/*
 * If p is the perimeter of a right angle triangle with integral length sides, {a,b,c}, there are exactly
 * three solutions for p = 120.
 * 
 * {20,48,52}, {24,45,51}, {30,40,50}
 *
 * For which value of p ≤ 1000, is the number of solutions maximised?
 *
 * Answer: 840
 */

#include <stdlib.h>
#include <stdio.h>

int problem39()
{
    int a, pcnt, pcntmax = 0, c1, c2, p, pmax = 0, c, b;

    for (p = 3; p <= 1000; p++) {
        a = 1;
        pcnt = 0;
        while (a < p) {
            c1 = 2*a*p - p*p;
            c2 = 2*a - 2*p;

            if (c1 % c2 == 0 && c1/c2 > 0) {
                c = c1/c2;
                b = p - a - c;
                if (b > 0) {
                    pcnt++;
                }
            }

            if (pcntmax < pcnt) {
                pcntmax = pcnt;
                pmax = p;
            }

            a++;
        }
    }
    
    return pmax;
    
}
