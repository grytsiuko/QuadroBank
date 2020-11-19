//
// Created by alouh on 18.11.2020.
//
#include "date_util.h"
const QuantityPeriod* get_quantity_and_period(int period_sec) {
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

const QString get_name_of_interval(int period){
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