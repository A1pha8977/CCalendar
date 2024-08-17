#include "ATime.h"

#include <stdlib.h>
#include <string.h>
#include <time.h>

int isLeapYear(const struct tm *t);

int getWeekday(int startWeekday, int day);

struct tm *getLocal() {
    time_t t = time(0);
    return localtime(&t);
}

int getDay() {
    struct tm *t = getLocal();
    const int mon = t->tm_mon;
    free(t);
    return mon;
}

char *getTimeStr(const struct tm *t) {
    char *buf = calloc(30, sizeof(char));
    strftime(buf, 30, "%Y-%m-%d %a %X", t);
    char *str = calloc(strlen(buf) + 1, sizeof(char));
    strcpy(str, buf);
    free(buf);
    return str;
}

int getMonStartWeekday(const struct tm *t) {
    int weekday = t->tm_wday;
    weekday -= (t->tm_mday - 1) % 7;
    return weekday < 1 ? weekday + 7 : weekday;
}

int getMonLastDay(const struct tm *t) {
    const int mon = t->tm_mon;
    if (mon == 2) return isLeapYear(t) ? 29 : 28;
    else if (mon <= 7) return mon % 2 == 1 ? 31 : 30;
    else return mon % 2 == 0 ? 31 : 30;
}

char *getCalendarStr(const struct tm *t) {
    char buf[300] = "Mon Tue Wed Thu Fri Sat Sun \n\n";
    int day = t->tm_mday;
    for (int i = 0; i < getMonStartWeekday(t) - 1; ++i) {
        strcat(buf, "    ");
    }
    for (int i = 0; i < getMonLastDay(t); ++i) {
        char *tmp = malloc(sizeof(char) * 3);
        itoa(i + 1, tmp, 10);
        strcat(buf, tmp);
        free(tmp);
        if (i + 1 < 10) strcat(buf, "   ");
        else strcat(buf, "  ");
        if (getWeekday(getMonStartWeekday(t), i + 1) == 7) strcat(buf, "\n\n");
    }
    char *str = calloc(strlen(buf) + 1, sizeof(char));
    strcpy(str, buf);
    return str;
}

//----------------------

int isLeapYear(const struct tm *t) {
    const int year = t->tm_year;
    if (year % 100 == 0) {
        if (year % 400 == 0) return 1;
        else return 0;
    } else {
        if (year % 4 == 0) return 1;
        else return 0;
    }
}

int getWeekday(int startWeekday, int day) {
    startWeekday += (day - 1) % 7;
    return startWeekday > 7 ? startWeekday - 7 : startWeekday;
}
