#ifndef ATIME_H
#define ATIME_H

struct tm *getLocal();

int getDay();

char *getTimeStr(const struct tm *t);

int getMonStartWeekday(const struct tm *t);

int getMonLastDay(const struct tm *t);

char *getCalendarStr(const struct tm *t);


#endif //ATIME_H
