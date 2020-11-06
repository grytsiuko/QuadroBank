//
// Created by alouh on 06.11.2020.
//

#ifndef QUADROBANK_DATE_UTIL_H
#define QUADROBANK_DATE_UTIL_H

#include <QtCore/QString>

QString create_date_from_unix(const time_t& date){
    struct tm * timeinfo = localtime(&date);
    return QString("%1-%2-%3").arg(timeinfo->tm_mday).arg(timeinfo->tm_mon+1).arg(timeinfo->tm_year+1900);
}

#endif //QUADROBANK_DATE_UTIL_H
