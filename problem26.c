/*
 * A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators
 * 2 to 10 are given:
    1/2	 = 0.5
    1/3	 = 0.(3)
    1/4	 = 0.25
    1/5	 = 0.2
    1/6	 = 0.1(6)
    1/7	 = 0.(142857)
    1/8	 = 0.125
    1/9	 = 0.(1)
    1/10 = 0.1
 *
 * Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit
 * recurring cycle.
 *
 * Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.
 *
 * Answer: 983
 * @see: http://algolist.manual.ru/maths/teornum/findperiod.php
 * @see: http://algolist.manual.ru/maths/teornum/simplper.php
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int problem26()
{
    int i, l, max = 0, d;

    for (i = 1; i < 1000; i++) {
        l = countPeriod(i);
        if (l > max) {
           max = l;
           d = i;
        }
    }

    return d;
}

int countPeriod(int n)
{
  int  l = 0, r = 1 /*n = 10*/;
  int c, k;
  
  while (l != n + 1) {
    r = (10 * r) % n;
    l++;
  }
  c = r;

  r = (10 * r) % n;
  k = 0;
  while (r != c) {
    r = (10 * r) % n;
    k++;
  }

  return k+1;
}
