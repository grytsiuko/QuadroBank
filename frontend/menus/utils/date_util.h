//
// Created by alouh on 06.11.2020.
//

#ifndef QUADROBANK_DATE_UTIL_H
#define QUADROBANK_DATE_UTIL_H

#include <QtCore/QString>
#include "backend/utils/time_intervals.h"


inline QString create_date_from_unix(const time_t& date){
    struct tm * timeinfo = localtime(&date);
    return QString("%1-%2-%3").arg(timeinfo->tm_mday).arg(timeinfo->tm_mon+1).arg(timeinfo->tm_year+1900);
}

struct QuantityPeriod{
    int quantity;
    int period;
};

inline QuantityPeriod* get_quantity_and_period(int period_sec) {
    QuantityPeriod *res = new QuantityPeriod{0, 0};
    int periods[5] = {TimeIntervals::SECOND, TimeIntervals::MINUTE,
                      TimeIntervals::HOUR, TimeIntervals::DAY,
                      TimeIntervals::MONTH};
    int i;
    for (i = 0; i < 5; ++i) {
        if (period_sec / periods[i] < 1) {
            break;
        }
        if (i>0 and period_sec % periods[i] != 0){
            break;
        }
    }
    res->period = periods[i-1];
    res->quantity = period_sec / (res->period);
    return res;
}

inline const QString get_name_of_interval(int period){
    QString res;
    if (period == 1){
        res = QString("Seconds");
    }
    else if (period == 60){
        res = QString("Minutes");
    }
    else if (period == 3600){
        res = QString("Hours");
    }
    else if (period == 86400){
        res = QString("Days");
    }
    else if (period == 86400 * 30){
        res = QString("Months");
    }
    return res;
}

#endif //QUADROBANK_DATE_UTIL_H
