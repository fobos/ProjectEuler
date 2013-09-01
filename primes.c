#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <math.h>

int is_prime64(int64_t n) {
    if (n <= 1)
        return 0;

    int64_t j;
    for (j = 2; j * j <= n; j++)
         if (n % j == 0) return 0;

    return 1;
}

int is_prime(int n) {
    if (n <= 1)
        return 0;

    int j;
    for (j = 2; j * j <= n; j++)
         if (n % j == 0) return 0;

    return 1;
}

int *athkin_sieve(int limit)
{
    //int limit = 1000;
    //int is_prime[limit + 1];
    int sqr_lim;
    int x2, y2;
    int i, j;
    int n;

    // Выделить память под хранение всех чисел
    int *is_prime = (int *)calloc(limit + 1, sizeof(int));

    // Инициализация решета
    sqr_lim = (int)sqrt((long double)limit);
    for (i = 0; i <= limit; i++) is_prime[i] = 0;
    is_prime[2] = 1;
    is_prime[3] = 1;

    // Предположительно простые - это целые с нечетным числом
    // представлений в данных квадратных формах.
    // x2 и y2 - это квадраты i и j (оптимизация).
    x2 = 0;
    for (i = 1; i <= sqr_lim; i++) {
        x2 += 2 * i - 1;
        y2 = 0;
        for (j = 1; j <= sqr_lim; j++) {
            y2 += 2 * j - 1;

            n = 4 * x2 + y2;
            if ((n <= limit) && (n % 12 == 1 || n % 12 == 5))
                is_prime[n] = !is_prime[n];

            // n = 3 * x2 + y2;
            n -= x2; // Оптимизация
            if ((n <= limit) && (n % 12 == 7))
                is_prime[n] = !is_prime[n];

            // n = 3 * x2 - y2;
            n -= 2 * y2; // Оптимизация
            if ((i > j) && (n <= limit) && (n % 12 == 11))
                is_prime[n] = !is_prime[n];
        }
    }

    // Отсеиваем квадраты простых чисел в интервале [5, sqrt(limit)].
    // (основной этап не может их отсеять)
    for (i = 5; i <= sqr_lim; i++) {
        if (is_prime[i]) {
            n = i * i;
            for (j = n; j <= limit; j += n) {
                is_prime[j] = 0;
            }
        }
    }
 
    return is_prime;
}
