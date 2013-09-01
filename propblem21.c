/*
 * Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
 *
 * If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called
 * amicable numbers.
 *
 * For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284.
 * The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.
 *
 * Evaluate the sum of all the amicable numbers under 10000.
 *
 * Answer: 31626
 */
#include <stdlib.h>
#include <stdio.h>

int sumDivisors(int n)
{
    int i, sum = 0;
    int x = n/2;
    for (i = 1; i <= x; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }

    return sum;
}

int checkAmicable(int n)
{
    int a;

    a = sumDivisors(n);

    if (sumDivisors(a) == n) {
        return a;
    }

    return 0;
}


int problem21()
{
    int i, sum = 0, a;
    int isAmicable[10000];
    for (i = 0; i < 10000; i++) {
        isAmicable[i] = 0;
    }

    for (i = 1; i < 10000; i++) {
        if (isAmicable[i]) {
            continue;
        }

        if ((a = checkAmicable(i))) {
            if (i != a && a < 10000) {
                sum += i + a;
            }
            
            isAmicable[i] = 1;
            isAmicable[a] = 1;
        }
    }

    return sum;
}

