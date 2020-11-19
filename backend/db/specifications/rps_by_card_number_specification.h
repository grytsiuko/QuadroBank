
#ifndef QUADROBANK_RPS_BY_CARD_NUMBER_SPECIFICATION_H
#define QUADROBANK_RPS_BY_CARD_NUMBER_SPECIFICATION_H

#include "specification.h"
#include <backend/utils/string_convert.h>
#include <backend/regular_payment/model/regular_payment.h>

#include <utility>

class RPsByCardNumberSpecification: public Specification<RegularPayment> {

private:
    const string _card_number;
    const string _where = "account_card = %0";
    const vector<string> _params;

public:
    explicit RPsByCardNumberSpecification(const string& card_number):
        _card_number(card_number), _params({to_param(_card_number)}){}

private:
    bool _filter(const RegularPayment &rp) const override {
        return _card_number == rp._account_card;
    }

    const string &_get_where() const override {
        return _where;
    }

    const vector<string> &_get_params() const override {
        return _params;
    }
};

#endif //QUADROBANK_RPS_BY_CARD_NUMBER_SPECIFICATION_H
