/*
 * In the 20×20 grid below, four numbers along a diagonal line have been marked in red.

08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08
49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00
81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65
52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91
22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80
24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50
32 98 81 28 64 23 67 10 26 38 40 67 59 54 70 66 18 38 64 70
67 26 20 68 02 62 12 20 95 63 94 39 63 08 40 91 66 49 94 21
24 55 58 05 66 73 99 26 97 17 78 78 96 83 14 88 34 89 63 72
21 36 23 09 75 00 76 44 20 45 35 14 00 61 33 97 34 31 33 95
78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92
16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57
86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58
19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40
04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66
88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69
04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36
20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16
20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54
01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48

 * The product of these numbers is 26 × 63 × 78 × 14 = 1788696.
 *
 * What is the greatest product of four adjacent numbers in any direction 
 * (up, down, left, right, or diagonally) in the 20×20 grid?
 *
 * Answer: 70600674
 */

#include <stdlib.h>
#include <stdio.h>

int matrix[20][20];
int matrix2[20][20];
int x, y; // position of the max sequence

void fill_m2()
{
    int i, j;
    for (i=0; i<20; i++) {
        for (j=0; j<20; j++) {
            matrix2[i][j] = -1;
        }
    }
}

void print_m2()
{
    int i, j;
    for (i=0; i<20; i++) {
        for (j=0; j<20; j++) {
            printf("%d ", matrix2[i][j]);
        }
        printf("\n");
    }
    
    printf("====================\n");
}

void fprint_m2(FILE *fp)
{
    int i, j;
    for (i=0; i<20; i++) {
        for (j=0; j<20; j++) {
            fprintf(fp, "%d ", matrix2[i][j]);
        }
        fprintf(fp, "\n");
    }

    fprintf(fp, "====================\n");
}

/*
 * Load a matrix from a file
 */
void load_matrix()
{
    FILE *fp;
    char c[61], *s;

    if ((fp = fopen("p11.txt", "r")) == NULL) {
        perror("p11.txt");
        return;
    }

    int n = 0;
    while (!feof(fp)) {
        s = fgets(c, 61, fp); // read one line from the file

        int i = 0, m = 0;
        do {
            matrix[n][m] = 10*(c[i] - '0') + (c[i+1] - '0'); // convert digit chars into one int

            m++; i += 3;
        } while (c[i+2] != '\0');

        n++;
    }
}

int problem11()
{
    int max = -1;
    int i, ii, jj, j, k;
    int tmp_pow1;
    int tmp_pow2;

    load_matrix();
    fill_m2();
    

    // Scan the matrix by vertical and horizontal
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 20; j++) {
            tmp_pow1 = 1; tmp_pow2 = 1;
            for (k = 0; k < 4; k++) {
                if (j + 4 <= 20) {
                    tmp_pow1 *= matrix[i][j+k]; // vertical scan
                    //matrix2[i][j+k] = matrix[i][j+k];
                }
                if (i + 4 <= 20) {
                    tmp_pow2 *= matrix[i+k][j]; // horizontal scan
                    //matrix2[i+k][j] = matrix[i+k][j];
                }
            }

            //fprint_m2(fp2);

            if (tmp_pow1 > max) {
                max = tmp_pow1;
                x = j; y = i;
            }
            if (tmp_pow2 > max) {
                max = tmp_pow2;
                x = i; y = j;
            }
        }
    }

    // Scan the matrix by diagonal from left up to right down
    for (i = 16; i >= 0 ; i--) {
        // Down left quarter
        for (ii = i, jj = 0; ii + 4 <= 20 && jj + 4 <= 20; ii++, jj++) {
            tmp_pow1 = 1;
            for (k = 0; k < 4; k++) {
                tmp_pow1 *= matrix[ii+k][jj+k];
                //matrix2[ii+k][jj+k] = matrix[ii+k][jj+k];;
            }

            //fprint_m2(fp2);

            if (tmp_pow1 > max) {
                x = jj; y = ii;
                max = tmp_pow1;
            }
        }

        // Up right quarter
        for (ii = 0, jj = i;  ii + 4 <= 20 && jj > 0 && jj + 4 <= 20; ii++, jj++) {
            tmp_pow1 = 1;
            for (k = 0; k < 4; k++) {
                tmp_pow1 *= matrix[ii+k][jj+k];
                //matrix2[ii+k][jj+k] = matrix[ii+k][jj+k];;
            }

            //fprint_m2(fp2);

            if (tmp_pow1 > max) {
                x = jj; y = ii;
                max = tmp_pow1;
            }
        }

        //fprint_m2(fp2);
    }

    // Scan the matrix by diagonal from right up to left down
    for (i = 16; i >= 0 ; i--) {
        // Down right quarter
        for (ii = i, jj = 19; ii + 4 <= 20 && jj - 3 >= 0; ii++, jj--) {
            tmp_pow1 = 1;
            for (k = 0; k < 4; k++) {
                tmp_pow1 *= matrix[ii+k][jj-k];
                //matrix2[ii+k][jj-k] = matrix[ii+k][jj-k];
            }

            //fprint_m2(fp2);
            
            if (tmp_pow1 > max) {
                x = jj; y = ii;
                max = tmp_pow1;
            }
        }
    }

    // Up right quarter
    for (j = 18; j >= 0; j--) {
        for (ii = 0, jj = j; ii + 4 <= 20 && jj - 3 >= 0; ii++, jj--) {
            tmp_pow1 = 1;
            for (k = 0; k < 4; k++) {
                tmp_pow1 *= matrix[ii+k][jj-k];
                //matrix2[ii+k][jj-k] = matrix[ii+k][jj-k];
            }

            //fprint_m2(fp2);

            if (tmp_pow1 > max) {
                x = jj; y = ii;
                max = tmp_pow1;
            }
        }
    }

    //printf("x: %d; y: %d \n", x, y);
    
    return max;
}
