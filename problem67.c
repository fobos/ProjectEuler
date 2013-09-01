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
 * Find the maximum total from top to bottom in p67.txt,
 * a 15K text file containing a triangle with one-hundred rows.
 *
 * NOTE: This is a much more difficult version of Problem 18. 
 * It is not possible to try every route to solve this problem, as there are 2^(99) altogether!
 * If you could check one trillion (10^(12)) routes every second it would take over twenty billion
 * years to check them all. There is an efficient algorithm to solve it. ;o)
 * 
 * Answer: 7273
 */

#include <stdlib.h>
#include <stdio.h>

int p67_matrix[100][100];

void p67_load_matrix(char *file)
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
            p67_matrix[n][m] = num;
            num = -1;
        } else {
            num = atoi(&c);
        }
    }
}

int problem67()
{
    int i, j;
    int tmp_sum1, tmp_sum2;

    p67_load_matrix("p67.txt");

    for (i = 1; i < 100; i++) {
        for (j = 0; p67_matrix[i][j] != 0; j++) {
            if (j == 0) {
                p67_matrix[i][j] += p67_matrix[i-1][j];
            } else {
                tmp_sum1 = p67_matrix[i][j] + p67_matrix[i-1][j-1];
                tmp_sum2 = p67_matrix[i][j] + p67_matrix[i-1][j];

                if (tmp_sum1 >= tmp_sum2) {
                    p67_matrix[i][j] =tmp_sum1;
                } else {
                    p67_matrix[i][j] =tmp_sum2;
                }
            }
        }
    }

    int max = 0;
    for (i = 99, j = 0; j < 100; j++) {
        if (max < p67_matrix[i][j]) {
            max = p67_matrix[i][j];
        }
    }

    return max;
}

