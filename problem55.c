/*
 * If we take 47, reverse and add, 47 + 74 = 121, which is palindromic.
 *
 * Not all numbers produce palindromes so quickly. For example,
 *
 * 349 + 943 = 1292,
 * 1292 + 2921 = 4213
 * 4213 + 3124 = 7337
 * 
 * That is, 349 took three iterations to arrive at a palindrome.
 *
 * Although no one has proved it yet, it is thought that some numbers, like 196, never produce a palindrome.
 * A number that never forms a palindrome through the reverse and add process is called a Lychrel number.
 * Due to the theoretical nature of these numbers, and for the purpose of this problem, we shall assume that
 * a number is Lychrel until proven otherwise. In addition you are given that for every number below ten-thousand,
 * it will either (i) become a palindrome in less than fifty iterations, or, (ii) no one, with all the computing
 * power that exists, has managed so far to map it to a palindrome. In fact, 10677 is the first number to be
 * shown to require over fifty iterations before producing a palindrome: 4668731596684224866951378664
 * (53 iterations, 28-digits).
 * 
 * Surprisingly, there are palindromic numbers that are themselves Lychrel numbers; the first example is 4994.
 *
 * How many Lychrel numbers are there below ten-thousand?
 *
 * NOTE: Wording was modified slightly on 24 April 2007 to emphasise the theoretical nature of Lychrel numbers.
 * 
 * Answer: 249
 */

#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include <string.h>

/*
 * Add numbers represented as strings.
 *
 * @return char* Pointer on the summ
 */
char *strsum(char *s1, char *s2)
{
    s1 = strrev(strdup(s1));
    s2 = strrev(strdup(s2));

    int i;
    char *sum = (char *)calloc(29, sizeof(char));
    for (i = 0; i < 29; i++) {
        sum[i] = '0';
    }
    sum[i] = '\0';

    int mem = 0, isum = 0;
    for (i = 0; s1[i] != '\0'; i++) {
        isum = (s1[i] - '0') + (s2[i] - '0');
        isum += mem;
        sum[i] = (isum % 10) + '0';
        mem = isum / 10;
    }
    while (mem) {
        sum[i++] = (mem % 10) + '0';
        mem /= 10;
    }
    sum[i] = '\0';

    return strrev(strdup(sum));
}

/*
 *  Check is the number is Lychrel number
 */
int isLychrel(int n)
{
    int i = 0;
    char strn[29];
    char *psum;

    psum = strsum(itoa(n, strn, 10), "0000");
    for (i = 0; i < 50; i++) {
        psum = strsum(psum, strrev(strdup(psum)));
        if (strcmp(psum, strrev(strdup(psum))) == 0) {
            return 0;
        }
    }

    return 1;
}

int problem55()
{
    int i;
    int sum = 0;

    for (i = 0; i < 10000; i++) {
        if (isLychrel(i)) {
            sum++;
        }
    }

    return sum;
}
