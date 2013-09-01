#include <stdlib.h>
#include <stdio.h>
#include <math.h>


/*
 * The sequence of triangle numbers is generated by adding the natural numbers.
 * So the 7^(th) triangle number would be 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28.
 * The first ten terms would be: 1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...
 *
 * Let us list the factors of the first seven triangle numbers:
     1: 1
     3: 1,3
     6: 1,2,3,6
    10: 1,2,5,10
    15: 1,3,5,15
    21: 1,3,7,21
    28: 1,2,4,7,14,28
 * We can see that 28 is the first triangle number to have over five divisors.
 *
 * What is the value of the first triangle number to have over five hundred divisors?
 *
 * 
 * Answer: 76576500 has 576 dividers
 * 
 * To solve the problem I used this materials
 * @link http://python.su/forum/viewtopic.php?id=6744
 * @link http://eek.diary.ru/p85182052.htm
 */

int get_next_prime(int *primes, int n)
{
    int i = n+1;
    for (; i <= 1000000 ;i++) {
        if (primes[i]) {
            return i;
        }
    }

    return -1;
}

/*
 * See description
 */
int calc_divisors(int n, int *primes)
{
    if (n == 1) return 1;
    
    int cnt = 1, i, n1 = (int)pow(n, 0.5);
    int k = get_next_prime(primes, 1);
    while (n!=1) {
        i=0;
        while (n%k == 0) {
            i++;
            n/=k;
        }
        if (i){
            cnt *= (i+1);
            n1=(int)pow(n, 0.5);
        }
        if (k > n1 && n != 1) {
            cnt *= 2; // cnt *= (1+1);
            break;
        }

        k = get_next_prime(primes, k);
    }
    
    return cnt;
}

int problem12()
{
    int i, dcnt;
    int triangle = 0;
    int *p;

    p = athkin_sieve(1000000);
    
    for (i = 1; ; i++) {
        triangle += i;

        dcnt = calc_divisors(triangle, p);
        //printf("%d: %d\n", triangle, dcnt);

        if (dcnt > 500) {
            return triangle;
        }
    }
}