/*
 * The n^(th) term of the sequence of triangle numbers is given by, t_(n) = ½n(n+1); so the first ten
 * triangle numbers are:
 *
 * 1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...
 *
 * By converting each letter in a word to a number corresponding to its alphabetical position and adding
 * these values we form a word value. For example, the word value for SKY is 19 + 11 + 25 = 55 = t_(10).
 * If the word value is a triangle number then we shall call the word a triangle word.
 *
 * Using words.txt (right click and 'Save Link/Target As...'), a 16K text file containing nearly two-thousand
 * common English words, how many are triangle words?
 *
 * Answer: 162
 */
#include <stdlib.h>
#include <stdio.h>

int is_triangle(int n)
{
    int i, t = 0;

    for (i = 1; t < n; i++) {
        t += i;
        
        if (t == n) {
            return 1;
        }
    }

    return 0;
}

int get_alpha_pos(char c)
{
    return c - 'A' + 1;
}

int problem42()
{
    FILE *fp;
    char c;
    int ws = 0, wsum = 0, cnt = 0;


    if ((fp = fopen("p42.txt", "r")) == NULL) {
        perror("p42.txt");
        return 0;
    }


    while ((c = fgetc(fp)) != EOF) {
        if (c == ',') {
            continue;
        }
        
        if (c == '"') {
            //ws = ws ? !ws : ws;

            if (!ws) {
                ws = 1;
            } else {
                if (is_triangle(wsum)) {
                    cnt++;
                }
                ws = 0;
                wsum = 0;
            }
            
            continue;
        }

        wsum += get_alpha_pos(c);
    }

    return cnt;
}
