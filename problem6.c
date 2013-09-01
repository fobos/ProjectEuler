#include <stdio.h>
#include <stdlib.h>

/*
 * The sum of the squares of the first ten natural numbers is,
 * 1^(2) + 2^(2) + ... + 10^(2) = 385
 *
 * The square of the sum of the first ten natural numbers is,
 * (1 + 2 + ... + 10)^(2) = 55^(2) = 3025
 *
 * Hence the difference between the sum of the squares of the first ten natural
 * numbers and the square of the sum is 3025 − 385 = 2640.
 *
 * Find the difference between the sum of the squares of the first one hundred
 * natural numbers and the square of the sum.
 *
 * Answer: 25164150
 */
int problem6()
{
    int s = 1, f = 100;
    int sum = 0, sum2 = 0;
    int i,j;

    // Calc the sum of sequence numbers 1*2 + 1*3 + 1*4 + ...
    for (i = s + 1; i <= f; i++) {
        sum += i;
    }
    sum = 2 * sum; // There are 2 sequence of numbers 1*2 + 1*3 + 1*4 + ...

    // Calc the sum of 2*3 + 3*4 + 2*5 + 3*4 + 3*5 + 4*5 + ...
    for (i = s + 1; i <= f - 1; i++) {
        for (j = i + 1; j <= f; j++ ) {
            sum2 += i*j;
        }
    }

    // Calc the result difference
    sum = sum + 2 * sum2;

    return sum;
}
