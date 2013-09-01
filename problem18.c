/*
 * By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.
 *
    3
    7 4
    2 4 6
    8 5 9 3
 * 
 * That is, 3 + 7 + 4 + 9 = 23.
 *
 * Find the maximum total from top to bottom of the triangle below: see p18.txt
 *
 * NOTE: As there are only 16384 routes, it is possible to solve this problem by trying every route.
 * However, Problem 67, is the same challenge with a triangle containing one-hundred rows;
 * it cannot be solved by brute force, and requires a clever method! ;o)
 *
 * Answer: 1072
 */

#include <stdlib.h>
#include <stdio.h>

int p18_matrix[15][15];

void p18_load_matrix(char *file)
{
    FILE *fp;
    char c;
    int num = -1;

    if ((fp = fopen(file, "r")) == NULL) {
        perror("p11.txt");
        return;
    }

    int n = 0, m = 0;
    while ((c = fgetc(fp)) != EOF) {
        if (c == '\n') {
            n++; m = 0;
            continue;
        }

        if (c == ' ') {
            m++;
            continue;
        }

        if (num != -1) {
            num = num * 10 + atoi(&c);
            p18_matrix[n][m] = num;
            num = -1;
        } else {
            num = atoi(&c);
        }
    }
}

int problem18()
{
    int i, j;
    int tmp_sum1, tmp_sum2;

    p18_load_matrix("p18.txt");

    for (i = 1; i < 15; i++) {
        for (j = 0; p18_matrix[i][j] != 0; j++) {
            if (j == 0) {
                p18_matrix[i][j] += p18_matrix[i-1][j];
            } else {
                tmp_sum1 = p18_matrix[i][j] + p18_matrix[i-1][j-1];
                tmp_sum2 = p18_matrix[i][j] + p18_matrix[i-1][j];
                
                if (tmp_sum1 >= tmp_sum2) {
                    p18_matrix[i][j] =tmp_sum1;
                } else {
                    p18_matrix[i][j] =tmp_sum2;
                }
            }
        }
    }

    int max = 0;
    for (i = 14, j = 0; j < 15; j++) {
        if (max < p18_matrix[i][j]) {
            max = p18_matrix[i][j];
        }
    }

    return max;
}
