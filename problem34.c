#include <stdlib.h>
#include <stdio.h>

/*
 * 145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.
 *
 * Find the sum of all numbers which are equal to the sum of the factorial of their digits.
 *
 * Note: as 1! = 1 and 2! = 2 are not sums they are not included.
 *
 * Solving: max number which should be calc is 7*9! because 9999999 = 7 times by 9! = 2540160 which
 * also has 7 digits.
 * 
 * Answer: 40730
 */
int problem34()
{
    int sum = 0, number;
    int max = 7 * factorial(9);

    for (number = 3; number <= max; number++) {
        int tmp_num = number;
        int fact_sum = 0;
        do {
            int d = tmp_num % 10;
            fact_sum += factorial(d);
            if (fact_sum > number) {
                break;
            }
        } while (tmp_num /= 10);

        if (number == fact_sum) {
            sum += number;
        }
    }

    return sum;
}






