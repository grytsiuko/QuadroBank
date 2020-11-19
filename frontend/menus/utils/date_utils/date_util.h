//
// Created by alouh on 06.11.2020.
//

#ifndef QUADROBANK_DATE_UTIL_H
#define QUADROBANK_DATE_UTIL_H

#include <QtCore/QString>
#include "backend/utils/time_intervals.h"


struct QuantityPeriod{
    int quantity;
    int period;
};

const QuantityPeriod* get_quantity_and_period(int period_sec);

const QString get_name_of_interval(int period);

#endif //QUADROBANK_DATE_UTIL_H
