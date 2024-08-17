#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/ATime.h"
int main(void) {
    printf("%s\n\n", getTimeStr(getLocal()));
    printf("%s\n", getCalendarStr(getLocal()));
    return 0;
}
