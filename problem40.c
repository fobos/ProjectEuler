#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
 * An irrational decimal fraction is created by concatenating the positive integers:
 *
 * 0.123456789101112131415161718192021...
 *
 * It can be seen that the 12^(th) digit of the fractional part is 1.
 *
 * If d_(n) represents the n^(th) digit of the fractional part, find the value of the following expression.
 *
 * d1 × d10 × d100 × d1000 × d10000 × d100000 × d1000000
 *
 * Answer: 210
 */
int problem40()
{

    int res;

    res = digit_in_pos(1) *
          digit_in_pos(10) *
          digit_in_pos(100) *
          digit_in_pos(1000) *
          digit_in_pos(10000) *
          digit_in_pos(100000) *
          digit_in_pos(1000000);

    return res;

}

int digit_in_pos(int pos)
{
    char str[7];
    int num;
    int ipos;
    char dig;

    ipos = 0; num = 0;
    while (ipos <= pos) {
        itoa(num, str, 10);


        int i;
        for (i = 0; str[i] != '\0' && ipos <= pos; i++, ipos++) {
            dig = str[i];
        }

        num++;
    }

    return dig - '0';
}
