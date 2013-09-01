#include <stdlib.h>
#include <stdio.h>

/*
 * You are given the following information, but you may prefer to do some research for yourself.
 * 
 * * 1 Jan 1900 was a Monday.
 * * Thirty days has September,
      April, June and November.
      All the rest have thirty-one,
      Saving February alone,
      Which has twenty-eight, rain or shine.
      And on leap years, twenty-nine.
 * * A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
 *
 * How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
 *
 * Answer: 171
 */

#define FEB 2
#define MON 0
#define SUN 6
#define Y_ID = 2
#define M_ID = 1
#define D_ID = 0

/*
 * DATE - массив из 3-х элементов
 *  0 - день
 *  1 - месяц
 *  2 - год
 */
void addDays(int DATE[3], int nd)
{
    static int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    while (nd--) {
        DATE[0]++;
        if (DATE[0] > daysInMonth[DATE[1]]) {
            /* Високосный год - любой год, делящийся нацело на 4,
             * однако первый год века (ХХ00) является високосным в том и только том случае,
             * если делится на 400.
             */
            if (DATE[2] % 4 == 0 && DATE[1] == FEB && DATE[0] == 29) {
                if (DATE[2] % 100) { // не первый год века
                    continue;
                } else { // первый год века
                    if (DATE[2] % 400 == 0) { // дополнительная проверка на високосность
                        continue;
                    }
                }
            } // Иначе

            DATE[0] = 1;    // К 1 числу месяца
            DATE[1]++;      // Переходим к следующему месяцу

            if (DATE[1] == 13) {// Если перешагнули на новый год
                DATE[1] = 1; // Месяц январь
                DATE[2]++;   // Переходим к следующему году
            }
        }
    }
}

int porblem19()
{
    int DATE[3] = {1, 1, 1900}, wd = MON;
    //char *WD[7] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
    int cnt = 0; // days count;

    while(!(DATE[2] == 2000 && DATE[1] == 12 && DATE[0] == 31)) {
        addDays(DATE, 1);
        // Вычислить день недели
        wd++;
        if (wd == 7) {
            wd = 0;
        }

        if (DATE[2] >= 1901 && DATE[0] == 1 && wd == SUN) {
            cnt++;
        }
    }

    return cnt;
}
