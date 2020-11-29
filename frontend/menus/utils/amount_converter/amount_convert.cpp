//
// Created by alouh on 29.11.2020.
//
#include "amount_convert.h"
int convertAmount(const QString& amount){
    QStringList amount_list = amount.split(".");
    if (amount_list.length() < 2){
        return amount.toInt();
    }
    else{
        if (amount_list[1].length() < 2 && amount_list[1] != ""){
            return amount_list[0].toInt() * 100 + amount_list[1].toInt() * 10;
        }
        else {
            return amount_list[0].toInt() * 100 + amount_list[1].toInt();
        }
    }
}