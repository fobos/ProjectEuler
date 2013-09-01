#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
 * Work out the first ten digits of the sum of the following one-hundred 50-digit numbers (see p13.txt).
 *
 * Answer: 5537376230
 */
const char *problem13()
{
    FILE *fp;
    int matrix[100][50];
    char c;
    
    if ((fp = fopen("p13.txt", "r")) == NULL) {
        perror("p13.txt");
        return 0;
    }

    int n=0, m=0;
    while ((c = fgetc(fp)) != EOF) {
        if (c == '\n') {
            n++;
            m = 0;
            continue;
        }

        matrix[n][m] = c - '0';
        m++;
    }


    /*
     */
    int i, j, k = 0, mem = 0;
    int dig[100] = {0};
    for (j = 49; j >= 0; j--) {
        int sum = 0;
        for (i = 0; i < 100; i++) {
            sum += matrix[i][j];
        }
        sum += mem;
        dig[k++] = sum % 10;
        mem = sum / 10;
    }
    //if (mem) {
        while (mem) {
            dig[k++] = mem % 10;
            mem /= 10;
        }
    //}

    int ii = 99;
    while (!dig[ii] && ii) {
        ii--;
    }

    int jj;
    char cc[11];
    for (jj = 0; jj < 10 && ii; jj++, ii--) {
        cc[jj] = dig[ii] + '0';
        //printf("%c", dig[ii] + '0');
    }
    cc[10] = '\0';
    
    return cc;
}
