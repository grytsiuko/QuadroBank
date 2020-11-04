#ifndef QUADROBANK_TIME_INTERVALS_H
#define QUADROBANK_TIME_INTERVALS_H

struct TimeIntervals{
    static const int SECOND = 1;
    static const int MINUTE = 60 * SECOND;
    static const int HOUR = 60 * MINUTE;
    static const int DAY = 24 * HOUR;
    static const int WEEK = 7 * DAY;
    static const int MONTH = 30 * DAY;
    static const int YEAR = 365 * DAY;
};

#endif //QUADROBANK_TIME_INTERVALS_H
