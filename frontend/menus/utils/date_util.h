//
// Created by alouh on 06.11.2020.
//

#ifndef QUADROBANK_DATE_UTIL_H
#define QUADROBANK_DATE_UTIL_H

#include <QtCore/QString>
#include "../backend/utils/time_intervals.h"


inline QString create_date_from_unix(const time_t& date){
    struct tm * timeinfo = localtime(&date);
    return QString("%1-%2-%3").arg(timeinfo->tm_mday).arg(timeinfo->tm_mon+1).arg(timeinfo->tm_year+1900);
}

struct QuantityPeriod{
    int quantity;
    int period;
};

inline QuantityPeriod* get_quantity_and_period(int period_sec) {
    int currentSeconds = period_sec;
    auto *res = new QuantityPeriod{0, 0};
    int periods[5] = {TimeIntervals::SECOND, TimeIntervals::MINUTE,
                      TimeIntervals::HOUR, TimeIntervals::DAY,
                      TimeIntervals::MONTH};
    int i;
    for (i = 0; i < 5; ++i) {
        if (currentSeconds / periods[i] < 1) {
            break;
        }
    }
    res->period = periods[i-1];
    res->quantity = period_sec / (res->period);
    return res;
}

#endif //QUADROBANK_DATE_UTIL_H
